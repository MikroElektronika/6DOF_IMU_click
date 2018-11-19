/*
    __c6dofimu_driver.h

-----------------------------------------------------------------------------

  This file is part of mikroSDK.
  
  Copyright (c) 2017, MikroElektonika - http://www.mikroe.com

  All rights reserved.

----------------------------------------------------------------------------- */

/**
@file   __c6dofimu_driver.h
@brief    6DOF_IMU Driver
@mainpage 6DOF_IMU Click
@{

@image html libstock_fb_view.jpg

@}

@defgroup   C6DOFIMU
@brief      6DOF_IMU Click Driver
@{

| Global Library Prefix | **C6DOFIMU** |
|:---------------------:|:-----------------:|
| Version               | **1.0.0**    |
| Date                  | **Aug 2018.**      |
| Developer             | **Nenad Filipovic**     |

*/
/* -------------------------------------------------------------------------- */

#include "stdint.h"

#ifndef _C6DOFIMU_H_
#define _C6DOFIMU_H_

/** 
 * @macro T_C6DOFIMU_P
 * @brief Driver Abstract type 
 */
#define T_C6DOFIMU_P    const uint8_t*

/** @defgroup C6DOFIMU_COMPILE Compilation Config */              /** @{ */

//  #define   __C6DOFIMU_DRV_SPI__                            /**<     @macro __C6DOFIMU_DRV_SPI__  @brief SPI driver selector */
   #define   __C6DOFIMU_DRV_I2C__                            /**<     @macro __C6DOFIMU_DRV_I2C__  @brief I2C driver selector */                                          
// #define   __C6DOFIMU_DRV_UART__                           /**<     @macro __C6DOFIMU_DRV_UART__ @brief UART driver selector */ 

                                                                       /** @} */
/** @defgroup C6DOFIMU_VAR Variables */                           /** @{ */

