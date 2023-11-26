/***************************************************************************//**
 * @file
 * @brief Core application logic.
 *******************************************************************************
 * # License
 * <b>Copyright 2020 Silicon Laboratories Inc. www.silabs.com</b>
 *******************************************************************************
 *
 * SPDX-License-Identifier: Zlib
 *
 * The licensor of this software is Silicon Laboratories Inc.
 *
 * This software is provided 'as-is', without any express or implied
 * warranty. In no event will the authors be held liable for any damages
 * arising from the use of this software.
 *
 * Permission is granted to anyone to use this software for any purpose,
 * including commercial applications, and to alter it and redistribute it
 * freely, subject to the following restrictions:
 *
 * 1. The origin of this software must not be misrepresented; you must not
 *    claim that you wrote the original software. If you use this software
 *    in a product, an acknowledgment in the product documentation would be
 *    appreciated but is not required.
 * 2. Altered source versions must be plainly marked as such, and must not be
 *    misrepresented as being the original software.
 * 3. This notice may not be removed or altered from any source distribution.
 *
 ******************************************************************************/

#include "app.h"
#define TURN_ON								1
#define TURN_OFF							0

#if SL_BT_CONFIG_MAX_CONNECTIONS < 1
#error At least 1 connection has to be enabled!
#endif


status_device status_of_device = DISCONNECT; // đầu tiên ở trạng thái chờ dữ liệu gửi.

// Array for holding properties of multiple (parallel) connections
static conn_properties_t conn_properties[SL_BT_CONFIG_MAX_CONNECTIONS];
// Counter of active connections
static uint8_t active_connections_num;
// State of the connection under establishment
static conn_state_t conn_state;
// my service UUID defined by Bluetooth SIG
static const uint8_t my_service[2] = { 0x00, 0x00 };  // chỉnh ở đây dịch vụ cần gửi ở đây.
// button characteristic UUID defined by Bluetooth SIG
static const uint8_t button_char[2] = { 0x11, 0x11 };	  // chỉnh sửa đặc trưng nút bấm cần gửi ở đây.
// sensor characteristic UUID defined by Bluetooth SIG
static const uint8_t sensor_char[2] = { 0x22, 0x22 };	  // chỉnh sửa đặc trưng cảm biến cần gửi ở đây.
// device control characteristic UUID defined by Bluetooth SIG
static const uint8_t device_control_char[2] = { 0x33, 0x33 };	  // chỉnh sửa đặc trưng cảm biến cần gửi ở đây.

static void init_properties(void);
static uint8_t find_service_in_advertisement(uint8_t *data, uint8_t len);
static uint8_t find_index_by_address_handle(uint16_t adrress);
static uint8_t find_index_by_connection_handle(uint8_t connection);
static void add_connection(uint8_t connection, uint16_t address);
// Remove a connection from the connection_properties array
static void remove_connection(uint8_t connection);
static void print_bluetooth_address(void);
// Print RSSI and temperature values
static void print_values(void);

// The advertising set handle allocated from Bluetooth stack.
static uint8_t advertising_set_handle = 0xff;
sl_status_t sc;

// flag print LCD.
static bool flag_print_LCD = false;
static bool flag_of_button = false;

/**************************************************************************//**
 * Application Init.
 *****************************************************************************/
SL_WEAK void app_init(void)
{
	cli_custom_cmd_init();
	init_properties();
	st7735_init();
	displays_init();
	threshold_alert_init();
	sl_bt_system_set_lazy_soft_timer(32768 * 10, 0, 0, 0);
	app_log_info("soc_thermometer_client initialised\n");
}

/**************************************************************************//**
 * Application Process Action.
 *****************************************************************************/
