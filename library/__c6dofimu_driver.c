/*
    __c6dofimu_driver.c

-----------------------------------------------------------------------------

  This file is part of mikroSDK.

  Copyright (c) 2017, MikroElektonika - http://www.mikroe.com

  All rights reserved.

----------------------------------------------------------------------------- */

#include "__c6dofimu_driver.h"
#include "__c6dofimu_hal.c"

/* ------------------------------------------------------------------- MACROS */

// REGISTER
const uint8_t    _C6DOFIMU_FUNC_CFG_ACCESS   = 0x01;
const uint8_t    _C6DOFIMU_FIFO_CTRL1        = 0x06;
const uint8_t    _C6DOFIMU_FIFO_CTRL2        = 0x07;
const uint8_t    _C6DOFIMU_FIFO_CTRL3        = 0x08;
const uint8_t    _C6DOFIMU_FIFO_CTRL4        = 0x09;
const uint8_t    _C6DOFIMU_FIFO_CTRL5        = 0x0A;
const uint8_t    _C6DOFIMU_ORIENT_CFG_G      = 0x0B;
const uint8_t    _C6DOFIMU_INT1_CTRL         = 0x0D;
const uint8_t    _C6DOFIMU_INT2_CTRL         = 0x0E;
const uint8_t    _C6DOFIMU_WHO_AM_I          = 0x0F;
const uint8_t    _C6DOFIMU_CTRL1_XL          = 0x10;
const uint8_t    _C6DOFIMU_CTRL2_G           = 0x11;
const uint8_t    _C6DOFIMU_CTRL3_C           = 0x12;
const uint8_t    _C6DOFIMU_CTRL4_C           = 0x13;
const uint8_t    _C6DOFIMU_CTRL5_C           = 0x14;
const uint8_t    _C6DOFIMU_CTRL6_C           = 0x15;
const uint8_t    _C6DOFIMU_CTRL7_G           = 0x16;
const uint8_t    _C6DOFIMU_CTRL8_XL          = 0x17;
const uint8_t    _C6DOFIMU_CTRL9_XL          = 0x18;
const uint8_t    _C6DOFIMU_CTRL10_C          = 0x19;
const uint8_t    _C6DOFIMU_WAKE_UP_SRC       = 0x1B;
const uint8_t    _C6DOFIMU_TAP_SRC           = 0x1C;
const uint8_t    _C6DOFIMU_D6D_SRC           = 0x1D;
const uint8_t    _C6DOFIMU_STATUS_REG        = 0x1E;
const uint8_t    _C6DOFIMU_FIFO_STATUS1      = 0x3A;
const uint8_t    _C6DOFIMU_FIFO_STATUS2      = 0x3B;
const uint8_t    _C6DOFIMU_FIFO_STATUS3      = 0x3C;
const uint8_t    _C6DOFIMU_FIFO_STATUS4      = 0x3D;
const uint8_t    _C6DOFIMU_FIFO_DATA_OUT_L   = 0x3E;
const uint8_t    _C6DOFIMU_FIFO_DATA_OUT_H   = 0x3F;
const uint8_t    _C6DOFIMU_TIMESTAMP0_REG    = 0x40;
const uint8_t    _C6DOFIMU_TIMESTAMP1_REG    = 0x41;
const uint8_t    _C6DOFIMU_TIMESTAMP2_REG    = 0x42;
const uint8_t    _C6DOFIMU_STEP_TIMESTAMP_L  = 0x49;
const uint8_t    _C6DOFIMU_STEP_TIMESTAMP_H  = 0x4A;
const uint8_t    _C6DOFIMU_STEP_COUNTER_L    = 0x4B;
const uint8_t    _C6DOFIMU_STEP_COUNTER_H    = 0x4C;
const uint8_t    _C6DOFIMU_FUNC_SRC          = 0x53;
const uint8_t    _C6DOFIMU_TAP_CFG           = 0x58;
const uint8_t    _C6DOFIMU_TAP_THS_6D        = 0x59;
const uint8_t    _C6DOFIMU_INT_DUR2          = 0x5A;
const uint8_t    _C6DOFIMU_WAKE_UP_THS       = 0x5B;
const uint8_t    _C6DOFIMU_WAKE_UP_DUR       = 0x5C;
const uint8_t    _C6DOFIMU_FREE_FALL         = 0x5D;
const uint8_t    _C6DOFIMU_MD1_CFG           = 0x5E;
const uint8_t    _C6DOFIMU_MD2_CFG           = 0x5F;
// OUTPUT REGISTER
// TEMP
const uint8_t    _C6DOFIMU_OUT_TEMP_L        = 0x20;
const uint8_t    _C6DOFIMU_OUT_TEMP_H        = 0x21;
// GYRO
const uint8_t    _C6DOFIMU_OUTX_L_G          = 0x22;
const uint8_t    _C6DOFIMU_OUTX_H_G          = 0x23;
const uint8_t    _C6DOFIMU_OUTY_L_G          = 0x24;
const uint8_t    _C6DOFIMU_OUTY_H_G          = 0x25;
const uint8_t    _C6DOFIMU_OUTZ_L_G          = 0x26;
const uint8_t    _C6DOFIMU_OUTZ_H_G          = 0x27;
// ACCEL
const uint8_t    _C6DOFIMU_OUTX_L_XL         = 0x28;
const uint8_t    _C6DOFIMU_OUTX_H_XL         = 0x29;
const uint8_t    _C6DOFIMU_OUTY_L_XL         = 0x2A;
const uint8_t    _C6DOFIMU_OUTY_H_XL         = 0x2B;
const uint8_t    _C6DOFIMU_OUTZ_L_XL         = 0x2C;
const uint8_t    _C6DOFIMU_OUTZ_H_XL         = 0x2D;

