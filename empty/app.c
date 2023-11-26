/***************************************************************************//**
 * @file
 * @brief Top level application functions
 *******************************************************************************
 * # License
 * <b>Copyright 2020 Silicon Laboratories Inc. www.silabs.com</b>
 *******************************************************************************
 *
 * The licensor of this software is Silicon Laboratories Inc. Your use of this
 * software is governed by the terms of Silicon Labs Master Software License
 * Agreement (MSLA) available at
 * www.silabs.com/about-us/legal/master-software-license-agreement. This
 * software is distributed to you in Source Code format and is governed by the
 * sections of the MSLA applicable to Source Code.
 *
 ******************************************************************************/

/***************************************************************************//**
 * Initialize application.
 ******************************************************************************/
#include "app_log.h"
#include "sl_simple_led_instances.h"
#include "sl_simple_button_instances.h"

int stage = 0;

void app_init(void)
{
	//sl_simple_led_turn_on(&sl_led_led0);
	app_log("Kit init\n");
}

/***************************************************************************//**
 * App ticking function.
 ******************************************************************************/
void app_process_action(void)
{
	if(stage == 1) {
		sl_led_turn_on(&sl_led_led0);
	} else {
		sl_led_turn_off(&sl_led_led0);
	}
}

void sl_button_on_change(const sl_button_t *handle)
{
	if(sl_button_get_state(handle) == SL_SIMPLE_BUTTON_PRESSED) {
		if (&sl_button_btn0 == handle) {
			//sl_led_toggle(&sl_led_led0);
			stage = (stage == 1) ? 0 : 1;
			app_log("Phim duoc nhan!\n");
		}
	}
}
