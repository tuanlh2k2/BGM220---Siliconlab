/***************************************************************************//**
 * @file ssd1306_spi.c
 * @brief SPI abstraction used by SSD1306
 *******************************************************************************
* # License
* <b>Copyright 2020 Silicon Laboratories Inc. www.silabs.com</b>
*******************************************************************************
*
* SPDX-License-Identifier: Zlib
*
* The licensor of this software is Silicon Laboratories Inc.
*
* This software is provided \'as-is\', without any express or implied
* warranty. In no event will the authors be held liable for any damages
* arising from the use of this software.
*
* Permission is granted to anyone to use this software for any purpose,
* including commercial applications, and to alter it and redistribute it
* freely, subject to the following restrictions:
*
* 1. The origin of this software must not be misrepresented; you must not
*    claim that you wrote the original software. If you use this software
*    in a product, an acknowledgment in the product documentation would be
*    appreciated but is not required.
* 2. Altered source versions must be plainly marked as such, and must not be
*    misrepresented as being the original software.
* 3. This notice may not be removed or altered from any source distribution.
*
*******************************************************************************
*
* EVALUATION QUALITY
* This code has been minimally tested to ensure that it builds with the specified
* dependency versions and is suitable as a demonstration for evaluation purposes only.
* This code will be maintained at the sole discretion of Silicon Labs.
*
******************************************************************************/
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

/***************************************************************************//**
 * @brief
 *    Send blocking command over SPI interface.
 *
 * @note
 *    The data received on the MISO wire is discarded.
 *    @n This function is blocking and returns when the transfer is complete.
 *
 * @param[in] command
 *    Transmit command buffer.
 *
 * @param[in] len
 *    Number of bytes in transfer.
 *
 * @return
 *    @ref SL_STATUS_OK on success or @ref SL_STATUS_FAIL on failure
 ******************************************************************************/
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

/***************************************************************************//**
 * @brief
 *    Send blocking data over SPI interface.
 *
 * @note
 *    The data received on the MISO wire is discarded.
 *    @n This function is blocking and returns when the transfer is complete.
 *
 * @param[in] data
 *    Transmit data buffer.
 *
 * @param[in] len
 *    Number of bytes in transfer.
 *
 * @return
 *    @ref SL_STATUS_OK on success or @ref SL_STATUS_FAIL on failure
 ******************************************************************************/
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
