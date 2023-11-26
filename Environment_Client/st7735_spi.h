/*
 * st7735_spi.h
 *
 *  Created on: Jul 30, 2023
 *      Author: Luong Huu Tuan
 */

#ifndef ST7735_SPI_H_
#define ST7735_SPI_H_

#include "stdint.h"
#include "sl_status.h"
#include "st7735.h"
#ifdef __cplusplus
extern "C" {
#endif

#define ST7735_SPI_DC_PORT                    gpioPortB
#define ST7735_SPI_DC_PIN                     4

#define ST7735_RS_GPIO_PORT                   gpioPortC
#define ST7735_RS_GPIO_PIN                    6

/***************************************************************************//**
 * @brief
 *   Initialize gpio used in the SPI interface.
 *
 * @detail
 *  The driver instances will be initialized automatically,
 *  during the sl_system_init() call in main.c.
 *****************************************************************************/

void st7735_spi_init(void);
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
sl_status_t st7735_send_command(uint8_t cmd);

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
sl_status_t st7735_send_data(uint32_t data, uint8_t len);

#ifdef __cplusplus
}
#endif

#endif /* ST7735_SPI_H_ */
