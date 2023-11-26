#include <stdio.h>
#include <stdint.h>

#include "dht11.h"
#include "app_log.h"
#include "em_gpio.h"

#ifndef GPIO_DHT11PORT
#define GPIO_DHT11PORT                  gpioPortC
#endif // GPIO_DHT11PORT

#define GPIO_DHT11PIN                   1

#define GPIO_DHT11PIN_INPUTMODE         gpioModeInput
#define GPIO_DHT11PIN_OUTPUTMODE        gpioModePushPull

#define GPIO_DHT11PIN_LOW            0
#define GPIO_DHT11PIN_HIGH           1

const float NAN = -99.0;

/***************************************************************************//**
 * Khởi tạo chân dữ liệu và bắt đầu quá trình liên kết với dht11.
 ******************************************************************************/
void dht_init(void)
{
	GPIO_PinModeSet(GPIO_DHT11PORT, 1, GPIO_DHT11PIN_OUTPUTMODE, 1);
}

/***************************************************************************//**
 * Gửi xung start cho cảm biến để bắt đầu quá trình đọc dữ liệu.
 ******************************************************************************/
void dht_start(void)
{
	app_log("OKK\n");
	// clear.
	GPIO_PortOutClear(GPIO_DHT11PORT, 1);
	sl_udelay_wait(500);
	// set.
	GPIO_PortOutSet(GPIO_DHT11PORT, 1);
	sl_udelay_wait(500);
}

/***************************************************************************//**
 * Nhận phản hồi từ cảm biến.
 ******************************************************************************/
void dht_response(void)
{
	GPIO_PinModeSet(GPIO_DHT11PORT, 1, GPIO_DHT11PIN_INPUTMODE, 0);
	uint8_t count = 0;
	while(GPIO_PinModeGet(GPIO_DHT11PORT, 1) == 0) {
		count ++;
	}
	app_log("count 1 = %d\n", count);
	count = 0;
	while(GPIO_PinModeGet(GPIO_DHT11PORT, 1) == 1) {
		count ++;
	}
	app_log("count 1 = %d\n", count);
}

/***************************************************************************//**
 * Nhận 8 bit dữ liệu.
 ******************************************************************************/
uint8_t dht_get_data()
{
	uint8_t data = 0;
	return data;
}
