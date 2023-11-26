/*
 * dht11.h
 *
 *  Created on: Jul 25, 2023
 *      Author: Wind
 */

#ifndef DHT11_H
#define DHT11_H

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <stdio.h>
#include <stdint.h>
#include "stdbool.h"
#include "em_gpio.h"
#include "em_cmu.h"
#include "app_log.h"
#include "sl_udelay.h"
#include "system_bgm22.h"

/*******************************************************************************
 * Macros
 ******************************************************************************/
typedef enum {
  DHT11_OK = 0,
  DHT11_ERROR
}dht11_status_t;
/*******************************************************************************
 * Defines
 ******************************************************************************/
#define TIMEOUT UINT32_MAX

/*******************************************************************************
 * Functions
 ******************************************************************************/
// This function is used to send signal from kit to dht11 request to send data.
void Request(void);

// This function is used to get response signal from dht11 after sending read request.
void Response(void);

// This function reads 40 bits of data from dht11 sent back.
void readData();

// This function calculates the response time.
uint32_t expectPulse(bool level);

// This function calculates the humidity value from 8 bits integer and 8 bits comma converted to 16 bit format.
int16_t CalcHumidity();

// This function calculates the temperature value from 8 bits integer and 8 bits comma converted to 16 bit format.
int16_t CalcTemperature();

// this function is called by main function to get data.
void readDataDHT11(uint16_t *humiValue, uint16_t *tempValue);
// print data of DHT11
void printDHT11Data();
/*******************************************************************************
 * END
 ******************************************************************************/

#endif /* DHT11_H */
