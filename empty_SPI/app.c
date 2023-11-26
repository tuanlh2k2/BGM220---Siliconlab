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
#include <st7735_spi.h>
#include "sl_spidrv_instances.h"
#include "st7735.h"
//#define DISPLAY_TEXT  0;

//SPIDRV_HandleData_t handleData;
//SPIDRV_Handle_t handle = &handleData;


void app_init(void)
{
	st7735_init();
	st7735_set_window(0, 0, 160, 128);
	draw_string(0, 90, "FPT SOFTWARE ", RED );
}

/***************************************************************************//**
 * App ticking function.
 ******************************************************************************/
void app_process_action(void)
{
	draw_string(0, 1, "DEVICE 1", YELLOW);
	draw_string(0, 9, "HUMIDITY: 58%", BLUE);
	draw_string(0, 18, "TEMPERATURE: 21?", BLUE);
	draw_string(0, 27, "LIGHT INTENSITY: 16", BLUE);

	draw_string(0, 45, "DEVICE 2", YELLOW);
	draw_string(0, 54, "HUMIDITY: 58%", BLUE);
	draw_string(0, 63, "TEMPERATURE: 21?", BLUE);
	draw_string(0, 72, "LIGHT INTENSITY: 16", BLUE);
}
