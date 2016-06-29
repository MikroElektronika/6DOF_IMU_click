/*******************************************************************************
* Title                 :   System Initialization
* Filename              :   sys_init.c
* Author                :   JWB
* Origin Date           :   04/23/2012
* Notes                 :   None
*******************************************************************************/
/*************** MODULE REVISION LOG ******************************************
*
*    Date    Software Version    Initials   Description
*  XX/XX/XX    XXXXXXXXXXX         JWB      Module Created.
*
*******************************************************************************/
/** @file XXX.c
 *  @brief This module contains the
 */
/******************************************************************************
* Includes
*******************************************************************************/
#include <stdint.h>
#include "6dof_hw.h"
#include "6dof_hal.h"
/******************************************************************************
* Module Preprocessor Constants
*******************************************************************************/

/******************************************************************************
* Module Preprocessor Macros
*******************************************************************************/

/******************************************************************************
* Module Typedefs
*******************************************************************************/

/******************************************************************************
* Module Variable Definitions
*******************************************************************************/

/******************************************************************************
* Function Prototypes
*******************************************************************************/

/******************************************************************************
* Function Definitions
*******************************************************************************/

int8_t dof6_init ( uint8_t address )
{
    uint8_t temp;
    dof6_hal_init ( address );
    dof6_hal_read ( 0x12, &temp, 1 );
    if ( (temp & (1 << 2)) == 0 )
    {
        temp |= (1 << 2);
        dof6_hal_write(0x12, &temp, 1);
    }
    dof6_hal_read(0x0F, &temp, 1);
    if (temp != 0x69) return -1;

    return 0;
}

void dof6_embedded_functions_access_enable(bool set)
{
    uint8_t temp;
    dof6_hal_read(FUNC_CFG_ACCESS, &temp, 1);
    switch (set)
    {
    case true:
        temp |= (1 << 7);
        dof6_hal_write(FUNC_CFG_ACCESS, &temp, 1);
        break;
    case false:
        temp &= (1 << 7);
        dof6_hal_write(FUNC_CFG_ACCESS, &temp, 1);
        break;
    }
}

void dof6_embedded_functions_enable(bool set)
{
    uint8_t temp;
    dof6_hal_read(CTRL10_C, &temp, 1);
    switch (set)
    {
    case true:
        temp |= (1 << 2);
        dof6_hal_write(CTRL10_C, &temp, 1);
        break;
    case false:
        temp &= (1 << 2);
        dof6_hal_write(CTRL10_C, &temp, 1);
        break;
    }
}


int8_t dof6_fifo_set_threshold_level(uint16_t threshold_level)
{
    uint8_t temp, temp1;
    if (threshold_level > 0x0FFFF) return -1;
    temp1 = threshold_level & 0x0F00;
    temp = (threshold_level & 0x0F00) >> 8;
    dof6_hal_write(FIFO_CTRL1, &temp1, 1);
    dof6_hal_write(FIFO_CTRL2, &temp, 1);
    return 0;
}

void dof6_fifo_pedometer_timestamp_enable(bool set)
{
    uint8_t temp;
    dof6_hal_read(FIFO_CTRL2, &temp, 1);
    if (set == true)
    {
        temp |= (1 << 7);
        dof6_hal_write (FIFO_CTRL2, &temp, 1);
    }
    else if (set == false)
    {
        temp &= (1 << 7);
        dof6_hal_write (FIFO_CTRL2, &temp, 1);
    }
}

void dof6_fifo_set_write_enable(bool set)
{
    uint8_t temp;
    dof6_hal_read(FIFO_CTRL2, &temp, 1);
    if (set == true)
    {
        temp |= (1 << 6);
        dof6_hal_write (FIFO_CTRL2, &temp, 1);
    }
    else if (set == false)
    {
        temp &= (1 << 6);
        dof6_hal_write (FIFO_CTRL2, &temp, 1);
    }
}

int8_t dof6_fifo_set_gyro_decimation(uint8_t set)
{
    uint8_t temp;
    int8_t status = 0;
    dof6_hal_read (FIFO_CTRL3, &temp, 1);
    switch (set)
    {
    case 0:
        temp &= ~(7 << 3);
        dof6_hal_write (FIFO_CTRL3, &temp, 1);
        break;
    case 1:
        temp &= ~(7 << 3);
        temp |= (1 << 3);
        dof6_hal_write (FIFO_CTRL3, &temp, 1);
        break;
    case 2:
        temp &= ~(7 << 3);
        temp |= (2 << 3);
        dof6_hal_write (FIFO_CTRL3, &temp, 1);
        break;
    case 3:
        temp &= ~(7 << 3);
        temp |= (3 << 3);
        dof6_hal_write (FIFO_CTRL3, &temp, 1);
        break;
    case 4:
        temp &= ~(7 << 3);
        temp |= (4 << 3);
        dof6_hal_write (FIFO_CTRL3, &temp, 1);
        break;
    case 8:
        temp &= ~(7 << 3);
        temp |= (5 << 3);
        dof6_hal_write (FIFO_CTRL3, &temp, 1);
        break;
    case 16:
        temp &= ~(7 << 3);
        temp |= (6 << 3);
        dof6_hal_write (FIFO_CTRL3, &temp, 1);
        break;
    case 32:
        temp |= (7 << 3);
        dof6_hal_write (FIFO_CTRL3, &temp, 1);
        break;
    default:
        status = -1;
        break;
    }
    return status;
}

int8_t dof6_fifo_set_accel_dcimation (uint8_t set)
{
    uint8_t temp;
    int8_t status = 0;
    dof6_hal_read (FIFO_CTRL3, &temp, 1);
    switch (set)
    {
    case 0:
        temp &= ~(7);
        dof6_hal_write (FIFO_CTRL3, &temp, 1);
        break;
    case 1:
        temp &= ~(7);
        temp |= (1);
        dof6_hal_write (FIFO_CTRL3, &temp, 1);
        break;
    case 2:
        temp &= ~(7);
        temp |= (2);
        dof6_hal_write (FIFO_CTRL3, &temp, 1);
        break;
    case 3:
        temp &= ~(7);
        temp |= (3);
        dof6_hal_write (FIFO_CTRL3, &temp, 1);
        break;
    case 4:
        temp &= ~(7);
        temp |= (4);
        dof6_hal_write (FIFO_CTRL3, &temp, 1);
        return 0;
        break;
    case 8:
        temp &= ~(7);
        temp |= (5);
        dof6_hal_write (FIFO_CTRL3, &temp, 1);
        break;
    case 16:
        temp &= ~(7);
        temp |= (6);
        dof6_hal_write (FIFO_CTRL3, &temp, 1);
        break;
    case 32:
        temp |= (7);
        dof6_hal_write (FIFO_CTRL3, &temp, 1);
        break;
    default:
        status = -1;
        break;
    }
    return status;
}

void dof6_fifo_8bit_enable(bool set)
{
    uint8_t temp;
    dof6_hal_read (FIFO_CTRL4, &temp, 1);
    if (set == true)
    {
        temp |= (1 << 6);
        dof6_hal_write (FIFO_CTRL4, &temp, 1);
    }
    else if (set == false)
    {
        temp &= ~(1 << 6);
        dof6_hal_write (FIFO_CTRL4, &temp, 1);
    }
}

int8_t dof6_fifo_set_third_data_decimation(uint8_t set)
{
    uint8_t temp;
    int8_t status = 0;
    dof6_hal_read (FIFO_CTRL4, &temp, 1);
    switch (set)
    {
    case 0:
        temp &= ~(7 << 3);
        dof6_hal_write (FIFO_CTRL4, &temp, 1);
        break;
    case 1:
        temp &= ~(7 << 3);
        temp |= (1 << 3);
        dof6_hal_write (FIFO_CTRL4, &temp, 1);
        break;
    case 2:
        temp &= ~(7 << 3);
        temp |= (2 << 3);
        dof6_hal_write (FIFO_CTRL4, &temp, 1);
        break;
    case 3:
        temp &= ~(7 << 3);
        temp |= (3 << 3);
        dof6_hal_write (FIFO_CTRL4, &temp, 1);
        break;
    case 4:
        temp &= ~(7 << 3);
        temp |= (4 << 3);
        dof6_hal_write (FIFO_CTRL4, &temp, 1);
        break;
    case 8:
        temp &= ~(7 << 3);
        temp |= (5 << 3);
        dof6_hal_write (FIFO_CTRL4, &temp, 1);
        break;
    case 16:
        temp &= ~(7 << 3);
        temp |= (6 << 3);
        dof6_hal_write (FIFO_CTRL4, &temp, 1);
        break;
    case 32:
        temp |= (7 << 3);
        dof6_hal_write (FIFO_CTRL4, &temp, 1);
        break;
    default:
        status = -1;
        break;
    }
    return status;
}