SL_WEAK void app_process_action(void)
{
	// In thông tin ra OLED.
	if (flag_print_LCD) {
		flag_print_LCD = false;
		// device 1.
		display_screen(56, 30, 0);
		// device 2.
		display_screen(56, 90, 1);
	}
	if (flag_of_button == true) {
		flag_of_button = false;
		// Xử lý sự kiện nhấn nút tại đây.
		for (int i = 0; i < active_connections_num; i++) {
			if (status_of_device == CONNECT) {
				// Tắt thiết bị.
				conn_properties[i].state_of_device = TURN_ON;
				// Tắt indications.
				conn_properties[i].enable_indicate = TURN_ON;
			} else {
				// Tắt thiết bị.
				conn_properties[i].state_of_device = TURN_OFF;
				// Tắt indications.
				conn_properties[i].enable_indicate = TURN_OFF;
			}

			// Gửi tín hiệu sang từng cho device trạng thái của gateway.
			sc = sl_bt_gatt_write_characteristic_value(conn_properties[i].connection_char,
					conn_properties[i].button_characteristic_handle, sizeof(status_of_device), &status_of_device);
			app_assert_status(sc);
			sl_sleeptimer_delay_millisecond(10);
		}
	}
}

/**************************************************************************//**
 * Bluetooth stack event handler.
 * This overrides the dummy weak implementation.
 *
 * @param[in] evt Event coming from the Bluetooth stack.
 *****************************************************************************/