// REGISTER
extern const uint8_t    _C6DOFIMU_FUNC_CFG_ACCESS;
extern const uint8_t    _C6DOFIMU_FIFO_CTRL1;
extern const uint8_t    _C6DOFIMU_FIFO_CTRL2;
extern const uint8_t    _C6DOFIMU_FIFO_CTRL3;
extern const uint8_t    _C6DOFIMU_FIFO_CTRL40x09;
extern const uint8_t    _C6DOFIMU_FIFO_CTRL50x0A;
extern const uint8_t    _C6DOFIMU_ORIENT_CFG_G;
extern const uint8_t    _C6DOFIMU_INT1_CTRL;
extern const uint8_t    _C6DOFIMU_INT2_CTRL;
extern const uint8_t    _C6DOFIMU_WHO_AM_I;
extern const uint8_t    _C6DOFIMU_CTRL1_XL;
extern const uint8_t    _C6DOFIMU_CTRL2_G;
extern const uint8_t    _C6DOFIMU_CTRL3_C;
extern const uint8_t    _C6DOFIMU_CTRL4_C;
extern const uint8_t    _C6DOFIMU_CTRL5_C;
extern const uint8_t    _C6DOFIMU_CTRL6_C;
extern const uint8_t    _C6DOFIMU_CTRL7_G;
extern const uint8_t    _C6DOFIMU_CTRL8_XL;
extern const uint8_t    _C6DOFIMU_CTRL9_XL;
extern const uint8_t    _C6DOFIMU_CTRL10_C;
extern const uint8_t    _C6DOFIMU_WAKE_UP_SRC;
extern const uint8_t    _C6DOFIMU_TAP_SRC;
extern const uint8_t    _C6DOFIMU_D6D_SRC;
extern const uint8_t    _C6DOFIMU_STATUS_REG0x1E;
extern const uint8_t    _C6DOFIMU_FIFO_STATUS1;
extern const uint8_t    _C6DOFIMU_FIFO_STATUS2;
extern const uint8_t    _C6DOFIMU_FIFO_STATUS3;
extern const uint8_t    _C6DOFIMU_FIFO_STATUS4;
extern const uint8_t    _C6DOFIMU_FIFO_DATA_OUT_L;
extern const uint8_t    _C6DOFIMU_FIFO_DATA_OUT_H;
extern const uint8_t    _C6DOFIMU_TIMESTAMP0_REG;
extern const uint8_t    _C6DOFIMU_TIMESTAMP1_REG;
extern const uint8_t    _C6DOFIMU_TIMESTAMP2_REG;
extern const uint8_t    _C6DOFIMU_STEP_TIMESTAMP_L;
extern const uint8_t    _C6DOFIMU_STEP_TIMESTAMP_H;
extern const uint8_t    _C6DOFIMU_STEP_COUNTER_L;
extern const uint8_t    _C6DOFIMU_STEP_COUNTER_H;
extern const uint8_t    _C6DOFIMU_FUNC_SRC;
extern const uint8_t    _C6DOFIMU_TAP_CFG;
extern const uint8_t    _C6DOFIMU_D6D_SRC;
extern const uint8_t    _C6DOFIMU_INT_DUR2;
extern const uint8_t    _C6DOFIMU_WAKE_UP_THS;
extern const uint8_t    _C6DOFIMU_WAKE_UP_DUR;
extern const uint8_t    _C6DOFIMU_FREE_FALL;
extern const uint8_t    _C6DOFIMU_MD1_CFG;
extern const uint8_t    _C6DOFIMU_MD2_CFG;
// OUTPUT REGISTER
// TEMP
extern const uint8_t    _C6DOFIMU_OUT_TEMP_L;
extern const uint8_t    _C6DOFIMU_OUT_TEMP_H;
// GYRO
extern const uint8_t    _C6DOFIMU_OUTX_L_G;
extern const uint8_t    _C6DOFIMU_OUTX_H_G;
extern const uint8_t    _C6DOFIMU_OUTY_L_G;
extern const uint8_t    _C6DOFIMU_OUTY_H_G;
extern const uint8_t    _C6DOFIMU_OUTZ_L_G;
extern const uint8_t    _C6DOFIMU_OUTZ_H_G;
// ACCEL
extern const uint8_t    _C6DOFIMU_OUTX_L_XL;
extern const uint8_t    _C6DOFIMU_OUTX_H_XL;
extern const uint8_t    _C6DOFIMU_OUTY_L_XL;
extern const uint8_t    _C6DOFIMU_OUTY_H_XL;
extern const uint8_t    _C6DOFIMU_OUTZ_L_XL;
extern const uint8_t    _C6DOFIMU_OUTZ_H_XL;

// ADDRESS
extern const uint8_t    _C6DOFIMU_I2C_ADDR;

// REGISTER CONFIG
extern const uint8_t    _C6DOFIMU_CTRL12_CONFIG;
extern const uint8_t    _C6DOFIMU_CTRL3_C_CONFIG;

                                                                       /** @} */
/** @defgroup C6DOFIMU_TYPES Types */                             /** @{ */



                                                                       /** @} */
