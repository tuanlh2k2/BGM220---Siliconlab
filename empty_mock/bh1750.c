#include "bh1750.h"
void bh1750_init(){
  sl_status_t sc;
  sc = bh1750_write(CMD_POWER_DOWN, 1);
  sl_sleeptimer_delay_millisecond(2);
  bh1750_write(CMD_POWER_ON, 1);
  sl_sleeptimer_delay_millisecond(2);
  bh1750_write(CMD_H_RES_MODE,1);
  sl_sleeptimer_delay_millisecond(200);
}
sl_status_t bh1750_write(uint8_t src, uint32_t len)
{
  I2C_TransferSeq_TypeDef seq;
  I2C_TransferReturn_TypeDef ret;
  uint8_t i2c_read_data[1];
  seq.addr =  BH1750_ADDR_WRITE;
  seq.flags = I2C_FLAG_WRITE;

  /*Write buffer*/
  seq.buf[0].data = src;
  seq.buf[0].len = len;
  /* Select length of data to be read */
  seq.buf[1].data = i2c_read_data;
  seq.buf[1].len  = 0;
  // Do a polled transfer
  ret = I2C_TransferInit(sl_i2cspm_mikroe, &seq);
  while (ret == i2cTransferInProgress)
    {
      ret = I2C_Transfer(sl_i2cspm_mikroe);
    }
  if(ret != i2cTransferDone) return SL_STATUS_FAIL;
  else return 0;
}
sl_status_t bh1750_readData( uint16_t *lux_data) {
  I2C_TransferSeq_TypeDef seq;
  I2C_TransferReturn_TypeDef ret;
  uint8_t buffer[2];
  uint8_t i2c_read_data[1];

  seq.addr = BH1750_ADDR_WRITE;
  seq.flags = I2C_FLAG_READ; // Đọc dữ liệu

  seq.buf[0].data = buffer;
  seq.buf[0].len = 2;

  seq.buf[1].data = i2c_read_data;
  seq.buf[1].len = 0;

  ret = I2C_TransferInit(sl_i2cspm_mikroe, &seq);
  while (ret == i2cTransferInProgress) {
      ret = I2C_Transfer(sl_i2cspm_mikroe);
  }
  if (ret != i2cTransferDone) {
      return SL_STATUS_FAIL;
  }
  else{
      *lux_data = ((uint16_t)buffer[0] << 8) | buffer[1];
      return SL_STATUS_OK;
  }
}

void printBH1750Data() {
  uint16_t lux_data;
  sl_status_t status;
  status = bh1750_readData(&lux_data);

  if (status != SL_STATUS_OK) {
      printf("Failed to read data from BH1750.\n");
  }
  else{
      bh1750_readData(&lux_data);
      printf("Lux Data: %d\n", lux_data);
  }
}