void sl_bt_on_event(sl_bt_msg_t *evt)
{
	uint8_t *char_value;
	uint16_t addr_value;
	uint8_t table_index;

	switch (SL_BT_MSG_ID(evt->header)) {
	case sl_bt_evt_system_soft_timer_id:
		if (evt->data.evt_system_soft_timer.handle == 0) {
			flag_print_LCD = true;
		}
		break;
		// -------------------------------
		// This event indicates the device has started and the radio is ready.
		// Do not call any stack command before receiving this boot event!
	case sl_bt_evt_system_boot_id:
		// Set passive scanning on 1Mb PHY
		sc = sl_bt_scanner_set_mode(sl_bt_gap_1m_phy, SCAN_PASSIVE);
		app_assert_status(sc);
		// Set scan interval and scan window
		sc = sl_bt_scanner_set_timing(sl_bt_gap_1m_phy, SCAN_INTERVAL, SCAN_WINDOW);
		app_assert_status(sc);
		// Set the default connection parameters for subsequent connections
		sc = sl_bt_connection_set_default_parameters(CONN_INTERVAL_MIN,
				CONN_INTERVAL_MAX,
				CONN_RESPONDER_LATENCY,
				CONN_TIMEOUT,
				CONN_MIN_CE_LENGTH,
				CONN_MAX_CE_LENGTH);
		app_assert_status(sc);
		// Start scanning - looking for thermometer devices
		sc = sl_bt_scanner_start(sl_bt_gap_1m_phy, sl_bt_scanner_discover_generic);
		app_assert_status_f(sc,
				"Failed to start discovery #1\n");
		conn_state = scanning;
		break;

		// -------------------------------
		// This event is generated when an advertisement packet or a scan response
		// is received from a responder
	case sl_bt_evt_scanner_scan_report_id:
		// Parse advertisement packets
		app_log("find\n");
		if (evt->data.evt_scanner_scan_report.packet_type == 0) {
			// If a thermometer advertisement is found...
			if (find_service_in_advertisement(&(evt->data.evt_scanner_scan_report.data.data[0]),
					evt->data.evt_scanner_scan_report.data.len) != 0) {
				// then stop scanning for a while
				sc = sl_bt_scanner_stop();
				app_assert_status(sc);
				// and connect to that device
				if (active_connections_num < SL_BT_CONFIG_MAX_CONNECTIONS) {
					sc = sl_bt_connection_open(evt->data.evt_scanner_scan_report.address,
							evt->data.evt_scanner_scan_report.address_type,
							sl_bt_gap_1m_phy,
							NULL);
					app_assert_status(sc);
					conn_state = opening;
				}
			}
		}
		break;

		// -------------------------------
		// This event is generated when a new connection is established
	case sl_bt_evt_connection_opened_id:
		// Get last two bytes of sender address
		addr_value = (uint16_t)(evt->data.evt_connection_opened.address.addr[1] << 8) + evt->data.evt_connection_opened.address.addr[0];
		// Add connection to the connection_properties array *** thấy được một kết nối sau đó lưu nó vào mảng kết nối, trong mảng này mới chỉ có 2 sự kiện được lưu.
		add_connection(evt->data.evt_connection_opened.connection, addr_value);
		// Discover Health Thermometer service on the responder device
		// chinh code o day. *** => Ở đây nó kiểm tra ID mà dịch vụ đang quảng cáo, nếu có dịch vụ nó cần thiết thì nó sẽ kết nối.
		sc = sl_bt_gatt_discover_primary_services_by_uuid(evt->data.evt_connection_opened.connection,
				sizeof(my_service),
				(const uint8_t*)my_service);
		app_assert_status(sc);

		conn_state = discover_services;
		break;

		// -------------------------------
		// This event is generated when a new service is discovered. Hàm này khi có một dịch vụ gửi đến nó sẽ kiểm tra trong mảng các thiết bị kết nối xem có phải thiết bị dã kết nối hay không? nếu có nó lưu lại dịch vụ.
	case sl_bt_evt_gatt_service_id:
		table_index = find_index_by_connection_handle(evt->data.evt_gatt_service.connection);
		if (table_index != TABLE_INDEX_INVALID) {
			// Save service handle for future reference
			conn_properties[table_index].my_service_handle = evt->data.evt_gatt_service.service;
		}
		break;
	case sl_bt_evt_gatt_characteristic_id:
		table_index = find_index_by_connection_handle(evt->data.evt_gatt_characteristic.connection);
		if (table_index != TABLE_INDEX_INVALID && conn_state == discover_sensor_characteristics) {
			// Save characteristic handle for future reference
			conn_properties[table_index].sensor_characteristic_handle = evt->data.evt_gatt_characteristic.characteristic;
			app_log("sensor_characteristic_handle = %d\n", conn_properties[table_index].sensor_characteristic_handle);
			break;
		}
		if (table_index != TABLE_INDEX_INVALID && conn_state == discover_button_characteristics) {
			// Save characteristic handle for future reference
			conn_properties[table_index].button_characteristic_handle = evt->data.evt_gatt_characteristic.characteristic;
			app_log("button_characteristic_handle = %d\n", conn_properties[table_index].button_characteristic_handle);
			conn_state = discover_device_control_characteristics;
			break;
		}
		// Xử lý khi có phản hồi về dịch vụ decice control.
		if (table_index != TABLE_INDEX_INVALID && conn_state == discover_device_control_characteristics) {
			conn_properties[table_index].device_control_characteristic_handle = evt->data.evt_gatt_characteristic.characteristic;
			app_log("device_control_characteristic_handle = %d\n", conn_properties[table_index].device_control_characteristic_handle);
			conn_state = checking_max_device;
			break;
		}
		break;

		// -------------------------------
		// This event is generated (được tạo ra) for various (nhiều) procedure (thủ tục) completions, e.g. when a
		// write procedure is completed, or service discovery is completed
	case sl_bt_evt_gatt_procedure_completed_id:
		table_index = find_index_by_connection_handle(evt->data.evt_gatt_procedure_completed.connection);
		if (table_index == TABLE_INDEX_INVALID) {
			break;
		}
		// If service discovery (khám phá) finished
		if (conn_state == discover_services && conn_properties[table_index].my_service_handle != SERVICE_HANDLE_INVALID) {
			// Discover (phát hiện) button characteristic on the responder device
			conn_properties[table_index].connection_char = evt->data.evt_gatt_procedure_completed.connection;
			sc = sl_bt_gatt_discover_characteristics_by_uuid(conn_properties[table_index].connection_char,
					conn_properties[table_index].my_service_handle,
					sizeof(sensor_char),
					(const uint8_t*)sensor_char);
			app_assert_status(sc);
			conn_state = discover_sensor_characteristics;
			break;
		}
		// Enable indications.
		if (conn_state == discover_sensor_characteristics && conn_properties[table_index].sensor_characteristic_handle != CHARACTERISTIC_HANDLE_INVALID) {
			// enable indications
			sc = sl_bt_gatt_set_characteristic_notification(conn_properties[table_index].connection_char,
					conn_properties[table_index].sensor_characteristic_handle,
					sl_bt_gatt_indication);
			app_assert_status(sc);

			// enable state indication.
			conn_properties[table_index].enable_indicate = TURN_ON;

			conn_state = discover_button_characteristics;
			break;
		}

		if (conn_state == discover_button_characteristics && conn_properties[table_index].my_service_handle != SERVICE_HANDLE_INVALID) {
			// Discover (phát hiện) button characteristic on the responder device
			sc = sl_bt_gatt_discover_characteristics_by_uuid(conn_properties[table_index].connection_char,
					conn_properties[table_index].my_service_handle,
					sizeof(button_char),
					(const uint8_t*)button_char);
			app_assert_status(sc);
			break;
		}

		if (conn_state == discover_device_control_characteristics && conn_properties[table_index].my_service_handle != SERVICE_HANDLE_INVALID) {
			sc = sl_bt_gatt_discover_characteristics_by_uuid(conn_properties[table_index].connection_char,
					conn_properties[table_index].my_service_handle,
					sizeof(device_control_char),
					(const uint8_t*)device_control_char);
			app_assert_status(sc);
			break;
		}

		if (conn_state == checking_max_device) {
			sl_bt_scanner_stop();
			if (active_connections_num == SL_BT_CONFIG_MAX_CONNECTIONS) {
				status_of_device = CONNECT;
				sl_bt_scanner_stop();
				app_log("found full device\n");
				conn_state = running;
			} else {
				// start scanning again to find new devices.
				sl_bt_scanner_stop();
				sc = sl_bt_scanner_start(sl_bt_gap_1m_phy, sl_bt_scanner_discover_generic);
				app_assert_status_f(sc,
						"Failed to start discovery #3\n");
				conn_state = scanning;
			}
			break;
		}
		break;

		// -------------------------------
		// This event indicates that a connection was closed.
	case sl_bt_evt_connection_closed_id:
		// remove connection from active connections
		app_log("close\n");
		if (active_connections_num == 0) {
			status_of_device = DISCONNECT;
		}
		// remove connection from active connections
		remove_connection(evt->data.evt_connection_closed.connection);
		//remove_connection(evt->data.evt_connection_closed.connection);
		if (active_connections_num == 0) {
			status_of_device = DISCONNECT;
		}
		if (conn_state != scanning) {
			// start scanning again to find new devices
			sc = sl_bt_scanner_start(sl_bt_gap_1m_phy, sl_bt_scanner_discover_generic);
			app_assert_status_f(sc,
					"Failed to start discovery #3\n");
			conn_state = scanning;
		}
		break;

		///////////////////////////////////////////////////////////////////////////
		// Add additional event handlers here as your application requires!      //
		///////////////////////////////////////////////////////////////////////////
	case sl_bt_evt_gatt_characteristic_value_id:
		char_value = &(evt->data.evt_gatt_characteristic_value.value.data[0]);
		table_index = find_index_by_connection_handle(evt->data.evt_gatt_characteristic_value.connection);
		if (table_index != TABLE_INDEX_INVALID) {
			//app_log("Da nhan thanh cong\n");
			conn_properties[table_index].integer_humi_value = *(char_value);
			conn_properties[table_index].decimal_humi_value = *(char_value + 1);
			conn_properties[table_index].integer_temp_value = *(char_value + 2) ;
			conn_properties[table_index].decimal_temp_value = *(char_value + 3);
			conn_properties[table_index].light_value_hight = *(char_value + 4);
			conn_properties[table_index].light_value_low = *(char_value + 5);
		}

		sc = sl_bt_gatt_send_characteristic_confirmation(evt->data.evt_gatt_characteristic_value.connection);
		uint16_t light = (uint16_t) (conn_properties[table_index].light_value_hight << 8 | conn_properties[table_index].light_value_low);
		app_log("device %d \nhumi = %d.%d, temp = %d.%d, light = %.1f\n", table_index,*(char_value), *(char_value + 1), *(char_value + 2),
				*(char_value + 3), (float) (light * 1.0 / 1.2));
		// check threshold alert
		if (check_threshold_alert(conn_properties[table_index].integer_humi_value,
				conn_properties[table_index].integer_temp_value,
				0, // Không sử dụng ánh sáng.
				conn_properties[table_index].threshold_of_sensor))

		{
			turn_on_threshold_alert(table_index);
			conn_properties[table_index].threshold_aler =  TURN_ON;
		} else {
			turn_off_threshold_alert(table_index);
			conn_properties[table_index].threshold_aler =  TURN_OFF;
		}
		break;
	default:
		break;
		// -------------------------------
		// Default event handler.
	}
}

