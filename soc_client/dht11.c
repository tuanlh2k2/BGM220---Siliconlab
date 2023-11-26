/*
 * dht11.c
 *
 *  Created on: Jul 25, 2023
 *      Author: Luong Huu Tuan
 */
#include "dht11.h"

static uint32_t maxcycles = 1000;
uint8_t data[5] = {};

// request.
void Request(void) {
	CMU_ClockEnable(cmuClock_GPIO, true);
	GPIO_PinModeSet(DHT11_PORT, DHT11_PIN, gpioModePushPull, 0);
	sl_sleeptimer_delay_millisecond(20);
	GPIO_PinOutSet(DHT11_PORT, DHT11_PIN);
	sl_udelay_wait(14);
	GPIO_PinModeSet(DHT11_PORT, DHT11_PIN, gpioModeInput, 1);
}

// response.
void Response(void) {
	while (GPIO_PinInGet(DHT11_PORT, DHT11_PIN) == 1);
	while (GPIO_PinInGet(DHT11_PORT, DHT11_PIN) == 0);
	while (GPIO_PinInGet(DHT11_PORT, DHT11_PIN) == 1);
}


// read data.
dht11_status_t readData()
{

	//uint8_t data = 0;
	for(int i = 0; i < 40; i++) {
		while (GPIO_PinInGet(DHT11_PORT, DHT11_PIN) == 0);
		sl_udelay_wait(30);
		if (GPIO_PinInGet(DHT11_PORT, DHT11_PIN) == 1) {
			//app_log("1");
			data[i/8] = (data[i/8] << 1) | 0x01;
		} else {
			//app_log("0");
			data[i/8] = (data[i/8] << 1);
		}
		if (expectPulse(1) == TIMEOUT) {
			app_log("ERROR timer out\n");
			return DHT11_ERROR;
		}
	}
	app_log("\n");
	if ((data[0] + data[1] + data[2] + data[3]) != data[4]) {
		app_log("ERROR check sum\n");
		return DHT11_ERROR;
	}
	return DHT11_OK;
}

uint32_t expectPulse(bool level)
{
	uint32_t count = 0;

	// Look into using DMA functionality here
	while ( GPIO_PinInGet(DHT11_PORT, DHT11_PIN) == level) {
		if (count++ >= maxcycles) {
			return TIMEOUT; // Exceeded timeout, fail.
		}
	}
	return count;
}

int16_t CalcHumidity()
{
	int16_t fHumidity = 0;
	fHumidity = ((int16_t)data[0]) << 8 | data[1];
	return fHumidity;
}

int16_t CalcTemperature()
{
	int16_t fTemperature = 0;
	fTemperature = ((int16_t)data[2]) << 8 | data[3];
	return fTemperature;
}

dht11_status_t readDataDHT11(uint8_t *integer_humi, uint8_t *dicimal_humi, uint8_t *integer_temp, uint8_t *dicimal_temp)
{
	dht11_status_t sc;
	// start.
	Request();

	// response.
	Response();

	// read data.
	sc = readData();
	if (sc == DHT11_ERROR) {
		return DHT11_ERROR;
	} else {
		// assign value.
		*integer_humi = data[0];
		*dicimal_humi = data[1];
		*integer_temp = data[2];
		*dicimal_temp = data[3];
		return DHT11_OK;
	}
}
