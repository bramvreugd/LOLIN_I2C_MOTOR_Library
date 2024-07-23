
#ifndef __LOLIN_I2C_MOTOR_H
#define __LOLIN_I2C_MOTOR_H

#if ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

#include "Wire.h"

#define PRODUCT_ID_I2C_MOTOR 0x02
#define DEFAULT_I2C_MOTOR_ADDRESS 0x30

enum I2C_MOTOR_ERROR
{
  I2C_MOTOR_SUCCESS=0,
  I2C_MOTOR_DATATOLONG,      // i2c error
  I2C_MOTOR_RECEIVENACKADR,  // i2c error
  I2C_MOTOR_RECEIVENACKDATA, // i2c error
  I2C_MOTOR_I2COTHER,        // i2c error
  I2C_MOTOR_TIMEOUT,         // i2c errors
  I2C_MOTOR_WRONGADR,        // adr 0 or >127 not supported
  I2C_MOTOR_MISSINGDATA,     // respone needs 2 bytes for GET_SLAVE_STATUS or 1 byte for other messages within 200ms
  I2C_MOTOR_BADRESPONSE      // send message should return 1.
};

enum I2C_MOTOR_CMD
{
  GET_SLAVE_STATUS = 0x01,
  RESET_SLAVE,
  CHANGE_I2C_ADDRESS,
  CHANGE_STATUS,
  CHANGE_FREQ,
  CHANGE_DUTY
};

enum MOTOR_STATUS
{
  MOTOR_STATUS_STOP = 0x00,
  MOTOR_STATUS_CCW,
  MOTOR_STATUS_CW,
  MOTOR_STATUS_SHORT_BRAKE,
  MOTOR_STATUS_STANDBY
};

enum MOTOR_CHANNEL
{
  MOTOR_CH_A=0x00,
  MOTOR_CH_B,
  MOTOR_CH_BOTH
};


class LOLIN_I2C_MOTOR
{
  public:
	boolean begin(unsigned char address = DEFAULT_I2C_MOTOR_ADDRESS, TwoWire *i2c = &Wire);

	unsigned char reset(void);
	unsigned char changeAddress(unsigned char address);
  unsigned char getInfo(void);
  
  unsigned char changeStatus(unsigned char ch, unsigned char sta);
  unsigned char changeFreq(unsigned char ch, uint32_t freq);
  unsigned char changeDuty(unsigned char ch, float duty);

  unsigned char VERSION=0;
  unsigned char PRODUCT_ID=0;

  private:
	unsigned char _address;
	unsigned char send_data[5] = {0};
	unsigned char get_data[2]={0};
	unsigned char sendData(unsigned char *data, unsigned char len);
};

#endif