/**************************************************************************//**
 * Simple Button
 * Button state changed callback
 * @param[in] handle Button event handle
 *****************************************************************************/
void sl_button_on_change(const sl_button_t *handle)
{
	sl_status_t sc;
	uint8_t data_send;
	// Button pressed.
	if (sl_button_get_state(handle) == SL_SIMPLE_BUTTON_PRESSED) {
		if (&sl_button_btn0 == handle) {
			flag_of_button = true;
			status_of_device = (status_of_device == PAUSE) ? CONNECT : PAUSE;
			if (status_of_device == CONNECT) {
				draw_string(64, 1, "     CONNECT", GREEN, BLACK);
			} else if (status_of_device == PAUSE){
				draw_string(64, 1, "       PAUSE", RED, BLACK);
			}
		}
	}
}

// Init connection properties
static void init_properties(void)
{
	uint8_t i;
	active_connections_num = 0;

	for (i = 0; i < SL_BT_CONFIG_MAX_CONNECTIONS; i++) {
		conn_properties[i].connection_handle = CONNECTION_HANDLE_INVALID;
		conn_properties[i].connection_char = CONNECTION_HANDLE_INVALID;
		conn_properties[i].my_service_handle = SERVICE_HANDLE_INVALID;
		conn_properties[i].button_characteristic_handle = CHARACTERISTIC_HANDLE_INVALID;
		conn_properties[i].sensor_characteristic_handle = CHARACTERISTIC_HANDLE_INVALID;

		// Những cái này có khi không cần --> test lại sau.
		conn_properties[i].integer_humi_value = 0;
		conn_properties[i].decimal_humi_value = 0;
		conn_properties[i].integer_temp_value = 0;
		conn_properties[i].decimal_temp_value = 0;
		conn_properties[i].light_value_hight = 0;
		conn_properties[i].light_value_low = 0;

		// Xét ngưỡng ban đầu là mặc định.
		conn_properties[i].threshold_of_sensor[0][1] = HUMIDITY_MAX;
		conn_properties[i].threshold_of_sensor[1][1] = TEMPERATURE_MAX;
		conn_properties[i].threshold_of_sensor[2][1] = LIGHT_MAX;

		conn_properties[i].threshold_of_sensor[0][0] = HUMIDITY_MIN;
		conn_properties[i].threshold_of_sensor[1][0] = TEMPERATURE_MIN;
		conn_properties[i].threshold_of_sensor[2][0] = LIGHT_MIN;


		conn_properties[i].state_of_device = TURN_OFF;  // ban đầu trạng thái là off.
		conn_properties[i].enable_indicate = TURN_OFF;  // khi chưa enable indicate.
	}
}

