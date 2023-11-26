/***************************************************************************//**
 * @file ssd1306.h
 * @brief SSD1306 interface
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

#ifndef SSD1306_H
#define SSD1306_H

#include "sl_status.h"

#include <stdbool.h>
#include <stdint.h>
#include "st7735_spi.h"
//#include "my_font.h"

#ifdef __cplusplus
extern "C" {
#endif


/**
 * General st7735 data structure.
 */
typedef struct st7735_t {
  unsigned short width;       ///< Display pixel width
  unsigned short height;      ///< Display pixel height
} st7735_t;

/* ==================================================================
							DEFINE
=====================================================================*/
#define WHITE             0xFFFF
#define BLACK             0x0000
#define BLUE              0x001F
#define RED               0xF800
#define MAGENTA           0xF81F
#define GREEN             0x07E0
#define CYAN              0x7FFF
#define YELLOW            0xFFE0
#define BROWN 		  	  0XBC40
#define GRAY  		  	  0X8430

/**
 * This function clears the screen.
 */
void st7735_clear(void);

/**
 * This function performs the setting of the display window.
 * @param x is the coordinates of the starting point in the x axis
 * @param y is the coordinate of the starting point along the y trục axis
 * @param w is the width of the frame
 * @param h is the length of the frame
 */
void st7735_set_window(uint8_t x, uint8_t y, uint8_t w, uint8_t h);

/**
 *
 * @param color
 */
void st7735_draw_z(uint16_t color);
void st7735_draw_pixel(int16_t x,int16_t y,uint16_t color);
void draw_character(int coordinate_x, int coordinate_y, char data, uint16_t color);
sl_status_t st7735_init(void);

void draw_string(int coordinate_x, int coordinate_y, const char* str, uint16_t color);

#ifdef __cplusplus
}
#endif

/** @} */

#endif
