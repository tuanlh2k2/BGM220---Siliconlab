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
#include "em_gpio.h"
#include "em_cmu.h"
#include "app.h"
#include "app_log.h"
#include "sl_simple_led_instances.h"

void app_init(void)
{
	blink_init();
	button_init();
	sl_sleeptimer_init();
}

/***************************************************************************//**
 * App ticking function.
 ******************************************************************************/
void app_process_action(void)
{
	if (1 == GPIO_PinInGet(gpioPortC, 3)) {
		// GPIO_PinOutSet(gpioPortC, 1);
		blink_led();
	}
	else {
		GPIO_PinOutClear(gpioPortC, 1);
	}
	app_log("%d\n", GPIO_PinInGet(gpioPortC, 3));
}


// blink led.
void blink_led(void)
{
	GPIO_PinOutSet(gpioPortC, 1);
	sl_sleeptimer_delay_millisecond(100);
	GPIO_PinOutClear(gpioPortC, 1);
	sl_sleeptimer_delay_millisecond(100);
}

// init led blink.
void blink_init(void)
{
	CMU_ClockEnable(cmuClock_GPIO, true);
	GPIO_PinModeSet(gpioPortC, 1, gpioModePushPull, 0);
}

// init button.
void button_init(void)
{
	CMU_ClockEnable(cmuClock_GPIO, true);
	GPIO_PinModeSet(gpioPortC, 3, gpioModeInputPullFilter, 1);
}