// Parse advertisements looking for advertised Health Thermometer service
static uint8_t find_service_in_advertisement(uint8_t *data, uint8_t len)
{
	uint8_t ad_field_length;
	uint8_t ad_field_type;
	uint8_t i = 0;
	// Parse advertisement packet
	while (i < len) {
		ad_field_length = data[i];
		ad_field_type = data[i + 1];
		// Partial ($02) or complete ($03) list of 16-bit UUIDs
		if (ad_field_type == 0x02 || ad_field_type == 0x03) {
			// compare UUID to Health Thermometer service UUID
			if (memcmp(&data[i + 2], my_service, 2) == 0) {
				return 1;
			}
		}
		// advance to the next AD struct
		i = i + ad_field_length + 1;
	}
	return 0;
}

// Add a new connection to the connection_properties array
static void add_connection(uint8_t connection, uint16_t address)
{
	conn_properties[active_connections_num].connection_handle = connection;
	conn_properties[active_connections_num].server_address    = address;
	conn_properties[active_connections_num].state_of_device = TURN_ON;  // mở thiết bị.
	active_connections_num++;
}

// Find the index of a given connection in the connection_properties array
static uint8_t find_index_by_connection_handle(uint8_t connection)
{
	for (uint8_t i = 0; i < active_connections_num; i++) {
		if (conn_properties[i].connection_handle == connection) {
			return i;
		}
	}
	return TABLE_INDEX_INVALID;
}

