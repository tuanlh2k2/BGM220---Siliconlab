/***************************************************************************//**
 * @file
 * @brief Top level application functions
 *******************************************************************************
 * # License
 * <b>Copyright 2020 Silicon Laboratories Inc. www.silabs.com</b>
 *******************************************************************************
 *
 * The licensor of this software is Silicon Laboratories Inc. Your use of this
 * software is governed by the terms of Silicon Labs Master Software License
 * Agreement (MSLA) available at
 * www.silabs.com/about-us/legal/master-software-license-agreement. This
 * software is distributed to you in Source Code format and is governed by the
 * sections of the MSLA applicable to Source Code.
 *
 ******************************************************************************/

#ifndef BH1750_H
#define BH1750_H

#include <stdio.h>
#include <stdint.h>
#include "em_gpio.h"
#include "em_cmu.h"
#include "app_log.h"
#include "sl_udelay.h"
#include "system_bgm22.h"
#include "sl_i2cspm_instances.h"
#include "sl_sleeptimer.h"
#include "sl_status.h"

#define BH1750_ADDR_WRITE       0x46

//instructions
//datasheet ref http://cpre.kmutnb.ac.th/esl/learning/bh1750-light-sensor/bh1750fvi-e_datasheet.pdf
#define CMD_POWER_DOWN          0x00
#define CMD_POWER_ON            0x01
#define CMD_RESET               0x03
#define CMD_H_RES_MODE          0x10
#define CMD_H_RES_MODE2         0x11
#define CMD_L_RES_MODE          0x13
#define CMD_ONE_H_RES_MODE      0x20
#define CMD_ONE_H_RES_MODE2     0x21
#define CMD_ONE_L_RES_MODE      0x23
#define CMD_CNG_TIME_HIGH       0x30    // 3 LSB set time
#define CMD_CNG_TIME_LOW        0x60    // 5 LSB set time

//void BH1750_Init();
//void BH1750_write(uint8_t cmd);
//uint16_t BH1750_readData();
//uint16_t BH1750_lux(uint8_t cmd);
sl_status_t bh1750_write(uint8_t src, uint32_t len);
sl_status_t bh1750_readData(uint16_t *lux_data);
void printBH1750Data();
void bh1750_init();

#endif  // BH1750_H