int8_t dof6_fifo_set_output_data_rate(odr_t odr)
{
    uint8_t temp;
    int8_t status = 0;
    dof6_hal_read (FIFO_CTRL5, &temp, 1);
    switch (odr)
    {
    case POWER_DOWN:
        temp &= ~(15 << 3);
        dof6_hal_write (FIFO_CTRL5, &temp, 1);
        break;
    case HZ_13:
        temp &= ~(15 << 3);
        temp |= (1 << 3);
        dof6_hal_write (FIFO_CTRL5, &temp, 1);
        break;
    case HZ_26:
        temp &= ~(15 << 3);
        temp |= (2 << 3);
        dof6_hal_write (FIFO_CTRL5, &temp, 1);
        break;
    case HZ_52:
        temp &= ~(15 << 3);
        temp |= (3 << 3);
        dof6_hal_write (FIFO_CTRL5, &temp, 1);
        break;
    case HZ_104:
        temp &= ~(15 << 3);
        temp |= (4 << 3);
        dof6_hal_write (FIFO_CTRL5, &temp, 1);
        break;
    case HZ_208:
        temp &= ~(15 << 3);
        temp |= (5 << 3);
        dof6_hal_write (FIFO_CTRL5, &temp, 1);
        break;
    case HZ_416:
        temp &= ~(15 << 3);
        temp |= (6 << 3);
        dof6_hal_write (FIFO_CTRL5, &temp, 1);
        break;
    case HZ_833:
        temp &= ~(15 << 3);
        temp |= (7 << 3);
        dof6_hal_write (FIFO_CTRL5, &temp, 1);
        break;
    case KHZ_1_6:
        temp &= ~(15 << 3);
        temp |= (8 << 3);
        dof6_hal_write (FIFO_CTRL5, &temp, 1);
        break;
    case KHZ_3_3:
        temp &= ~(15 << 3);
        temp |= (9 << 3);
        dof6_hal_write (FIFO_CTRL5, &temp, 1);
        break;
    case KHZ_6_6:
        temp &= ~(15 << 3);
        temp |= (10 << 3);
        dof6_hal_write (FIFO_CTRL5, &temp, 1);
        break;
    default:
        status = -1;
        break;
    }
    return status;
}



int8_t dof6_fifo_set_mode(fifo_mode_t mode)
{
    uint8_t temp;
    int8_t status = 0;
    dof6_hal_read (FIFO_CTRL5, &temp, 1);
    switch (mode)
    {
    case FIFO_BYPASS_MODE:
        temp &= ~(7);
        dof6_hal_write (FIFO_CTRL5, &temp, 1);
        break;
    case FIFO_FULL_MODE:
        temp &= ~(7);
        temp |= 1;
        dof6_hal_write (FIFO_CTRL5, &temp, 1);
        break;
    case CONTINOUS_TO_FIFO:
        temp &= ~(7);
        temp |= 3;
        dof6_hal_write (FIFO_CTRL5, &temp, 1);
        break;
    case BYPASS_TO_CONTINOUS:
        temp &= ~(7);
        temp |= 4;
        dof6_hal_write (FIFO_CTRL5, &temp, 1);
        break;
    case CONTINOUS:
        temp &= ~(7);
        temp |= 6;
        dof6_hal_write (FIFO_CTRL5, &temp, 1);
        break;
    default:
        status = -1;
        break;
    }
    return status;
}

int8_t dof6_gyro_set_sign_x(gyro_sign_t sign)
{
    uint8_t temp;
    int8_t status = 0;
    dof6_hal_read (ORIENT_CFG_G, &temp, 1);
    switch (sign)
    {
    case POSITIVE:
        temp &= ~(1 << 5);
        dof6_hal_write (ORIENT_CFG_G, &temp, 1);
        break;
    case NEGATIVE:
        temp |= (1 << 5);
        dof6_hal_write (ORIENT_CFG_G, &temp, 1);
        break;
    default:
        status = -1;
        break;
    }
    return status;
}

int8_t dof6_gyro_set_sign_y(gyro_sign_t sign)
{
    uint8_t temp;
    int8_t status = 0;
    dof6_hal_read (ORIENT_CFG_G, &temp, 1);
    switch (sign)
    {
    case POSITIVE:
        temp &= ~(1 << 4);
        dof6_hal_write (ORIENT_CFG_G, &temp, 1);
        break;
    case NEGATIVE:
        temp |= (1 << 4);
        dof6_hal_write (ORIENT_CFG_G, &temp, 1);
        break;
    default:
        status = -1;
        break;
    }
    return status;
}

int8_t dof6_gyro_set_sign_z(gyro_sign_t sign)
{
    uint8_t temp;
    int8_t status = 0;
    dof6_hal_read (ORIENT_CFG_G, &temp, 1);
    switch (sign) {
    case POSITIVE:
        temp &= ~(1 << 3);
        dof6_hal_write (ORIENT_CFG_G, &temp, 1);
        break;
    case NEGATIVE:
        temp |= (1 << 3);
        dof6_hal_write (ORIENT_CFG_G, &temp, 1);
        break;
    default:
        status = -1;
        break;
    }
    return status;
}

int8_t dof6_gyro_set_directional_oritentation(orientation_t orientation)
{
    uint8_t temp;
    int8_t status = 0;
    dof6_hal_read (ORIENT_CFG_G, &temp, 1);
    switch (orientation)
    {
    case X_Y_Z:
        temp &= ~(7);
        dof6_hal_write (ORIENT_CFG_G, &temp, 1);
        break;
    case X_Z_Y:
        temp &= ~(7);
        temp |= 1;
        dof6_hal_write (ORIENT_CFG_G, &temp, 1);
        break;
    case Y_X_Z:
        temp &= ~(7);
        temp |= 2;
        dof6_hal_write (ORIENT_CFG_G, &temp, 1);
        break;
    case Y_Z_X:
        temp &= ~(7);
        temp |= 3;
        dof6_hal_write (ORIENT_CFG_G, &temp, 1);
        break;
    case Z_X_Y:
        temp &= ~(7);
        temp |= 4;
        dof6_hal_write (ORIENT_CFG_G, &temp, 1);
        break;
    case Z_Y_X:
        temp &= ~(7);
        temp |= 5;
        dof6_hal_write (ORIENT_CFG_G, &temp, 1);
        break;
    default:
        status = -1;
        break;
    }
    return status;
}

void dof6_int1_configure(interrupt1_config_t interrupt1)
{
    uint8_t temp = 0;

    if (interrupt1.step_detector == 0) temp |= (1 << 7);
    if (interrupt1.sign_motion == 0) temp |= (1 << 6);
    if (interrupt1.fifo_full == 0) temp |= (1 << 5);
    if (interrupt1.fifo_ovr == 0) temp |= (1 << 4);
    if (interrupt1.fifo_thrs == 0) temp |= (1 << 3);
    if (interrupt1.boot == 0) temp |= (1 << 2);
    if (interrupt1.gyro_drdy == 0) temp |= (1 << 1);
    if (interrupt1.accel_drdy == 0) temp |= (1);
    dof6_hal_write (INT1_CTRL, &temp, 1);
}

void dof6_int2_configure(interrupt2_config_t interrupt2)
{
    uint8_t temp;

    if (interrupt2.step_delta == 0) temp |= (1 << 7);
    if (interrupt2.step_count_ovr == 0) temp |= (1 << 6);
    if (interrupt2.fifo_full2 == 0) temp |= (1 << 5);
    if (interrupt2.fifo_ovr2 == 0) temp |= (1 << 4);
    if (interrupt2.fifo_thrs2 == 0) temp |= (1 << 3);
    if (interrupt2.temp_drdy == 0) temp |= (1 << 2);
    if (interrupt2.gyro_drdy2 == 0) temp |= (1 << 1);
    if (interrupt2.accel_drdy2 == 0) temp |= (1);
    dof6_hal_write (INT2_CTRL, &temp, 1);
}