// Find the index of a given connection in the connection_properties array
static uint8_t find_index_by_address_handle(uint16_t adrress)
{
	for (uint8_t i = 0; i < active_connections_num; i++) {
		if (conn_properties[i].server_address == adrress) {
			return i;
		}
	}
	return TABLE_INDEX_INVALID;
}

// Remove a connection from the connection_properties array
static void remove_connection(uint8_t connection)
{
	uint8_t i;
	uint8_t table_index = find_index_by_connection_handle(connection);

	if (active_connections_num > 0) {
		active_connections_num--;
	}
	// Shift entries after the removed connection toward 0 index
	for (i = table_index; i < active_connections_num; i++) {
		conn_properties[i] = conn_properties[i + 1];
	}
	// Clear the slots we've just removed so no junk values appear
	for (i = active_connections_num; i < SL_BT_CONFIG_MAX_CONNECTIONS; i++) {
		conn_properties[i].connection_handle = CONNECTION_HANDLE_INVALID;
		conn_properties[i].connection_char = CONNECTION_HANDLE_INVALID;
		conn_properties[i].my_service_handle = SERVICE_HANDLE_INVALID;
		conn_properties[i].button_characteristic_handle = CHARACTERISTIC_HANDLE_INVALID;
		conn_properties[i].sensor_characteristic_handle = CHARACTERISTIC_HANDLE_INVALID;
		conn_properties[i].integer_humi_value = 0;
		conn_properties[i].decimal_humi_value = 0;
		conn_properties[i].integer_temp_value = 0;
		conn_properties[i].decimal_temp_value = 0;
		conn_properties[i].light_value_hight = 0;
		conn_properties[i].light_value_low = 0;

		// Xét ngưỡng ban đầu là mặc định.
		conn_properties[i].threshold_of_sensor[0][1] = HUMIDITY_MAX;
		conn_properties[i].threshold_of_sensor[1][1] = TEMPERATURE_MAX;
		conn_properties[i].threshold_of_sensor[2][1] = LIGHT_MAX;

		conn_properties[i].threshold_of_sensor[0][0] = HUMIDITY_MIN;
		conn_properties[i].threshold_of_sensor[1][0] = TEMPERATURE_MIN;
		conn_properties[i].threshold_of_sensor[2][0] = LIGHT_MIN;

		// Xét ngưỡng ảo.
		conn_properties[i].virtual_threshold[0] = 0; // ngưỡng ảo để test vượt ngưỡng.
		conn_properties[i].virtual_threshold[1] = 0;
		conn_properties[i].virtual_threshold[2] = 0;

		// Trạng thái hoạt động của thiết bị kết nối.
		conn_properties[i].state_of_device = TURN_OFF;
		conn_properties[i].enable_indicate = TURN_OFF;
		conn_properties[i].threshold_aler =  TURN_OFF;
	}
}

