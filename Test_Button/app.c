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
#include "em_common.h"
#include "app_assert.h"
#include "sl_bluetooth.h"
#include "gatt_db.h"
#include "sl_simple_button_instances.h"
#include "sl_simple_led_instances.h"
#include "bh1750.h"
#include "app_log.h"
#include "app.h"

static bool report_button_flag = false;
// connection handle
static uint8_t app_connection_handle;
// The advertising set handle allocated from Bluetooth stack.
static uint8_t advertising_set_handle = 0xff;

// These variables need to be added and are used for the connection handle
// and the notification parameters to send Button data to the mobile app
uint8_t g_lab4Connection;
uint8_t notification_data[1] = {0};
uint16_t notification_len = 0;
uint8_t notifyEnabled = false;


// Updates the Report Button characteristic.
static sl_status_t update_report_button_characteristic(void);
/**************************************************************************//**
 * Application Init.
 *****************************************************************************/
SL_WEAK void app_init(void)
{
	/////////////////////////////////////////////////////////////////////////////
	// Put your additional application init code here!                         //
	// This is called once during start-up.                                    //
	/////////////////////////////////////////////////////////////////////////////
}

/**************************************************************************//**
 * Application Process Action.
 *****************************************************************************/
SL_WEAK void app_process_action(void)
{
	/////////////////////////////////////////////////////////////////////////////
	// Put your additional application code here!                              //
	// This is called infinitely.                                              //
	// Do not call blocking functions from here!                               //
	/////////////////////////////////////////////////////////////////////////////
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
		// When sending notifications we need the connection handle.  Capture
		// it here
		g_lab4Connection = evt->data.evt_connection_opened.connection;
		break;

		// -------------------------------
		// This event indicates that a connection was closed.
	case sl_bt_evt_connection_closed_id:
		// Restart advertising after client has disconnected.
		sc = sl_bt_advertiser_start(
				advertising_set_handle,
				sl_bt_advertiser_general_discoverable,
				sl_bt_advertiser_connectable_scannable);
		app_assert_status(sc);
		break;

		///////////////////////////////////////////////////////////////////////////
		// Add additional event handlers here as your application requires!      //
		///////////////////////////////////////////////////////////////////////////
	case sl_bt_evt_gatt_server_user_write_request_id:
		app_log("WRITE\n");
		if (evt->data.evt_gatt_server_user_write_request.characteristic == gattdb_button_characteristic) {
			// Write user supplied value to LEDs.
			if (evt->data.evt_gatt_server_attribute_value.value.data[0]) {

				//This is the use of the Simple LED component
				sl_led_turn_on(&sl_led_led0);
			}
			else {
				//This is the use of the Simple LED component
				sl_led_turn_off(&sl_led_led0);
			}
			sc = sl_bt_gatt_server_send_user_write_response(
					evt->data.evt_gatt_server_user_write_request.connection,
					gattdb_button_characteristic, SL_STATUS_OK);
			app_assert_status(sc);
		}
		break;
	case sl_bt_evt_gatt_server_user_read_request_id:
		app_log("READ\n");
		sl_status_t sc = 0;
		uint8_t respond_data = 1;
		uint8_t respond_data_length = 1;

		sc = sl_bt_gatt_server_send_user_read_response(
				evt->data.evt_gatt_server_user_read_request.connection,
				gattdb_button_characteristic,
				0,
				1,
				(uint8_t *) respond_data,
				NULL);
		app_assert_status(sc);
		break;
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
    report_button_flag = true;
  }
}

/***************************************************************************//**
 * Updates the Report Button characteristic.
 *
 * Checks the current button state and then writes it into the local GATT table.
 ******************************************************************************/
static sl_status_t update_report_button_characteristic(void)
{
  sl_status_t sc;
  uint8_t data_send;

  switch (sl_button_get_state(SL_SIMPLE_BUTTON_INSTANCE(0))) {
    case SL_SIMPLE_BUTTON_PRESSED:
      data_send = (uint8_t)SL_SIMPLE_BUTTON_PRESSED;
      break;

    case SL_SIMPLE_BUTTON_RELEASED:
      data_send = (uint8_t)SL_SIMPLE_BUTTON_RELEASED;
      break;

    default:
      // Invalid button state
      return SL_STATUS_FAIL; // Invalid button state
  }

  // Write attribute in the local GATT database.
  sc = sl_bt_gatt_server_write_attribute_value(gattdb_button_characteristic,
                                               0,
                                               sizeof(data_send),
                                               &data_send);

  if (sc == SL_STATUS_OK) {
    app_log_info("Attribute written: 0x%02x", (int)data_send);
  }

  return sc;
}