int8_t dof6_accel_set_output_data_rate (odr_t data_rate)
{
    uint8_t temp;
    int8_t status = 0;
    dof6_hal_read (CTRL1_XL, &temp, 1);
    switch (data_rate)
    {
    case POWER_DOWN:
        temp &= ~(15 << 4);
        dof6_hal_write (CTRL1_XL, &temp, 1);
        break;
    case HZ_13:
        temp &= ~(15 << 4);
        temp |= (1 << 4);
        dof6_hal_write (CTRL1_XL, &temp, 1);
        break;
    case HZ_26:
        temp &= ~(15 << 4);
        temp |= (2 << 4);
        dof6_hal_write (CTRL1_XL, &temp, 1);
        break;
    case HZ_52:
        temp &= ~(15 << 4);
        temp |= (3 << 4);
        dof6_hal_write (CTRL1_XL, &temp, 1);
        break;
    case HZ_104:
        temp &= ~(15 << 4);
        temp |= (4 << 4);
        dof6_hal_write (CTRL1_XL, &temp, 1);
        break;
    case HZ_208:
        temp &= ~(15 << 4);
        temp |= (5 << 4);
        dof6_hal_write (CTRL1_XL, &temp, 1);
        break;
    case HZ_416:
        temp &= ~(15 << 4);
        temp |= (6 << 4);
        dof6_hal_write (CTRL1_XL, &temp, 1);
        break;
    case HZ_833:
        temp &= ~(15 << 4);
        temp |= (7 << 4);
        dof6_hal_write (CTRL1_XL, &temp, 1);
        break;
    case KHZ_1_6:
        temp &= ~(15 << 4);
        temp |= (8 << 4);
        dof6_hal_write (CTRL1_XL, &temp, 1);
        break;
    case KHZ_3_3:
        temp &= ~(15 << 4);
        temp |= (9 << 4);
        dof6_hal_write (CTRL1_XL, &temp, 1);
        break;
    case KHZ_6_6:
        temp &= ~(15 << 4);
        temp |= (10 << 4);
        dof6_hal_write (CTRL1_XL, &temp, 1);
        break;
    default:
        status = -1;
        break;
    }
    return status;
}

odr_t dof6_accel_get_output_data_rate()
{
    uint8_t temp;
    dof6_hal_read (CTRL1_XL, &temp, 1);
    temp = temp >> 4;
    return temp;
}

int8_t dof6_accel_set_range (acl_range_t range)
{
    uint8_t temp;
    int8_t status = 0;
    dof6_hal_read(CTRL1_XL, &temp, 1);

    switch (range)
    {
    case ACL_RANGE_2G:
        temp &= ~(3 << 2);
        dof6_hal_write(CTRL1_XL, &temp, 1);
        break;
    case ACL_RANGE_16G:
        temp &= ~(3 << 2);
        temp |= 1;
        dof6_hal_write(CTRL1_XL, &temp, 1);
        break;
    case ACL_RANGE_4G:
        temp &= ~(3 << 2);
        temp |= (1 << 1);
        dof6_hal_write(CTRL1_XL, &temp, 1);
        break;
    case ACL_RANGE_8G:
        temp |= (3 << 2);
        dof6_hal_write(CTRL1_XL, &temp, 1);
        break;
    default:
        status = -1;
        break;
    }
    return status;
}

acl_range_t dof6_accel_get_range()
{
    uint8_t temp;
    dof6_hal_read(CTRL1_XL, &temp, 1);

    return ((temp & 0b00001100) >> 2);
}

int8_t dof6_accel_set_filter_bandwith (filter_bandwith_t bandwith)
{
    uint8_t temp;
    int8_t status = 0;
    dof6_hal_read(CTRL1_XL, &temp, 1);

    switch (bandwith)
    {
    case HZ_400:
        temp &= ~(3);
        dof6_hal_write(CTRL1_XL, &temp, 1);
        break;
    case HZ_200:
        temp &= ~(3);
        temp |= 1;
        dof6_hal_write(CTRL1_XL, &temp, 1);
        break;
    case HZ_100:
        temp &= ~(3);
        temp |= (1 << 1);
        dof6_hal_write(CTRL1_XL, &temp, 1);
        break;
    case HZ_50:
        temp |= 3;
        dof6_hal_write(CTRL1_XL, &temp, 1);
        break;
    default:
        status = -1;
        break;
    }
    return status;
}

filter_bandwith_t dof6_accel_get_filter_bandwith()
{
    uint8_t temp;
    dof6_hal_read(CTRL1_XL, &temp, 1);
    temp &= ~(0b11111100);
    return temp;
}

int8_t dof6_gyro_set_output_data_rate ( odr_t data_rate )
{
    uint8_t temp;
    int8_t status = 0;
    dof6_hal_read(CTRL2_G, &temp, 1);

    switch (data_rate)
    {
    case POWER_DOWN:
        temp &= ~(15 << 4);
        dof6_hal_write(CTRL2_G, &temp, 1);
        break;
    case HZ_13:
        temp &= ~(15 << 4);
        temp |= 1 << 4;
        dof6_hal_write(CTRL2_G, &temp, 1);
        break;
    case HZ_26:
        temp &= ~(15 << 4);
        temp |= 2 << 4;
        dof6_hal_write(CTRL2_G, &temp, 1);
        break;
    case HZ_52:
        temp &= ~(15 << 4);
        temp |= 3 << 4;
        dof6_hal_write(CTRL2_G, &temp, 1);
        break;
    case HZ_104:
        temp &= ~(15 << 4);
        temp |= 4 << 4;
        dof6_hal_write(CTRL2_G, &temp, 1);
        break;
    case HZ_208:
        temp &= ~(15 << 4);
        temp |= 5 << 4;
        dof6_hal_write(CTRL2_G, &temp, 1);
        break;
    case HZ_416:
        temp &= ~(15 << 4);
        temp |= 6 << 4;
        dof6_hal_write(CTRL2_G, &temp, 1);
        break;
    case HZ_833:
        temp &= ~(15 << 4);
        temp |= 7 << 4;
        dof6_hal_write(CTRL2_G, &temp, 1);
        break;
    case KHZ_1_6:
        temp &= ~(15 << 4);
        temp |= 8 << 4;
        dof6_hal_write(CTRL2_G, &temp, 1);
        break;
    default:
        status = -1;
    }
    return status;
}

odr_t dof6_gyro_get_output_data_rate ()
{
    uint8_t temp;
    dof6_hal_read(CTRL2_G, &temp, 1);

    return (temp >> 4);
}

int8_t dof6_gyro_set_range(gyro_range_t range)
{
    uint8_t temp;
    int8_t status = 0;
    dof6_hal_read(CTRL2_G, &temp, 1);

    switch (range)
    {
    case DPS_245:
        temp &= ~(3 << 2);
        dof6_hal_write(CTRL2_G, &temp, 1);
        break;
    case DPS_500:
        temp &= ~(3 << 2);
        temp |= (1 << 2);
        dof6_hal_write(CTRL2_G, &temp, 1);
        break;
    case DPS_1000:
        temp &= ~(3 << 2);
        temp |= (1 << 3);
        dof6_hal_write(CTRL2_G, &temp, 1);
        break;
    case DPS_2000:
        temp |= (3 << 2);
        dof6_hal_write(CTRL2_G, &temp, 1);
        break;
    case DPS_125:
        temp |= (1 << 1);
        temp &= ~(3 << 2);
        dof6_hal_write(CTRL2_G, &temp, 1);
        break;
    default:
        status = -1;
    }
    return status;
}

gyro_range_t dof6_gyro_get_range()
{
    uint8_t temp;
    dof6_hal_read(CTRL2_G, &temp, 1);

    if (temp >= 2) return DPS_125;
    else temp  &= ~(0b11110000);
    return (temp >> 1);
}

void dof6_reboot_enable(bool set)
{
    uint8_t temp;
    dof6_hal_read(CTRL3_C, &temp, 1);

    switch (set)
    {
    case true:
        temp |= (1 << 7);
        dof6_hal_write(CTRL3_C, &temp, 1);
        break;
    case false:
        temp &= ~(1 << 7);
        dof6_hal_write(CTRL3_C, &temp, 1);
        break;
    }
}


void dof6_continous_data_update_enable(bool update)
{
    uint8_t temp;
    dof6_hal_read(CTRL3_C, &temp, 1);

    switch (update)
    {
    case true:
        temp &= ~(1 << 6);
        dof6_hal_write(CTRL3_C, &temp, 1);
        break;
    case false:
        temp |= (1 << 6);
        dof6_hal_write(CTRL3_C, &temp, 1);
        break;
    }
}

int8_t dof6_set_interrupt_activation_level(level_t level)
{
    uint8_t temp;
    int8_t status = 0;
    dof6_hal_read(CTRL3_C, &temp, 1);

    switch (level)
    {
    case HIGH:
        temp &= ~(1 << 5);
        dof6_hal_write(CTRL3_C, &temp, 1);
        break;
    case LOW:
        temp |= (1 << 5);
        dof6_hal_write(CTRL3_C, &temp, 1);
        break;
    default:
        status = -1;
        break;
    }
    return status;
}



