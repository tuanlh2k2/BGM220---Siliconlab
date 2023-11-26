#include "em_gpio.h"

void app_init(void)
{
	GPIO_PinModeSet(gpioPortA, 4, gpioModePushPull, 1);
}

/***************************************************************************//**
 * App ticking function.
 ******************************************************************************/
void app_process_action(void)
{
	GPIO_PinOutSet(gpioPortA, 4);
	sl_sleeptimer_delay_millisecond(500);
	GPIO_PinOutClear(gpioPortA, 4);
	sl_sleeptimer_delay_millisecond(500);
}