// ADDRESS
const uint8_t    _C6DOFIMU_I2C_ADDR          = 0x6B;

// REGISTER CONFIG
const uint8_t    _C6DOFIMU_CTRL12_CONFIG    = 0x80;
const uint8_t    _C6DOFIMU_CTRL3_C_CONFIG    = 0x04;

/* ---------------------------------------------------------------- VARIABLES */

#ifdef   __C6DOFIMU_DRV_I2C__
static uint8_t _slaveAddress;
#endif

/* -------------------------------------------- PRIVATE FUNCTION DECLARATIONS */



/* --------------------------------------------- PRIVATE FUNCTION DEFINITIONS */



/* --------------------------------------------------------- PUBLIC FUNCTIONS */

#ifdef   __C6DOFIMU_DRV_SPI__

void c6dofimu_spiDriverInit(T_C6DOFIMU_P gpioObj, T_C6DOFIMU_P spiObj)
{
    hal_spiMap( (T_HAL_P)spiObj );
    hal_gpioMap( (T_HAL_P)gpioObj );

    // ... power ON
    // ... configure CHIP
}

#endif
#ifdef   __C6DOFIMU_DRV_I2C__

void c6dofimu_i2cDriverInit(T_C6DOFIMU_P gpioObj, T_C6DOFIMU_P i2cObj, uint8_t slave)
{
    _slaveAddress = slave;
    hal_i2cMap( (T_HAL_P)i2cObj );
    hal_gpioMap( (T_HAL_P)gpioObj );

    // ... power ON
    // ... configure CHIP
}

#endif
#ifdef   __C6DOFIMU_DRV_UART__

void c6dofimu_uartDriverInit(T_C6DOFIMU_P gpioObj, T_C6DOFIMU_P uartObj)
{
    hal_uartMap( (T_HAL_P)uartObj );
    hal_gpioMap( (T_HAL_P)gpioObj );

    // ... power ON
    // ... configure CHIP
}

#endif



/* ----------------------------------------------------------- IMPLEMENTATION */


/* Generic write data function */
void c6dofimu_writeData( uint8_t address, uint8_t writeCommand )
{
    uint8_t buffer[2];
    buffer[0]= address;
    buffer[1]= writeCommand;

    hal_i2cStart();
    hal_i2cWrite( _slaveAddress, buffer, 2, END_MODE_STOP );
}

/* Generic read data function */
uint8_t c6dofimu_readData( uint8_t address )
{
    uint8_t writeReg[1];
    uint8_t readReg[1];

    writeReg[0] = address;

    hal_i2cStart();
    hal_i2cWrite( _slaveAddress, writeReg, 1, END_MODE_RESTART );
    Delay_10ms();
    hal_i2cRead( _slaveAddress, readReg, 1, END_MODE_STOP );
    Delay_10ms();

    return readReg[0];
}

/* Function get data from two LSM6DS33 register */
int16_t c6dofimu_getAxis( uint8_t adrRegLow )
{
    uint16_t result;
    uint8_t buffer[2];

    buffer[0] = c6dofimu_readData( adrRegLow + 1 );
    buffer[1] = c6dofimu_readData( adrRegLow );

    result = buffer[0];
    result <<= 8;
    result |= buffer[1];

    return result;
}

/* Function read Gyro X-axis, Y-axis and Z-axis axis */
void c6dofimu_readGyro( int16_t *gyroX, int16_t *gyroY, int16_t *gyroZ )
{
    *gyroX = c6dofimu_getAxis( _C6DOFIMU_OUTX_L_G );
    *gyroY = c6dofimu_getAxis( _C6DOFIMU_OUTY_L_G );
    *gyroZ = c6dofimu_getAxis( _C6DOFIMU_OUTZ_L_G );
}

/* Function read Accel X-axis, Y-axis and Z-axis */
void c6dofimu_readAccel( int16_t *accelX, int16_t *accelY, int16_t *accelZ )
{
    *accelX = c6dofimu_getAxis( _C6DOFIMU_OUTX_L_XL );
    *accelY = c6dofimu_getAxis( _C6DOFIMU_OUTY_L_XL );
    *accelZ = c6dofimu_getAxis( _C6DOFIMU_OUTZ_L_XL );
}

/* Function read temperature data */
float c6dofimu_readTemperature()
{
    int16_t result;
    float temperature;
    temperature = 0.000;

    result = c6dofimu_getAxis( _C6DOFIMU_OUT_TEMP_L );

    temperature =  ( float ) result;
    temperature = ( temperature * 0.065 ) + 25.000;

    return temperature;
}



/* -------------------------------------------------------------------------- */
/*
  __c6dofimu_driver.c

  Copyright (c) 2017, MikroElektonika - http://www.mikroe.com

  All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright
   notice, this list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright
   notice, this list of conditions and the following disclaimer in the
   documentation and/or other materials provided with the distribution.

3. All advertising materials mentioning features or use of this software
   must display the following acknowledgement:
   This product includes software developed by the MikroElektonika.

4. Neither the name of the MikroElektonika nor the
   names of its contributors may be used to endorse or promote products
   derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY MIKROELEKTRONIKA ''AS IS'' AND ANY
EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL MIKROELEKTRONIKA BE LIABLE FOR ANY
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

----------------------------------------------------------------------------- */