int8_t dof6_set_int_mode(int_mode_t mode)
{
    uint8_t temp;
    int8_t status = 0;
    dof6_hal_read(CTRL3_C, &temp, 1);

    switch (mode)
    {
    case PUSH_PULL:
        temp &= ~(1 << 4);
        dof6_hal_write(CTRL3_C, &temp, 1);
    case OPEN_DRAIN:
        temp |= (1 << 4);
        dof6_hal_write(CTRL3_C, &temp, 1);
    default:
        status = -1;
    }
    return status;
}

void dof6_software_reset()
{
    uint8_t temp;
    dof6_hal_read(CTRL3_C, &temp, 1);

    temp |= 1;
    dof6_hal_write(CTRL3_C, &temp, 1);
}

void dof6_accel_bandwith_selection_enable (bool set)
{
    uint8_t temp;
    dof6_hal_read(CTRL4_C, &temp, 1);

    switch (set)
    {
    case true:
        temp |= (1 << 7);
        dof6_hal_write(CTRL4_C, &temp, 1);
        break;
    case false:
        temp &= ~(1 << 7);
        dof6_hal_write(CTRL4_C, &temp, 1);
        break;
    }
}

void dof6_gyro_sleepmode_enable(bool set)
{
    uint8_t temp;
    dof6_hal_read(CTRL4_C, &temp, 1);

    switch (set)
    {
    case true:
        temp |= (1 << 6);
        dof6_hal_write(CTRL4_C, &temp, 1);
        break;
    case false:
        temp &= ~(1 << 6);
        dof6_hal_write(CTRL4_C, &temp, 1);
        break;
    }
}

void dof6_int2_on_int1_enable(bool set)
{
    uint8_t temp;
    dof6_hal_read(CTRL4_C, &temp, 1);

    switch (set)
    {
    case true:
        temp |= (1 << 5);
        dof6_hal_write(CTRL4_C, &temp, 1);
        break;
    case false:
        temp &= ~(1 << 5);
        dof6_hal_write(CTRL4_C, &temp, 1);
        break;
    }
}

void dof6_fifo_temp_enable(bool set)
{
    uint8_t temp;
    dof6_hal_read(CTRL4_C, &temp, 1);

    switch (set)
    {
    case true:
        temp |= (1 << 4);
        dof6_hal_write(CTRL4_C, &temp, 1);
        break;
    case false:
        temp &= ~(1 << 4);
        dof6_hal_write(CTRL4_C, &temp, 1);
        break;
    }
}

void dof6_da_timer_enable(bool set)
{
    uint8_t temp;
    dof6_hal_read(CTRL4_C, &temp, 1);

    switch (set)
    {
    case true:
        temp |= (1 << 3);
        dof6_hal_write(CTRL4_C, &temp, 1);
        break;
    case false:
        temp &= ~(1 << 3);
        dof6_hal_write(CTRL4_C, &temp, 1);
        break;
    }
}

void dof6_fifo_threshold_level_enable(bool set)
{
    uint8_t temp;
    dof6_hal_read(CTRL4_C, &temp, 1);

    switch (set)
    {
    case true:
        temp |= 1;
        dof6_hal_write(CTRL4_C, &temp, 1);
        break;
    case false:
        temp &= ~(1);
        dof6_hal_write(CTRL4_C, &temp, 1);
        break;
    }
}

int8_t dof6_set_burstmode_rounding(rounding_t rounding)
{
    uint8_t temp;
    int8_t status = 0;
    dof6_hal_read(CTRL5_C, &temp, 1);

    switch (rounding)
    {
    case NO_ROUNDING:
        temp &= ~(7 << 5);
        dof6_hal_write(CTRL5_C, &temp, 1);
        break;
    case ACC_ONLY:
        temp &= ~(7 << 5);
        temp |= (1 << 5);
        dof6_hal_write(CTRL5_C, &temp, 1);
        break;
    case GYRO_ONLY:
        temp &= ~(7 << 5);
        temp |= (1 << 6);
        dof6_hal_write(CTRL5_C, &temp, 1);
        break;
    case GYRO_AND_ACC:
        temp &= ~(7 << 5);
        temp |= (3 << 5);
        dof6_hal_write(CTRL5_C, &temp, 1);
        break;
    default:
        status = -1;
        break;
    }
    return status;
}

int8_t dof6_gyro_set_selftest(selftest_t set)
{
    uint8_t temp;
    int8_t status = 0;
    dof6_hal_read(CTRL5_C, &temp, 1);

    switch (set)
    {
    case NORMAL_MODE:
        temp &= (3 << 2);
        dof6_hal_write(CTRL5_C, &temp, 1);
        break;
    case POS_SIGN:
        temp &= ~(3 << 2);
        temp |= (1 << 2);
        dof6_hal_write(CTRL5_C, &temp, 1);
        break;
    case NEG_SIGN:
        temp &= ~(3 << 2);
        temp |= (3 << 2);
        dof6_hal_write(CTRL5_C, &temp, 1);
        break;
    default:
        status = -1;
        break;
    }
    return status;
}

int8_t dof6_accel_set_selftest(selftest_t set)
{
    uint8_t temp;
    int8_t status = 0;
    dof6_hal_read(CTRL5_C, &temp, 1);

    switch (set)
    {
    case NORMAL_MODE:
        temp &= 3;
        dof6_hal_write(CTRL5_C, &temp, 1);
        break;
    case POS_SIGN:
        temp &= 3;
        temp |= 1;
        dof6_hal_write(CTRL5_C, &temp, 1);
        break;
    case NEG_SIGN:
        temp &= 3;
        temp |= 3;
        dof6_hal_write(CTRL5_C, &temp, 1);
        break;
    default:
        status = -1;
        break;
    }
    return status;
}

void dof6_gyro_data_egde_trigger_enable(bool set)
{
    uint8_t temp;
    dof6_hal_read(CTRL6_C, &temp, 1);

    switch (set)
    {
    case true:
        temp |= (1 << 7);
        dof6_hal_write(CTRL6_C, &temp, 1);
        break;
    case false:
        temp &= ~(1 << 7);
        dof6_hal_write(CTRL6_C, &temp, 1);
        break;
    }
}

void dof6_gyro_data_level_trigger_enable(bool set)
{
    uint8_t temp;
    dof6_hal_read(CTRL6_C, &temp, 1);

    switch (set)
    {
    case true:
        temp |= (1 << 6);
        dof6_hal_write(CTRL6_C, &temp, 1);
        break;
    case false:
        temp &= ~(1 << 6);
        dof6_hal_write(CTRL6_C, &temp, 1);
        break;
    }
}

void dof6_gyro_level_sensitive_latch_enable(bool set)
{
    uint8_t temp;
    dof6_hal_read(CTRL6_C, &temp, 1);

    switch (set)
    {
    case true:
        temp |= (1 << 5);
        dof6_hal_write(CTRL6_C, &temp, 1);
        break;
    case false:
        temp &= ~(1 << 5);
        dof6_hal_write(CTRL6_C, &temp, 1);
        break;
    }
}

void dof6_accel_high_perfomance_operating_mode_enable(bool set)
{
    uint8_t temp;
    dof6_hal_read(CTRL6_C, &temp, 1);

    switch (set)
    {
    case true:
        temp &= ~(1 << 4);
        dof6_hal_write(CTRL6_C, &temp, 1);
        break;
    case false:
        temp |= (1 << 4);
        dof6_hal_write(CTRL6_C, &temp, 1);
        break;
    }
}

void dof6_gyro_high_perfomance_operating_mode_enable(bool set)
{
    uint8_t temp;
    dof6_hal_read(CTRL7_G, &temp, 1);

    switch (set)
    {
    case true:
        temp &= ~(1 << 7);
        dof6_hal_write(CTRL7_G, &temp, 1);
        break;
    case false:
        temp |= (1 << 7);
        dof6_hal_write(CTRL7_G, &temp, 1);
        break;
    }
}

void dof6_gyro_high_pass_filter_enable(bool set)
{
    uint8_t temp;
    dof6_hal_read(CTRL7_G, &temp, 1);

    switch (set)
    {
    case true:
        temp |= (1 << 6);
        dof6_hal_write(CTRL7_G, &temp, 1);
        break;
    case false:
        temp &= ~(1 << 6);
        dof6_hal_write(CTRL7_G, &temp, 1);
        break;
    }
}

void dof6_gyro_hp_filter_reset_enable(bool set)
{
    uint8_t temp;
    dof6_hal_read(CTRL7_G, &temp, 1);

    switch (set)
    {
    case true:
        temp |= (1 << 3);
        dof6_hal_write(CTRL7_G, &temp, 1);
    case false:
        temp &= ~(1 << 3);
        dof6_hal_write(CTRL7_G, &temp, 1);
        break;
    }
}