#ifdef __cplusplus
extern "C"{
#endif

/** @defgroup C6DOFIMU_INIT Driver Initialization */              /** @{ */

#ifdef   __C6DOFIMU_DRV_SPI__
void c6dofimu_spiDriverInit(T_C6DOFIMU_P gpioObj, T_C6DOFIMU_P spiObj);
#endif
#ifdef   __C6DOFIMU_DRV_I2C__
void c6dofimu_i2cDriverInit(T_C6DOFIMU_P gpioObj, T_C6DOFIMU_P i2cObj, uint8_t slave);
#endif
#ifdef   __C6DOFIMU_DRV_UART__
void c6dofimu_uartDriverInit(T_C6DOFIMU_P gpioObj, T_C6DOFIMU_P uartObj);
#endif


/** @defgroup C6DOFIMU_FUNC Driver Functions */                   /** @{ */


/**
 * @brief Generic write data function
 *
 * @param[in] address         Register address
 *
 * @param[in] writeCommand    Command to write
 *
 * Function write byte of data to LSM6DS33
 */
void c6dofimu_writeData( uint8_t address, uint8_t writeCommand );

/**
 * @brief Generic read data function
 *
 * @param[in] address         Register address
 *
 * @return    Data from addressed register in LSM6DS33
 *
 * Function read byte of data from register address of LSM6DS33
 */
uint8_t c6dofimu_readData( uint8_t address );


/**
 * @brief Function get low and high register data
 *
 * @param[in] adrRegLow         low data register address
 *
 * @param[in] adrRegHigh         high data register address
 *
 * @return         16-bit value ( low and high data )
 *
 * Function get data from two LSM6DS33 register
 */
int16_t c6dofimu_getAxis( uint8_t adrRegLow );

/**
 * @brief Function read axis
 *
 * @param[out] gyroX             pointer to read Gyro X-axis data
 * @param[out] gyroY             pointer to read Gyro Y-axis data
 * @param[out] gyroZ             pointer to read Gyro Z-axis data
 *
 * Function read Gyro X-axis, Y-axis and Z-axis axis.
 *
 */
void c6dofimu_readGyro( int16_t *gyroX, int16_t *gyroY, int16_t *gyroZ );

/**
 * @brief Function read axis
 *
 * @param[out] gyroX             pointer to read Accel X-axis data
 * @param[out] gyroY             pointer to read Accel Y-axis data
 * @param[out] gyroZ             pointer to read Accel Z-axis data
 *
 * Function read Accel X-axis, Y-axis and Z-axis axis.
 *
 */
void c6dofimu_readAccel( int16_t *accelX, int16_t *accelY, int16_t *accelZ );

/**
 * @brief Function read temperature data in degrees [ °C ]
 *
 * @return         temperature in degrees [ °C ]
 *
 * Function read temperature data
 */
float c6dofimu_readTemperature();




                                                                       /** @} */
#ifdef __cplusplus
} // extern "C"
#endif
#endif

/**
    @example Click_6DOF_IMU_STM.c
    @example Click_6DOF_IMU_TIVA.c
    @example Click_6DOF_IMU_CEC.c
    @example Click_6DOF_IMU_KINETIS.c
    @example Click_6DOF_IMU_MSP.c
    @example Click_6DOF_IMU_PIC.c
    @example Click_6DOF_IMU_PIC32.c
    @example Click_6DOF_IMU_DSPIC.c
    @example Click_6DOF_IMU_AVR.c
    @example Click_6DOF_IMU_FT90x.c
    @example Click_6DOF_IMU_STM.mbas
    @example Click_6DOF_IMU_TIVA.mbas
    @example Click_6DOF_IMU_CEC.mbas
    @example Click_6DOF_IMU_KINETIS.mbas
    @example Click_6DOF_IMU_MSP.mbas
    @example Click_6DOF_IMU_PIC.mbas
    @example Click_6DOF_IMU_PIC32.mbas
    @example Click_6DOF_IMU_DSPIC.mbas
    @example Click_6DOF_IMU_AVR.mbas
    @example Click_6DOF_IMU_FT90x.mbas
    @example Click_6DOF_IMU_STM.mpas
    @example Click_6DOF_IMU_TIVA.mpas
    @example Click_6DOF_IMU_CEC.mpas
    @example Click_6DOF_IMU_KINETIS.mpas
    @example Click_6DOF_IMU_MSP.mpas
    @example Click_6DOF_IMU_PIC.mpas
    @example Click_6DOF_IMU_PIC32.mpas
    @example Click_6DOF_IMU_DSPIC.mpas
    @example Click_6DOF_IMU_AVR.mpas
    @example Click_6DOF_IMU_FT90x.mpas
*/                                                                     /** @} */
/* -------------------------------------------------------------------------- */
/*
  __c6dofimu_driver.h

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