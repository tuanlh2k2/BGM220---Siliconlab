/*
 * threshold_alert.c
 *
 *  Created on: Aug 16, 2023
 *      Author: Wind
 */
#include "threshold_alert.h"
#include "app_log.h"
void threshold_alert_init(void)
{
	CMU_ClockEnable(cmuClock_GPIO, true);

	/* Setup GPIOs */
	GPIO_PinModeSet(DEVICE1_PORT, DEVICE1_PIN, gpioModePushPull, 0);

	GPIO_PinModeSet(DEVICE2_PORT, DEVICE2_PIN, gpioModePushPull, 0);
}

bool check_threshold_alert(uint8_t humi, uint8_t temp,  uint8_t light, uint8_t threshold[3][2])
{
	//app_log("vn 1 = %d %d %d \n\n", threshold[0][1], threshold[1][1], threshold[2][1]);
	if (humi >= threshold[0][1] || temp >= threshold[1][1] || light >= threshold[2][1]) {
		app_log("Vuot nguong 1 !!!\n\n");
		return true;
	}
	//app_log("vn 2 = %d %d %d \n\n", threshold[0][0], threshold[1][0], threshold[2][0]);
	if (humi < threshold[0][0] || temp < threshold[1][0]) {
		app_log("Vuot nguong 2 %d %d!!!\n\n", threshold[0][0], temp <= threshold[1][0]);
		return true;
	}
	return false;
}

void turn_on_threshold_alert(uint8_t device)
{
	if (device == 0) {
		GPIO_PinOutSet(DEVICE1_PORT, DEVICE1_PIN);
	} else {
		GPIO_PinOutSet(DEVICE2_PORT, DEVICE2_PIN);
	}
}

void turn_off_threshold_alert(uint8_t device)
{
	if (device == 0) {
		GPIO_PinOutClear(DEVICE1_PORT, DEVICE1_PIN);
	} else {
		GPIO_PinOutClear(DEVICE2_PORT, DEVICE2_PIN);
	}
}
