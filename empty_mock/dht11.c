/*
 * dht11.c
 *
 *  Created on: Jul 25, 2023
 *      Author: Wind
 */
#include "dht11.h"

static uint32_t maxcycles = 150;
uint8_t data_dht11[5] = {};
uint32_t max_freq = 80000000UL;

// request.
void Request(void) {
  // init C1 is output.
  // init C1 is input.
  CMU_ClockEnable(cmuClock_GPIO, true);
  GPIO_PinModeSet(gpioPortC, 1, gpioModePushPull, 0);
  sl_sleeptimer_delay_millisecond(23);
  GPIO_PinOutSet(gpioPortC, 1);
  sl_udelay_wait(14);
  GPIO_PinModeSet(gpioPortC, 1, gpioModeInput, 1);
}

// response.
void Response(void) {
  while (GPIO_PinInGet(gpioPortC, 1) == 1);
  while (GPIO_PinInGet(gpioPortC, 1) == 0);
  while (GPIO_PinInGet(gpioPortC, 1) == 1);
}


// read data.
void readData()
{
  for(int i = 0; i < 40; i++) {
      while (GPIO_PinInGet(gpioPortC, 1) == 0);
      sl_udelay_wait(30);
      if (GPIO_PinInGet(gpioPortC, 1) == 1) {
          data_dht11[i/8] = (data_dht11[i/8] << 1) | 0x01;
      } else {
          data_dht11[i/8] = (data_dht11[i/8] << 1);
      }
      if (expectPulse(1) == TIMEOUT) {
          app_log("ERROR\n");
      }
  }
  app_log("\n");
  if ((data_dht11[0] + data_dht11[1] + data_dht11[2] + data_dht11[3]) != data_dht11[4]) {
      app_log("ERROR\n");
  }
}

uint32_t expectPulse(bool level)
{
  uint32_t count = 0;

  // Look into using DMA functionality here
  while ( GPIO_PinInGet(gpioPortC, 1) == level) {
      if (count++ >= maxcycles) {
          return TIMEOUT; // Exceeded timeout, fail.
      }
  }
  return count;
}

int16_t CalcHumidity()
{
  int16_t fHumidity;
  fHumidity = ((int16_t)data_dht11[0]) << 8 | data_dht11[1];
  return fHumidity;
}

int16_t CalcTemperature()
{
  int16_t fTemperature ;
  fTemperature = ((int16_t)data_dht11[2]) << 8 | data_dht11[3];
  return fTemperature;
}

void readDataDHT11(uint16_t *humiValue, uint16_t *tempValue)
{
  // start.
  Request();

  // response.
  Response();

  // read data.
  readData();
  // assign value.
  *humiValue = CalcHumidity();
  *tempValue = CalcTemperature();
}

void printDHT11Data(){
  uint32_t humi, temp;
  readDataDHT11(&humi, &temp);
  app_log("Humi = %5.2f %%, Temp =  %f *C\n", (humi * 1.0) / 256, (temp * 1.0) / 256);
}