void cmd_set_timer_handler(sl_cli_command_arg_t *arguments) {
	int argc = sl_cli_get_argument_count(arguments);
	if (argc < 2) {
		printf("Not enough arguments. Expected 2! \n");
		return;
	} else {
		uint8_t device = sl_cli_get_argument_uint8(arguments, 0);
		uint8_t timer = sl_cli_get_argument_uint8(arguments, 1);

		//set timer for device.
		sc = sl_bt_gatt_write_characteristic_value(conn_properties[device].connection_char,
				conn_properties[device].device_control_characteristic_handle, sizeof(timer), &timer);
		app_assert_status(sc);
		printf("timer setting for device %d is successful!\n", device);
	}
}

void cmd_set_connect_device_handler(sl_cli_command_arg_t *arguments) {
	int argc = sl_cli_get_argument_count(arguments);
	if (argc < 2) {
		printf("Not enough arguments. Expected 2! \n");
		return;
	} else {
		uint8_t device = sl_cli_get_argument_uint8(arguments, 0);
		uint8_t stage_sent = sl_cli_get_argument_uint8(arguments, 1); // 1 - on, 0 - off.

		if (stage_sent) {
			// Bật thiết bị.
			conn_properties[device].state_of_device = TURN_ON;
			// Bật indications.
			conn_properties[device].enable_indicate = TURN_ON;
		} else {
			// Bật thiết bị.
			conn_properties[device].state_of_device = TURN_OFF;
			// Bật indications.
			conn_properties[device].enable_indicate = TURN_OFF;
		}

		sc = sl_bt_gatt_write_characteristic_value(conn_properties[device].connection_char,
				conn_properties[device].button_characteristic_handle, sizeof(stage_sent), &stage_sent);
		app_assert_status(sc);
		printf("control signal sent successfully to device %d!\n", device);
	}
}

void cmd_set_virtual_threshold_handler(sl_cli_command_arg_t *arguments) {
	int argc = sl_cli_get_argument_count(arguments);
	if (argc < 3) {
		printf("Not enough arguments. Expected 2! \n");
		return;
	} else {
		uint8_t device = sl_cli_get_argument_uint8(arguments, 0);
		uint8_t type = sl_cli_get_argument_uint8(arguments, 1);
		uint8_t value = sl_cli_get_argument_uint8(arguments, 2);

		conn_properties[device].virtual_threshold[type] = value;

		printf("virtual %d value of the device %d = %d!\n", type, device, value);
	}
}

void cmd_set_threshold_for_device_handler(sl_cli_command_arg_t *arguments) {
	int argc = sl_cli_get_argument_count(arguments);
	if (argc < 3) {
		printf("Not enough arguments. Expected 2! \n");
		return;
	} else {
		uint8_t device = sl_cli_get_argument_uint8(arguments, 0);
		uint8_t type = sl_cli_get_argument_uint8(arguments, 1);
		uint8_t min_value =
				sl_cli_get_argument_uint8(arguments, 2);
		uint8_t max_value = sl_cli_get_argument_uint8(arguments, 3);
		conn_properties[device].threshold_of_sensor[type][0] = min_value;
		conn_properties[device].threshold_of_sensor[type][1] = max_value;

		printf("set threshold for device %d successfully!\n", device);
	}
}