void dof6_rounding_function_enable ( bool set )
{
    uint8_t temp;
    dof6_hal_read(CTRL7_G, &temp, 1);

    switch (set)
    {
    case true:
        temp |= (1 << 2);
        dof6_hal_write(CTRL7_G, &temp, 1);
        break;
    case false:
        temp &= ~(1 << 2);
        dof6_hal_write(CTRL7_G, &temp, 1);
        break;
    }
}

int8_t dof6_gyro_set_hp_filter_cutoff_freq(hp_cutoff_freq_t set)
{
    uint8_t temp;
    int8_t status = 0;
    dof6_hal_read(CTRL7_G, &temp, 1);

    switch (set)
    {
    case HZ_0_0081:
        temp &= ~(3 << 4);
        dof6_hal_write(CTRL7_G, &temp, 1);
        break;
    case HZ_0_0324:
        temp &= ~(3 << 4);
        temp |= (1 << 4);
        dof6_hal_write(CTRL7_G, &temp, 1);
        break;
    case HZ_2_07:
        temp &= ~(3 << 4);
        temp |= (1 << 5);
        dof6_hal_write(CTRL7_G, &temp, 1);
        break;
    case HZ_16_32:
        temp |= (3 << 4);
        dof6_hal_write(CTRL7_G, &temp, 1);
        break;
    default:
        status = -1;
        break;
    }
    return status;
}

void dof6_accel_low_pass_filter2_enable(bool set)
{
    uint8_t temp;
    dof6_hal_read(CTRL8_XL, &temp, 1);

    switch (set) {
    case true:
        temp |= (1 << 7);
        dof6_hal_write(CTRL8_XL, &temp, 1);
        break;
    case false:
        temp &= ~(1 << 7);
        dof6_hal_write(CTRL8_XL, &temp, 1);
        break;
    }
}


int8_t dof6_accel_slope_and_high_pass_config(slope_hp_config_t configuration)
{
    uint8_t temp;
    int8_t status = 0;
    dof6_hal_read(CTRL8_XL, &temp, 1);

    switch (configuration)
    {
    case ODR_XL_50:
        temp &= ~(3 << 5);
        break;
    case ODR_XL_100:
        temp &= ~(3 << 5);
        temp |= (1 << 5);
        break;
    case ODR_XL_9:
        temp &= ~(3 << 5);
        temp |= (1 << 6);
        break;
    case ODR_XL_400:
        temp |= (3 << 5);
        break;
    default:
        status = -1;
        break;
    }
    return status;
}

void dof6_accel_slope_filter_enable(bool set)
{
    uint8_t temp;
    dof6_hal_read(CTRL8_XL, &temp, 1);

    switch (set)
    {
    case true:
        temp |= (1 << 2);
        dof6_hal_write(CTRL8_XL, &temp, 1);
        break;
    case false:
        temp &= ~(1 << 2);
        dof6_hal_write(CTRL8_XL, &temp, 1);
        break;
    }
}

void dof6_6d_low_pass_enable(bool set)
{
    uint8_t temp;
    dof6_hal_read(CTRL8_XL, &temp, 1);

    switch (set) {
    case true:
        temp |= 1;
        dof6_hal_write(CTRL8_XL, &temp, 1);
        break;
    case false:
        temp &= ~1;
        dof6_hal_write(CTRL8_XL, &temp, 1);
        break;
    }
}

void dof6_accel_z_enable(bool set)
{
    uint8_t temp;
    dof6_hal_read(CTRL9_XL, &temp, 1);
    switch (set)
    {
    case true:
        temp |= (1 << 5);
        dof6_hal_write(CTRL9_XL, &temp, 1);
        break;
    case false:
        temp &= ~(1 << 5);
        dof6_hal_write(CTRL9_XL, &temp, 1);
        break;
    }

}

void dof6_accel_y_enable(bool set)
{
    uint8_t temp;
    dof6_hal_read(CTRL9_XL, &temp, 1);
    switch (set)
    {
    case true:
        temp |= (1 << 4);
        dof6_hal_write(CTRL9_XL, &temp, 1);
        break;
    case false:
        temp &= ~(1 << 4);
        dof6_hal_write(CTRL9_XL, &temp, 1);
        break;
    }
}

void dof6_accel_x_enable(bool set)
{
    uint8_t temp;
    dof6_hal_read(CTRL9_XL, &temp, 1);
    switch (set)
    {
    case true:
        temp |= (1 << 3);
        dof6_hal_write(CTRL9_XL, &temp, 1);
        break;
    case false:
        temp &= ~(1 << 3);
        dof6_hal_write(CTRL9_XL, &temp, 1);
        break;
    }
}

void dof6_gyro_x_enable(bool set)
{
    uint8_t temp;
    dof6_hal_read(CTRL10_C, &temp, 1);
    switch (set)
    {
    case true:
        temp |= (1 << 3);
        dof6_hal_write(CTRL10_C, &temp, 1);
        break;
    case false:
        temp &= ~(1 << 3);
        dof6_hal_write(CTRL10_C, &temp, 1);
        break;
    }
}

void dof6_gyro_y_enable(bool set)
{
    uint8_t temp;
    dof6_hal_read(CTRL10_C, &temp, 1);
    switch (set)
    {
    case true:
        temp |= (1 << 4);
        dof6_hal_write(CTRL10_C, &temp, 1);
        break;
    case false:
        temp &= ~(1 << 4);
        dof6_hal_write(CTRL10_C, &temp, 1);
        break;
    }
}

void dof6_gyro_z_enable(bool set)
{
    uint8_t temp;
    dof6_hal_read(CTRL10_C, &temp, 1);
    switch (set)
    {
    case true:
        temp |= (1 << 5);
        dof6_hal_write(CTRL10_C, &temp, 1);
        break;
    case false:
        temp &= ~(1 << 5);
        dof6_hal_write(CTRL10_C, &temp, 1);
        break;
    }
}

void dof6_reset_pedometer_counter()
{
    uint8_t temp;
    dof6_hal_read(CTRL10_C, &temp, 1);
    temp |= (1 << 1);
    dof6_hal_write(CTRL10_C, &temp, 1);
}

void dof6_significant_motion_enable(bool set)
{
    uint8_t temp;
    dof6_hal_read(CTRL10_C, &temp, 1);

    switch (set)
    {
    case true:
        temp |= 1;
        dof6_hal_write(CTRL10_C, &temp, 1);
        break;
    case false:
        temp &= ~(1);
        dof6_hal_write(CTRL10_C, &temp, 1);
        break;
    }
}

int8_t dof6_is_free_fall()
{
    uint8_t temp;
    dof6_hal_read(WAKE_UP_SRC, &temp, 1);
    temp = temp & (1 << 5);
    if ( temp == 0 ) return 0;
    else return 1;
}

int8_t dof6_is_sleep_event()
{
    uint8_t temp;
    dof6_hal_read(WAKE_UP_SRC, &temp, 1);
    temp = temp & (1 << 4);
    if ( temp == 0) return 0;
    else return 1;
}

int8_t dof6_is_wakeup_event()
{
    uint8_t temp;
    dof6_hal_read(WAKE_UP_SRC, &temp, 1);
    temp = temp & (1 << 3);
    if ( temp == 0) return 0;
    else return 1;
}

int8_t dof6_is_wakeup_event_on_x()
{
    uint8_t temp;
    dof6_hal_read(WAKE_UP_SRC, &temp, 1);
    temp = temp & (1 << 2);
    if ( temp == 0) return 0;
    else return 1;
}

int8_t dof6_is_wakeup_event_on_y()
{
    uint8_t temp;
    dof6_hal_read(WAKE_UP_SRC, &temp, 1);
    temp = temp & (1 << 1);
    if ( temp == 0) return 0;
    else return 1;
}

int8_t dof6_is_wakeup_event_on_z()
{
    uint8_t temp;
    dof6_hal_read(WAKE_UP_SRC, &temp, 1);
    temp = temp & 1;
    if ( temp == 0) return 0;
    else return 1;
}

int8_t dof6_is_tap_event()
{
    uint8_t temp;
    dof6_hal_read(TAP_SRC, &temp, 1);
    temp = temp & (1 << 6);
    if ( temp == 0) return 0;
    else return 1;
}

int8_t dof6_is_single_tap_event()
{
    uint8_t temp;
    dof6_hal_read(TAP_SRC, &temp, 1);
    temp = temp & (1 << 5);
    if ( temp == 0) return 0;
    else return 1;
}

