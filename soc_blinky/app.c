/***************************************************************************//**
 * @file
 * @brief Core application logic.
 *******************************************************************************
 * # License
 * <b>Copyright 2021 Silicon Laboratories Inc. www.silabs.com</b>
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
#include "em_common.h"
#include "app_assert.h"
#include "app_log.h"
#include "sl_bluetooth.h"
#include "sl_simple_timer.h"
#include "gatt_db.h"
#include "dht11.h"
#include "app.h"
#include "sl_simple_button_instances.h"
#include "sl_simple_led_instances.h"

// flag of sensor.
static bool flag_of_sensor = false;

// value sensor.
static uint8_t integer_humi, decimal_humi, integer_temp, decimal_temp;

// The advertising set handle allocated from Bluetooth stack.
static uint8_t advertising_set_handle = 0xff;

// Connection handle.
static uint8_t app_connection = 0;
// Periodic timer handle.
static sl_simple_timer_t app_periodic_timer;
// Periodic timer callback.
static void app_periodic_timer_cb(sl_simple_timer_t *timer, void *data);

/**************************************************************************//**
 * Application Init.
 *****************************************************************************/
SL_WEAK void app_init(void)
{
	sl_bt_system_set_lazy_soft_timer(32768 * 10, 0, 0, 0);  // timer read sensor.
	sl_bt_system_set_lazy_soft_timer(32768 / 5, 0, 1, 0);   // timer blink led.
}

/**************************************************************************//**
 * Application Process Action.
 *****************************************************************************/
SL_WEAK void app_process_action(void)
{
	if (flag_of_sensor == true) {
		dht11_status_t sc;
		sc = readDataDHT11(&integer_humi, &decimal_humi, &integer_temp, &decimal_temp);
		if (sc == DHT11_OK) {
			app_log("humi = %d.%d%%, temp =  %d.%d*C\n", integer_humi, decimal_humi, integer_temp, decimal_temp);
		}
		flag_of_sensor = false;
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
	sl_status_t sc;
	bd_addr address;
	uint8_t address_type;
	uint8_t system_id[8];

	switch (SL_BT_MSG_ID(evt->header)) {

	case sl_bt_evt_system_soft_timer_id:
		if (evt->data.evt_system_soft_timer.handle == 0) {
			flag_of_sensor = true;
		}
		if (evt->data.evt_system_soft_timer.handle == 1) {

		}
		break;
		// -------------------------------
		// This event indicates the device has started and the radio is ready.
		// Do not call any stack command before receiving this boot event!
	case sl_bt_evt_system_boot_id:
		// Extract unique ID from BT Address.
		sc = sl_bt_system_get_identity_address(&address, &address_type);
		app_assert_status(sc);

		// Pad and reverse unique ID to get System ID.
		system_id[0] = address.addr[5];
		system_id[1] = address.addr[4];
		system_id[2] = address.addr[3];
		system_id[3] = 0xFF;
		system_id[4] = 0xFE;
		system_id[5] = address.addr[2];
		system_id[6] = address.addr[1];
		system_id[7] = address.addr[0];

		sc = sl_bt_gatt_server_write_attribute_value(gattdb_system_id,
				0,
				sizeof(system_id),
				system_id);
		app_assert_status(sc);

		// Create an advertising set.
		sc = sl_bt_advertiser_create_set(&advertising_set_handle);
		app_assert_status(sc);

		// Set advertising interval to 100ms.
		sc = sl_bt_advertiser_set_timing(
				advertising_set_handle,
				160, // min. adv. interval (milliseconds * 1.6)
				160, // max. adv. interval (milliseconds * 1.6)
				0,   // adv. duration
				0);  // max. num. adv. events
		app_assert_status(sc);
		// Start general advertising and enable connections.
		sc = sl_bt_advertiser_start(
				advertising_set_handle,
				sl_bt_advertiser_general_discoverable,
				sl_bt_advertiser_connectable_scannable);
		app_assert_status(sc);
		break;

		// -------------------------------
		// This event indicates that a new connection was opened.
	case sl_bt_evt_connection_opened_id:

		// bắt đầu đặt định thời gửi dữ liệu tại đây.
		app_connection = evt->data.evt_connection_opened.connection;
		sc = sl_simple_timer_start(&app_periodic_timer,
				1000,
				app_periodic_timer_cb,
				NULL,
				true);
		app_assert_status(sc);
		// Send first indication.
		app_periodic_timer_cb(&app_periodic_timer, NULL);

		break;

		// -------------------------------
		// This event indicates that a connection was closed.
	case sl_bt_evt_connection_closed_id:
		app_log_info("Connection closed.\n");

		// Restart advertising after client has disconnected.
		sc = sl_bt_advertiser_start(
				advertising_set_handle,
				sl_bt_advertiser_general_discoverable,
				sl_bt_advertiser_connectable_scannable);
		app_assert_status(sc);
		break;

		// -------------------------------
		// This event indicates that the value of an attribute in the local GATT
		// database was changed by a remote GATT client.
	case sl_bt_evt_gatt_server_attribute_value_id:
		// The value of the gattdb_led_control characteristic was changed.
		if (gattdb_button_characteristic == evt->data.evt_gatt_server_characteristic_status.characteristic) {
			uint8_t data_recv;
			size_t data_recv_len;

			// Read characteristic value.
			sc = sl_bt_gatt_server_read_attribute_value(gattdb_button_characteristic,
					0,
					sizeof(data_recv),
					&data_recv_len,
					&data_recv);
			(void)data_recv_len;
			app_log_status_error(sc);

			if (sc != SL_STATUS_OK) {
				break;
			}

			// Toggle LED.
			if (data_recv == 0x00) {
				sl_led_turn_off(SL_SIMPLE_LED_INSTANCE(0));
				app_log_info("LED off.\n");
			} else if (data_recv == 0x01) {
				sl_led_turn_on(SL_SIMPLE_LED_INSTANCE(0));
				app_log_info("LED on.\n");
			} else {
				app_log_error("Invalid attribute value: 0x%02x\n", (int)data_recv);
			}
		}
		break;

		///////////////////////////////////////////////////////////////////////////
		// Add additional event handlers here as your application requires!      //
		///////////////////////////////////////////////////////////////////////////

		// -------------------------------
		// Default event handler.
	default:
		break;
	}
}

/***************************************************************************//**
 * Simple Button
 * Button state changed callback
 * @param[in] handle Button event handle
 ******************************************************************************/
void sl_button_on_change(const sl_button_t *handle)
{
	if (SL_SIMPLE_BUTTON_INSTANCE(0) == handle) {
	}
}

/**************************************************************************//**
 * Timer callback
 * Called periodically to time periodic temperature measurements and indications.
 *****************************************************************************/
uint8_t counter = 0;
static void app_periodic_timer_cb(sl_simple_timer_t *timer, void *data)
{
  (void)data;
  (void)timer;
  sl_status_t sc;
  int32_t temperature = 0;
  uint32_t humidity = 0;
  uint8_t buf[5] = { 0 };
  counter++;
  buf[0] = counter;
  sc = sl_bt_gatt_server_send_indication(app_connection, gattdb_button_characteristic, sizeof(buf), buf);
  if (sc) {
    app_log_warning("Failed to send temperature measurement indication\n");
  }
}
