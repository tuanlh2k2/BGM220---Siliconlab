/*
 * threshold_alert.h
 *
 *  Created on: Aug 16, 2023
 *      Author: Wind
 */
#include "stdbool.h"
#include "stdint.h"
#include "em_cmu.h"
#include "em_gpio.h"

#ifndef THRESHOLD_ALERT_H_
#define THRESHOLD_ALERT_H_

#define DEVICE1_PORT	gpioPortB
#define DEVICE1_PIN		3
#define DEVICE2_PORT 	gpioPortB
#define DEVICE2_PIN 	2

#define TEMPERATURE_MIN 20
#define HUMIDITY_MIN	50
#define	LIGHT_MIN		20000

#define TEMPERATURE_MAX 34
#define HUMIDITY_MAX	88
#define	LIGHT_MAX		30000

// check elert init.
void threshold_alert_init(void);
// check elert.
bool check_threshold_alert(uint8_t humi, uint8_t temp,  uint8_t light, uint8_t threshold[3][2]);

void turn_on_threshold_alert(uint8_t device);

void turn_off_threshold_alert(uint8_t device);
#endif /* THRESHOLD_ALERT_H_ */