int8_t dof6_is_double_tap_event()
{
    uint8_t temp;
    dof6_hal_read(TAP_SRC, &temp, 1);
    temp = temp & (1 << 4);
    if ( temp == 0) return 0;
    else return 1;
}

int8_t dof6_get_tap_detection_sign()
{
    uint8_t temp;
    dof6_hal_read(TAP_SRC, &temp, 1);
    temp = temp & (1 << 3);
    if ( temp == 0) return 1;
    else return 0;
}

int8_t dof6_is_tap_event_on_x()
{
    uint8_t temp;
    dof6_hal_read(TAP_SRC, &temp, 1);
    temp = temp & (1 << 2);
    if ( temp == 0) return 0;
    else return 1;
}

int8_t dof6_is_tap_event_on_y()
{
    uint8_t temp;
    dof6_hal_read(TAP_SRC, &temp, 1);
    temp = temp & (1 << 1);
    if ( temp == 0) return 0;
    else return 1;
}

int8_t dof6_is_tap_event_on_z()
{
    uint8_t temp;
    dof6_hal_read(TAP_SRC, &temp, 1);
    temp = temp & 1;
    if ( temp == 0) return 0;
    else return 1;
}

int8_t dof6_is_changed_position()
{
    uint8_t temp;
    dof6_hal_read(D6D_SRC, &temp, 1);
    temp = temp & (1 << 6);
    if ( temp == 0) return 0;
    else return 1;
}

int8_t dof6_is_high_event_z()
{
    uint8_t temp;
    dof6_hal_read(D6D_SRC, &temp, 1);
    temp = temp & (1 << 5);
    if ( temp == 0) return 0;
    else return 1;
}

int8_t dof6_is_low_event_z()
{
    uint8_t temp;
    dof6_hal_read(D6D_SRC, &temp, 1);
    temp = temp & (1 << 4);
    if ( temp == 0) return 0;
    else return 1;
}

int8_t dof6_is_high_event_y()
{
    uint8_t temp;
    dof6_hal_read(D6D_SRC, &temp, 1);
    temp = temp & (1 << 3);
    if ( temp == 0) return 0;
    else return 1;
}

int8_t dof6_is_low_event_y()
{
    uint8_t temp;
    dof6_hal_read(D6D_SRC, &temp, 1);
    temp = temp & (1 << 2);
    if ( temp == 0) return 0;
    else return 1;
}

int8_t dof6_is_high_event_x()
{
    uint8_t temp;
    dof6_hal_read(D6D_SRC, &temp, 1);
    temp = temp & (1 << 1);
    if ( temp == 0) return 0;
    else return 1;
}

int8_t dof6_is_low_event_x()
{
    uint8_t temp;
    dof6_hal_read(D6D_SRC, &temp, 1);
    temp = temp & 1;
    if ( temp == 0) return 0;
    else return 1;
}

int8_t dof6_is_boot_running()
{
    uint8_t temp;
    dof6_hal_read(STATUS_REG, &temp, 1);
    temp = temp & (1 << 3);
    if ( temp == 0) return 0;
    else return 1;
}

int8_t dof6_is_new_temp_data_available()
{
    uint8_t temp;
    dof6_hal_read(STATUS_REG, &temp, 1);
    temp = temp & (1 << 2);
    if ( temp == 0) return 0;
    else return 1;
}

int8_t dof6_is_new_gyro_data_available()
{
    uint8_t temp;
    dof6_hal_read(STATUS_REG, &temp, 1);
    temp = temp & (1 << 1);
    if ( temp == 0) return 0;
    else return 1;
}

int8_t dof6_is_new_accel_data_available()
{
    uint8_t temp;
    dof6_hal_read(STATUS_REG, &temp, 1);
    temp = temp & 1;
    if ( temp == 0) return 0;
    else return 1;
}

int16_t dof6_get_temp_data()
{
    int16_t temp;
    uint8_t buffer[2];
    dof6_hal_read(OUT_TEMP_L, buffer, 2);

    temp += (int16_t) buffer[0];
    temp |= ((int16_t)buffer[1]) << 8;

    return temp;
}

int16_t dof6_get_gyro_x()
{
    int16_t temp;
    uint8_t buffer[2];
    dof6_hal_read(OUTX_L_G, buffer, 2);

    temp += (int16_t) buffer[0];
    temp |= ((int16_t)buffer[1]) << 8;

    return temp;
}

int16_t dof6_get_gyro_y()
{
    int16_t temp;
    uint8_t buffer[2];
    dof6_hal_read(OUTY_L_G, buffer, 2);

    temp += (int16_t) buffer[0];
    temp |= ((int16_t)buffer[1]) << 8;

    return temp;
}

int16_t dof6_get_gyro_z()
{
    int16_t temp;
    uint8_t buffer[2];
    dof6_hal_read(OUTZ_L_G, buffer, 2);

    temp += (int16_t) buffer[0];
    temp |= ((int16_t)buffer[1]) << 8;

    return temp;
}

int16_t dof6_get_accel_x()
{
    int16_t temp;
    uint8_t buffer[2];
    dof6_hal_read(OUTX_L_XL, buffer, 2);

    temp += (int16_t) buffer[0];
    temp |= ((int16_t)buffer[1]) << 8;

    return temp;
}

int16_t dof6_get_accel_y()
{
    int16_t temp;
    uint8_t buffer[2];
    dof6_hal_read(OUTY_L_XL, buffer, 2);

    temp += (int16_t) buffer[0];
    temp |= ((int16_t)buffer[1]) << 8;

    return temp;
}

int16_t dof6_get_accel_z()
{
    int16_t temp;
    uint8_t buffer[2];
    dof6_hal_read(OUTZ_L_XL, buffer, 2);

    temp += (int16_t) buffer[0];
    temp |= ((int16_t)buffer[1]) << 8;

    return temp;
}

uint16_t dof6_fifo_get_unread_number()
{
    uint16_t temp;
    uint8_t buffer[2];
    dof6_hal_read(FIFO_STATUS1, buffer, 2);

    temp = (uint16_t)buffer[0];
    temp |= ((uint16_t)(buffer[1] & ~(0xf0))) << 8;
}

int8_t dof6_fifo_get_watermark_status()
{
    uint8_t temp;
    dof6_hal_read(FIFO_STATUS2, &temp, 1);
    temp = temp & (1 << 7);
    if ( temp == 0) return 0;
    else return 1;
}

int8_t dof6_fifo_get_overrun_status()
{
    uint8_t temp;
    dof6_hal_read(FIFO_STATUS2, &temp, 1);
    temp = temp & (1 << 6);
    if ( temp == 0) return 0;
    else return 1;
}

int8_t dof6_fifo_get_full_status()
{
    uint8_t temp;
    dof6_hal_read(FIFO_STATUS2, &temp, 1);
    temp = temp & (1 << 5);
    if ( temp == 0) return 0;
    else return 1;
}

int8_t dof6_fifo_get_empty_status()
{
    uint8_t temp;
    dof6_hal_read(FIFO_STATUS2, &temp, 1);
    temp = temp & (1 << 4);
    if ( temp == 0) return 0;
    else return 1;
}

uint16_t dof6_fifo_get_pattern()
{
    uint16_t temp;
    uint8_t buffer[2];
    dof6_hal_read(FIFO_STATUS3, buffer, 2);
    temp = (uint16_t) buffer[0];
    temp |= ((uint16_t)buffer[1]) << 8;
    return temp;
}

uint16_t dof6_fifo_get_data()
{
    uint16_t temp;
    uint8_t buffer[2];
    dof6_hal_read(FIFO_DATA_OUT_L, buffer, 2);

    temp = (uint16_t) buffer[0];
    temp |= ((uint16_t)buffer[1]) << 8;

    return temp;
}

uint32_t dof6_get_timestamp()
{
    uint32_t temp;
    uint8_t buffer[3];
    dof6_hal_read(TIMESTAMP0_REG, buffer, 3);
    temp = (uint32_t) buffer[0];
    temp |= ((uint32_t)buffer[1]) << 8;
    temp |= ((uint32_t)buffer[2]) << 16;
    return temp;
}

uint16_t dof6_get_step_timestamp()
{
    uint16_t temp;
    uint8_t buffer[2];
    dof6_hal_read(STEP_TIMESTAMP_L, buffer, 2);
    temp = (uint16_t) buffer[0];
    temp |= ((uint16_t)buffer[1]) << 8;
    return temp;
}

uint16_t dof6_get_step_count()
{
    uint16_t temp;
    uint8_t buffer[2];
    dof6_hal_read(STEP_COUNTER_L, buffer, 2);
    temp = (uint16_t) buffer[0];
    temp |= ((uint16_t)buffer[1]) << 8;
    return temp;
}

