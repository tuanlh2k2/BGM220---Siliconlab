/*
 * st7735_spi.c
 *
 *  Created on: Jul 30, 2023
 *      Author: Luong Huu Tuan.
 */
#include <st7735_spi.h>
#include "em_cmu.h"
#include "em_gpio.h"
#include "spidrv.h"
#include "sl_spidrv_instances.h"

#define spi_handle    sl_spidrv_mikroe_handle

/***************************************************************************//**
 * @brief
 *   Initialize gpio used in the SPI interface.
 *
 * @detail
 *  The driver instances will be initialized automatically,
 *  during the sl_system_init() call in main.c.
 *****************************************************************************/
void st7735_spi_init(void)
{
  CMU_ClockEnable(cmuClock_GPIO, true);

  /* Setup GPIOs */

  /* Configure RS pin as an output and drive inactive high */
  GPIO_PinModeSet(ST7735_RS_GPIO_PORT, ST7735_RS_GPIO_PIN, gpioModePushPull, 1);

  /* Configure DC pin as an output and drive inactive high */
  GPIO_PinModeSet(ST7735_SPI_DC_PORT, ST7735_SPI_DC_PIN, gpioModePushPull, 1);
}

/**
 * This function sends commands to the screen
 * @param cmd
 * @return
 */
sl_status_t st7735_send_command(uint8_t cmd)
{
  Ecode_t ret;
  uint8_t cmd_sent = cmd;
  /* Clear DC pin to send command */
  GPIO_PinOutClear(ST7735_SPI_DC_PORT, ST7735_SPI_DC_PIN);

  /* Blocking data transfer to slave. */
  ret = SPIDRV_MTransmitB(spi_handle, &cmd_sent, 1);
  if (ret != ECODE_EMDRV_SPIDRV_OK) {
    return SL_STATUS_FAIL;
  }

  /* Note that at this point all the data is loaded into the fifo, this does
   * not necessarily mean that the transfer is complete. */
  return SL_STATUS_OK;
}

/**
 * This function sends data to the screen.
 * @param data
 * @param len
 * @return
 */
sl_status_t st7735_send_data(uint32_t data, uint8_t len)
{
  Ecode_t ret;
  uint32_t data_sent = data;
  /* Set DC pin to send data */
  GPIO_PinOutSet(ST7735_SPI_DC_PORT, ST7735_SPI_DC_PIN);

  /* Blocking data transfer to slave. */
  ret = SPIDRV_MTransmitB(spi_handle, &data_sent, len);
  if (ret != ECODE_EMDRV_SPIDRV_OK) {
    return SL_STATUS_FAIL;
  }

  /* Note that at this point all the data is loaded into the fifo, this does
   * not necessarily mean that the transfer is complete. */
  return SL_STATUS_OK;
}