void display_screen(uint8_t x, uint8_t y, uint8_t index_device)
{
	if (status_of_device == CONNECT) {
		draw_string(64, 1, "     CONNECT", GREEN, BLACK);
		// Khi đang đang được kết nối.
		if (conn_properties[index_device].state_of_device == TURN_ON) {
			draw_string(104, index_device * 60 + 15, "&", YELLOW, BLACK);
			draw_string(112, index_device * 60 + 15, "@", YELLOW, BLUE);
		} else {
			draw_string(104, index_device * 60 + 15, "&", YELLOW, RED);
			draw_string(112, index_device * 60 + 15, "@", YELLOW, BLACK);
		}

		if (conn_properties[index_device].threshold_aler ==  TURN_ON) {
			// vẽ biểu tượng quả chuông khi chưa có không báo.
			draw_string(144, index_device * 60 + 15, "a", RED, BLACK);
		} else {
			// vẽ biểu tượng quả chuông khi có không báo.
			draw_string(144, index_device * 60 + 15, "a", GREEN, BLACK);
		}

		// In thông tin ra màn hình.
		if (conn_properties[index_device].enable_indicate == TURN_ON) {

			// vẽ biểu tượng enable indicate.
			draw_string(128, index_device * 60 + 15, "b", GREEN, BLACK);

			// Kiểm trang thông tin có bị null không và in ra màn hình.
			if (conn_properties[index_device].connection_handle != CONNECTION_HANDLE_INVALID &&
					conn_properties[index_device].integer_humi_value != 0 &&
					conn_properties[index_device].integer_temp_value != 0) {
				char* str = update_value(conn_properties[index_device].integer_humi_value, conn_properties[index_device].decimal_humi_value);
				strcat(str, "%");
				draw_string(x, y, "      ", WHITE, BLACK);		// clear screen.
				draw_string(x, y, str, WHITE, BLACK);

				str = update_value(conn_properties[index_device].integer_temp_value, conn_properties[index_device].decimal_temp_value);
				strcat(str, "?");
				draw_string(x, y + 15, "      ", WHITE, BLACK);        // clear screen.
				draw_string(x, y + 15, str, WHITE, BLACK);

				str = convert_light_intensity_to_string(conn_properties[index_device].light_value_hight, conn_properties[index_device].light_value_low);
				strcat(str, "LUX");
				draw_string(x, y + 30, "            ", WHITE, BLACK);  // clear screen.
				draw_string(x, y + 30, str, WHITE, BLACK);
			}
		} else {
			// vẽ biểu tượng enable indicate.
			draw_string(128, index_device * 60 + 15, "b", RED, BLACK);
		}
	} else if (status_of_device == PAUSE){
		draw_string(64, 1, "       PAUSE", RED, BLACK);
		// vẽ biểu tượng disenable indicate.
		draw_string(128, index_device * 60 + 15, "b", RED, BLACK);

	} else {
		// In lại thông tin các thiết bị đang ở trạng thái off.
		draw_string(104, index_device * 60 + 15, "&", YELLOW, RED);
		draw_string(112, index_device * 60 + 15, "@", YELLOW, BLACK);

		// In lại thông tin các thiết bị đang ở trạng thái disenable indications.
		draw_string(128, index_device * 60 + 15, "b", RED, BLACK);

		// vẽ biểu tượng quả chuông khi chưa có không báo.
		draw_string(144, index_device * 60 + 15, "a", RED, BLACK);

		// Vẽ biểu tượng đang tìm kiếm.
		draw_string(64, 1, "SCANNING ", RED, BLACK);
		draw_string(136, 1, ".  ", RED, BLACK);
		draw_string(136, 1, "   ", RED, BLACK);
		draw_string(136, 1, ".. ", RED, BLACK);
		draw_string(136, 1, "   ", RED, BLACK);
		draw_string(136, 1, "...", RED, BLACK);
		draw_string(136, 1, "   ", RED, BLACK);
		draw_string(136, 1, "...", RED, BLACK);
	}
}