int8_t dof6_is_step_detected_in_dt()
{
    uint8_t temp;
    dof6_hal_read(FUNC_SRC, &temp, 1);
    temp = temp & (1 << 7);
    if ( temp == 0) return 0;
    else return 1;
}

int8_t dof6_is_significant_motion()
{
    uint8_t temp;
    dof6_hal_read(FUNC_SRC, &temp, 1);
    temp = temp & (1 << 6);
    if ( temp == 0) return 0;
    else return 1;
}

int8_t dof6_is_tilt_event()
{
    uint8_t temp;
    dof6_hal_read(FUNC_SRC, &temp, 1);
    temp = temp & (1 << 5);
    if ( temp == 0) return 0;
    else return 1;
}

int8_t dof6_is_step_detected()
{
    uint8_t temp;
    dof6_hal_read(FUNC_SRC, &temp, 1);
    temp = temp & (1 << 4);
    if ( temp == 0) return 0;
    else return 1;
}

int8_t dof6_is_step_overflow_detected()
{
    uint8_t temp;
    dof6_hal_read(FUNC_SRC, &temp, 1);
    temp = temp & (1 << 3);
    if ( temp == 0) return 0;
    else return 1;
}

void dof6_timer_enable(bool set)
{
    uint8_t temp;
    dof6_hal_read(TAP_CFG, &temp, 1);
    switch (set)
    {
    case true:
        temp |= (1 << 7);
        dof6_hal_write(TAP_CFG, &temp, 1);
        break;
    case false:
        temp &= ~(1 << 7);
        dof6_hal_write(TAP_CFG, &temp, 1);
        break;
    }
}

void dof6_pedometer_algorithm_enable(bool set)
{
    uint8_t temp;
    dof6_hal_read(TAP_CFG, &temp, 1);
    switch (set)
    {
    case true:
        temp |= (1 << 6);
        dof6_hal_write(TAP_CFG, &temp, 1);
        break;
    case false:
        temp &= ~(1 << 6);
        dof6_hal_write(TAP_CFG, &temp, 1);
        break;
    }
}

void dof6_tilt_enable(bool set)
{
    uint8_t temp;
    dof6_hal_read(TAP_CFG, &temp, 1);
    switch (set)
    {
    case true:
        temp |= (1 << 5);
        dof6_hal_write(TAP_CFG, &temp, 1);
        break;
    case false:
        temp &= ~(1 << 5);
        dof6_hal_write(TAP_CFG, &temp, 1);
        break;
    }
}

void dof6_accel_hp_lpf2_enable(bool set)
{
    uint8_t temp;
    dof6_hal_read(TAP_CFG, &temp, 1);
    switch (set)
    {
    case true:
        temp |= (1 << 4);
        dof6_hal_write(TAP_CFG, &temp, 1);
        break;
    case false:
        temp &= ~(1 << 4);
        dof6_hal_write(TAP_CFG, &temp, 1);
        break;
    }
}

void dof6_tap_x_enable(bool set)
{
    uint8_t temp;
    dof6_hal_read(TAP_CFG, &temp, 1);
    switch (set)
    {
    case true:
        temp |= (1 << 3);
        dof6_hal_write(TAP_CFG, &temp, 1);
        break;
    case false:
        temp &= ~(1 << 3);
        dof6_hal_write(TAP_CFG, &temp, 1);
        break;
    }
}

void dof6_tap_y_enable(bool set)
{
    uint8_t temp;
    dof6_hal_read(TAP_CFG, &temp, 1);
    switch (set)
    {
    case true:
        temp |= (1 << 2);
        dof6_hal_write(TAP_CFG, &temp, 1);
        break;
    case false:
        temp &= ~(1 << 2);
        dof6_hal_write(TAP_CFG, &temp, 1);
        break;
    }
}

void dof6_tap_z_enable(bool set)
{
    uint8_t temp;
    dof6_hal_read(TAP_CFG, &temp, 1);
    switch (set)
    {
    case true:
        temp |= (1 << 1);
        dof6_hal_write(TAP_CFG, &temp, 1);
        break;
    case false:
        temp &= ~(1 << 1);
        dof6_hal_write(TAP_CFG, &temp, 1);
        break;
    }
}

void dof6_latched_interrupt_enable(bool set)
{
    uint8_t temp;
    dof6_hal_read(TAP_CFG, &temp, 1);
    switch (set)
    {
    case true:
        temp |= 1;
        dof6_hal_write(TAP_CFG, &temp, 1);
        break;
    case false:
        temp &= ~(1);
        dof6_hal_write(TAP_CFG, &temp, 1);
        break;
    }
}

void dof6_4d_enable(bool set)
{
    uint8_t temp;
    dof6_hal_read(TAP_THS_6D, &temp, 1);
    switch (set)
    {
    case true:
        temp |= 1;
        dof6_hal_write(TAP_THS_6D, &temp, 1);
        break;
    case false:
        temp &= ~(1);
        dof6_hal_write(TAP_THS_6D, &temp, 1);
        break;
    }
}

int8_t dof6_6d_set_threshold(d6d_threshold_t threshold)
{
    uint8_t temp;
    int8_t status = 0;
    dof6_hal_read(TAP_THS_6D, &temp, 1);
    switch (threshold)
    {
    case DEGREES_80:
        temp &= ~(3 << 5);
        dof6_hal_write(TAP_THS_6D, &temp, 1);
        break;
    case DEGREES_70:
        temp &= ~(3 << 5);
        temp |= (1 << 5);
        dof6_hal_write(TAP_THS_6D, &temp, 1);
        break;
    case DEGREES_60:
        temp &= ~(3 << 5);
        temp |= (1 << 6);
        dof6_hal_write(TAP_THS_6D, &temp, 1);
        break;
    case DEGREES_50:
        temp |= (3 << 5);
        dof6_hal_write(TAP_THS_6D, &temp, 1);
        break;
    default:
        status = -1;
        break;
    }
    return status;
}

int8_t dof6_tap_set_threshold(uint8_t threshold)
{
    uint8_t temp;
    int8_t status = 0;
    dof6_hal_read(TAP_THS_6D, &temp, 1);
    if (threshold > 31) status = -1;
    else
    {
        temp |= threshold;
        dof6_hal_write(TAP_THS_6D, &temp, 1);
    }
    return status;
}

int8_t dof6_double_tap_set_time_gap(uint8_t max_time_tap)
{
    uint8_t temp;
    int8_t status = 0;
    dof6_hal_read(INT_DUR2, &temp, 1);
    if (max_time_tap > 15) status = -1;
    else
    {
        temp |= (max_time_tap << 4);
        dof6_hal_write(INT_DUR2, &temp, 1);
    }
    return status;
}

int8_t dof6_tap_set_quiet_time(uint8_t quiet_time)
{
    uint8_t temp;
    int8_t status = 0;
    dof6_hal_read(INT_DUR2, &temp, 1);
    if (quiet_time > 3) status = -1;
    else
    {
        temp |= quiet_time << 2;
        dof6_hal_write(INT_DUR2, &temp, 1);
    }
    return status;
}

int8_t dof6_tap_set_shock_time( uint8_t duration )
{
    uint8_t temp;
    int8_t status = 0;
    dof6_hal_read(INT_DUR2, &temp, 1);

    if (duration > 3) status = -1;
    else
    {
        temp |= duration;
        dof6_hal_write(INT_DUR2, &temp, 1);
    }
    return status;

}

int8_t dof6_tap_event_select(tap_wakeup_t select)
{
    uint8_t temp;
    int8_t status = 0;
    dof6_hal_read(WAKE_UP_THS, &temp, 1);
    switch (select)
    {
    case SINGLE_ONLY:
        temp &=  ~(1 << 7);
        dof6_hal_write(WAKE_UP_THS, &temp, 1);
        break;
    case SINGLE_AND_DOUBLE:
        temp |= (1 << 7);
        dof6_hal_write(WAKE_UP_THS, &temp, 1);
    default:
        status = -1;
        break;
    }
    return status;
}

void dof6_inactivity_event_enable(bool set)
{
    uint8_t temp;
    dof6_hal_read(WAKE_UP_THS, &temp, 1);
    switch (set)
    {
    case true:
        temp |= (1 << 6);
        dof6_hal_write(WAKE_UP_THS, &temp, 1);
        break;
    case false:
        temp &= ~(1 << 6);
        dof6_hal_write(WAKE_UP_THS, &temp, 1);
        break;
    }
}

int8_t dof6_wakeup_set_threshold(uint8_t threshold)
{
    uint8_t temp;
    int8_t status = 0;

    if (threshold > 63) status = -1;
    else
    {
        dof6_hal_read(WAKE_UP_THS, &temp, 1);
        temp |= threshold;
        dof6_hal_write(WAKE_UP_THS, &temp, 1);
    }
    return status;
}

int8_t dof6_free_fall_set_duration(uint8_t duration)
{
    uint8_t temp;
    int8_t status;
    if (duration > 63) status = -1;
    else
    {
        if (duration >= 32)
        {
            dof6_hal_read(WAKE_UP_DUR, &temp, 1);
            temp |= (1 << 7);
            dof6_hal_write(WAKE_UP_DUR, &temp, 1);
        }

        dof6_hal_read(FREE_FALL, &temp, 1);
        temp |= (duration << 4);
        dof6_hal_write(FREE_FALL, &temp, 1);
    }
    return status;
}

int8_t dof6_wakeup_set_duration(uint8_t duration)
{
    uint8_t temp;
    int8_t status = 0;

    if (duration > 3) status = -1;
    else
    {
        dof6_hal_read(WAKE_UP_DUR, &temp, 1);
        temp |= (duration << 5);
        dof6_hal_write(WAKE_UP_DUR, &temp, 1);
    }
    return status;
}

int8_t dof6_timer_set_resolution(timer_resolution_t resolution)
{
    uint8_t temp;
    int8_t status = 0;
    dof6_hal_read(WAKE_UP_DUR, &temp, 1);

    switch (resolution)
    {
    case MS_6_4:
        temp &= ~ (1 << 4);
        dof6_hal_write(WAKE_UP_DUR, &temp, 1);
        break;
    case MS_25:
        temp |= (1 << 4);
        dof6_hal_write(WAKE_UP_DUR, &temp, 1);
        break;
    default:
        status = -1;
        break;
    }
    return status;
}

int8_t dof6_sleep_set_duration(uint8_t duration)
{
    uint8_t temp;
    int8_t status = 0;
    if (duration > 15) status = -1;

    else
    {
        dof6_hal_read(WAKE_UP_DUR, &temp, 1);
        temp |= duration;
        dof6_hal_write(WAKE_UP_DUR, &temp, 1);
    }

    return status;
}

int8_t dof6_free_fall_set_threshold (free_fall_threshold_t threshold)
{
    uint8_t temp;
    int8_t status = 0;

    dof6_hal_read(FREE_FALL, &temp, 1);
    switch (threshold)
    {
    case mg_156:
        temp &= ~(7);
        dof6_hal_write(FREE_FALL, &temp, 1);
        break;
    case mg_219:
        temp &= ~(7);
        temp |= 1;
        dof6_hal_write(FREE_FALL, &temp, 1);
        break;
    case mg_250:
        temp &= ~(7);
        temp |= (1 << 1);
        dof6_hal_write(FREE_FALL, &temp, 1);
        break;
    case mg_312:
        temp &= ~(7);
        temp |= 3;
        dof6_hal_write(FREE_FALL, &temp, 1);
        break;
    case mg_344:
        temp &= ~(7);
        temp |= (1 << 2);
        dof6_hal_write(FREE_FALL, &temp, 1);
        break;
    case mg_406:
        temp &= ~(7);
        temp |= 1;
        temp |= (1 << 2);
        dof6_hal_write(FREE_FALL, &temp, 1);
        break;
    case mg_469:
        temp &= ~(7);
        temp |= (1 << 1);
        temp |= (1 << 2);
        dof6_hal_write(FREE_FALL, &temp, 1);
        break;
    case mg_469:
        temp |= (7);
        dof6_hal_write(FREE_FALL, &temp, 1);
        break;
    default:
        status = -1;
        break;
    }
    return status;
}

int8_t dof6_int1_set_routing_functions(int1_routing_t interrupt1)
{
    uint8_t temp = 0;
    uint8_t temp1;

    if (interrupt1.inactive_state == 0) temp |= (1 << 7);
    if (interrupt1.single_tap == 0)     temp |= (1 << 6);
    if (interrupt1.wake_up == 0)        temp |= (1 << 5);
    if (interrupt1.free_fall == 0)      temp |= (1 << 4);
    if (interrupt1.double_tap == 0)     temp |= (1 << 3);
    if (interrupt1.d6 == 0)             temp |= (1 << 2);
    if (interrupt1.tilt == 0) temp |= (1 << 1);
    if (interrupt1.timer == 0) temp |= (1);

    dof6_hal_write (MD1_CFG, &temp, 1);
    dof6_hal_read (MD1_CFG, &temp1, 1);
    if (temp == temp1) return 0;
    else return -1;
}

int8_t dof6_int2_set_routing_functions(int2_routing_t interrupt2)
{
    uint8_t temp = 0;
    uint8_t temp1;

    if (interrupt2.inactive_state2 == 0) temp |= (1 << 7);
    if (interrupt2.single_tap2 == 0)     temp |= (1 << 6);
    if (interrupt2.wake_up2 == 0)        temp |= (1 << 5);
    if (interrupt2.free_fall2 == 0)      temp |= (1 << 4);
    if (interrupt2.double_tap2 == 0)     temp |= (1 << 3);
    if (interrupt2.d62 == 0)             temp |= (1 << 2);
    if (interrupt2.tilt2 == 0) temp |= (1 << 1);

    dof6_hal_write (MD2_CFG, &temp, 1);
    dof6_hal_read (MD2_CFG, &temp1, 1);
    if (temp == temp1) return 0;
    else return -1;
}


/** EMBEDDED FUNCTIONS REGISTERS AND IT'S FUNCTIONS **/


int8_t dof6_pedometer_set_internal_full_scale(acl_range_t scale)
{
    uint8_t temp;
    int8_t status = 0;
    dof6_embedded_functions_access_enable(true);
    dof6_hal_read(0x0F, &temp, 1);

    switch (scale)
    {
    case ACL_RANGE_2G:
        temp |= (1 << 7);
        dof6_hal_write(0x0F, &temp, 1);
        dof6_embedded_functions_access_enable(false);
        break;
    case ACL_RANGE_4G:
        temp &= ~(1 << 7);
        dof6_hal_write(0x0F, &temp, 1);
        dof6_embedded_functions_access_enable(true);
        break;
    default:
        dof6_embedded_functions_access_enable(false);
        status = -1;
        break;
    }
    return status;
}

int8_t dof6_pedometer_set_minimum_threshold(uint8_t threshold)
{
    uint8_t temp;
    int8_t status = 0;
    dof6_embedded_functions_access_enable(ENABLE);
    dof6_hal_read(0x0F, &temp, 1);
    if (threshold > 31)
    {
        dof6_embedded_functions_access_enable(false);
        status = -1;
    }
    else
    {
        temp |= threshold;
        dof6_hal_read(0x0F, &temp, 1);
        dof6_embedded_functions_access_enable(false);
    }
    return status;
}

int8_t dof6_significant_motion_set_threshold(uint8_t threshold)
{
    uint8_t temp;
    int8_t status = 0;
    dof6_embedded_functions_access_enable(ENABLE);
    dof6_hal_write(0x13, &threshold, 1);
    dof6_hal_read (0x13, &temp, 1);

    if (temp != threshold)
        status = -1;

    dof6_embedded_functions_access_enable(false);
    return status;
}

int8_t dof6_pedometer_set_debounce_time(uint8_t debounce_time)
{
    uint8_t temp;
    int8_t status = 0;
    dof6_embedded_functions_access_enable(ENABLE);
    dof6_hal_read ( 0x14, &temp, 1 );

    temp |= (debounce_time << 3);
    dof6_hal_write ( 0x14, &temp, 1 );

    dof6_hal_read ( 0x14, &temp, 1 );
    if ( (temp >> 3) != debounce_time)
        status = -1;

    dof6_embedded_functions_access_enable(false);
    return status;
}

int8_t dof6_pedometer_set_debounce_number(uint8_t number)
{
    uint8_t temp;
    int8_t status = 0;
    dof6_embedded_functions_access_enable(ENABLE);
    if ( number > 7)
        status = -1;
    else
    {
        dof6_hal_read ( 0x14, &temp, 1 );
        temp |= number;
        dof6_hal_write ( 0x14, &temp, 1 );
    }
    dof6_embedded_functions_access_enable(false);
    return status;
}

int8_t dof6_pedometer_set_time_period_value(uint8_t time_period)
{
    uint8_t temp;
    dof6_embedded_functions_access_enable(ENABLE);

    dof6_hal_write(0x15, &time_period, 1);
    dof6_hal_read (0x15, &temp, 1);

    if (temp != time_period)
        status = -1;

    return status;
}


/*************** END OF FUNCTIONS **********************************************/
