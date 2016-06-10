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
#include "6dof_api.h"
#include "6dof_hw.h"


/******************************************************************************
* Module Preprocessor Constants
*******************************************************************************/
/**
 * Doxygen tag for documenting variables and constants
 */


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
/******************************************************************************/


int8_t dof6_accel_configure(odr_t odr, bool accel_x, bool accel_y, bool accel_z, acl_range_t range)
{
    int8_t temp_check;
    temp_check = dof6_accel_set_output_data_rate(odr);
    if (temp_check == -1) return -1;

    dof6_accel_x_enable(accel_x);
    dof6_accel_y_enable(accel_y);
    dof6_accel_z_enable(accel_z);

    temp_check = dof6_accel_set_range(range);
    if (temp_check == -1) return -1;

    return 0;
}

int8_t dof6_gyro_configure(odr_t odr, bool gyro_x, bool gyro_y, bool gyro_z, gyro_range_t range)
{
    int8_t temp_check;
    temp_check = dof6_gyro_set_output_data_rate(odr);
    if (temp_check == -1) return -1;

    dof6_gyro_x_enable(gyro_x);
    dof6_gyro_y_enable(gyro_y);
    dof6_gyro_z_enable(gyro_z);

    temp_check = dof6_gyro_set_range(range);
    if (temp_check == -1) return -1;

    return true;
}

int16_t dof6_accel_read_x()
{
  return dof6_get_accel_x();
}

int16_t dof6_accel_read_y()
{
    return dof6_get_accel_y();
}

int16_t dof6_accel_read_z()
{
    return dof6_get_accel_z();
}

int16_t dof6_gyro_read_x()
{
    return dof6_get_gyro_x();
}

int16_t dof6_gyro_read_y()
{
    return dof6_get_gyro_y();
}

int16_t dof6_gyro_read_z()
{
    return dof6_get_gyro_z();
}

int8_t dof6_configure_single_tap_interrupt ( bool int_enable, uint8_t threshold,uint8_t quiet_time, uint8_t shock_time, uint8_t pin )
{
    uint8_t temp;
    int8_t temp_check;
    if (int_enable == true)
    {
        dof6_tap_x_enable(true);
        dof6_tap_y_enable(true);
        dof6_tap_z_enable(true);
        temp_check = dof6_tap_set_threshold(threshold);
        if (temp_check == -1) return -1;
        temp_check = dof6_tap_set_shock_time(shock_time);
        if (temp_check == -1) return -1;
        temp_check =  dof6_tap_set_quiet_time(quiet_time);
        if (temp_check == -1) return -1;
        dof6_tap_event_select(SINGLE_ONLY);
        if (pin ==  1)
        {
            dof6_hal_read(MD1_CFG, &temp, 1);
            temp |= (1<<6);
            dof6_hal_write(MD1_CFG, &temp, 1);
            return true;
        }
        else if (pin == 2)
        {
            dof6_hal_read(MD2_CFG, &temp, 1);
            temp |= (1<<6);
            dof6_hal_write(MD2_CFG, &temp, 1);
            return true;
        }
        else return -1;
    }
    else if (int_enable == false)
    {
        dof6_tap_x_enable(false);
        dof6_tap_y_enable(false);
        dof6_tap_z_enable(false);
        if(pin == 1)
        {
            dof6_hal_read(MD1_CFG, &temp, 1);
            temp &= ~(1<<6);
            dof6_hal_write(MD1_CFG, &temp, 1);
            return 0;
        }
        else if (pin == 2)
        {
            dof6_hal_read(MD2_CFG, &temp, 1);
            temp &= ~(1<<6);
            dof6_hal_write(MD2_CFG, &temp, 1);
            return 0;
        }
        else return -1;
    }
}

int8_t dof6_configure_double_tap_interrupt(uint8_t pin, bool int_enable, uint8_t threshold,uint8_t quiet_time, uint8_t shock_time, uint8_t time_gap )
{
    uint8_t temp;
    int8_t temp_check;
    if (int_enable == true)
    {
        dof6_tap_x_enable(true);
        dof6_tap_y_enable(true);
        dof6_tap_z_enable(true);
        temp_check = dof6_tap_set_threshold(threshold);
        if (temp_check == -1) return -1;
        temp_check = dof6_tap_set_shock_time(shock_time);
        if (temp_check == -1) return -1;
        temp_check =  dof6_tap_set_quiet_time(quiet_time);
        if (temp_check == -1) return -1;
        temp_check = dof6_double_tap_set_time_gap(time_gap);
        if (temp_check == -1) return -1;
        dof6_tap_event_select(SINGLE_AND_DOUBLE);
        if (pin == 1)
        {
            dof6_hal_read(MD1_CFG, &temp, 1);
            temp |= (1<<3);
            dof6_hal_write(MD1_CFG, &temp, 1);
            return 0;
        }

        else if (pin == 2)
        {
            dof6_hal_read(MD1_CFG, &temp, 1);
            temp |= (1<<3);
            dof6_hal_write(MD1_CFG, &temp, 1);
            return 0;
        }
        else return -1;
    }
    else if (int_enable == false)
    {
        dof6_tap_x_enable(false);
        dof6_tap_y_enable(false);
        dof6_tap_z_enable(false);
        if (pin == 1)
        {
            dof6_hal_read(MD1_CFG, &temp, 1);
            temp &= ~(1<<3);
            dof6_hal_write(MD1_CFG, &temp, 1);
            return 0;
        }
        else if (pin == 2)
        {
            dof6_hal_read(MD2_CFG, &temp, 1);
            temp &= ~(1<<3);
            dof6_hal_write(MD2_CFG, &temp, 1);
            return 0;
        }
        else return -1;
    }
}

int8_t dof6_configure_free_fall_interrupt(uint8_t pin, bool int_enable, uint8_t duration, uint8_t threshold )
{
    uint8_t temp;
    int8_t temp_check;

    if (int_enable == true)
    {
        temp_check = dof6_free_fall_set_duration(duration);
        if (temp_check == -1) return -1;
        temp_check = dof6_free_fall_set_threshold(threshold);
        if (temp_check == -1) return -1;
        if (pin == 1)
        {
            dof6_hal_read(MD1_CFG, &temp, 1);
            temp |= (1<<4);
            dof6_hal_write(MD1_CFG, &temp, 1);
            return 0;
        }

        else if (pin == 2)
        {
            dof6_hal_read(MD2_CFG, &temp, 1);
            temp |= (1<<4);
            dof6_hal_write(MD2_CFG, &temp, 1);
            return 0;
        }

        else return -1;
    }

    else if (int_enable == false)
    {
        if (pin == 1)
        {
            dof6_hal_read(MD1_CFG, &temp, 1);
            temp &= ~(1<<4);
            dof6_hal_write(MD1_CFG, &temp, 1);
            return 0;
        }
        else if (pin == 2)
        {
            dof6_hal_read(MD2_CFG, &temp, 1);
            temp &= ~(1<<4);
            dof6_hal_write(MD2_CFG, &temp, 1);
            return 0;
        }
        else return -1;
    }

    else return -1;
}

int8_t dof6_configure_inactive_interrupt(bool int_enable, uint8_t pin, uint8_t inactivity_duration, uint8_t activity_duration, uint8_t threshold)
{
    uint8_t temp;
    int8_t temp_check;

    if (int_enable == true)
    {
        temp_check = dof6_sleep_set_duration(inactivity_duration);
        if (temp_check == -1) return -1;

        temp_check = dof6_wakeup_set_duration(activity_duration);
        if (temp_check == -1) return -1;

        temp_check = dof6_wakeup_set_threshold(threshold);
        if (temp_check == -1) return -1;

        dof6_inactivity_event_enable(true);

        if (pin == 1)
        {
            dof6_hal_read(MD1_CFG, &temp, 1);
            temp |= (1<<7);
            dof6_hal_write(MD1_CFG, &temp, 1);
            return 0;
        }

        else if (pin == 2)
        {
            dof6_hal_read(MD2_CFG, &temp, 1);
            temp |= (1<<7);
            dof6_hal_write(MD2_CFG, &temp, 1);
            return 0;
        }

        else return -1;
    }

    else if (int_enable == false)
    {
        if (pin == 1)
        {
            dof6_hal_read(MD1_CFG, &temp, 1);
            temp &= ~(1<<7);
            dof6_hal_write(MD1_CFG, &temp, 1);
            return 0;
        }

        else if (pin == 2)
        {
            dof6_hal_read(MD2_CFG, &temp, 1);
            temp &= ~(1<<7);
            dof6_hal_write(MD2_CFG, &temp, 1);
            return 0;
        }

        else return -1;
    }

    else return -1;


}

int8_t dof6_configure_wakeup_interrupt(bool int_enable, uint8_t pin, bool high_pass, uint8_t threshold, uint8_t duration)
{
    uint8_t temp;
    int8_t temp_check;

    if (int_enable == true)
    {
        if (high_pass == true)
        {
            dof6_accel_hp_lpf2_enable(true);
        }
        else if (high_pass == false)
        {
            dof6_accel_hp_lpf2_enable(false);
        }
        else return -1;
        dof6_latched_interrupt_enable(false);

        temp_check = dof6_wakeup_set_duration(duration);
        if (temp_check == -1) return -1;

        temp_check = dof6_wakeup_set_threshold(threshold);
        if (temp_check == -1) return -1;

        if (pin == 1)
        {
            dof6_hal_read(MD1_CFG, &temp, 1);
            temp |= (1<<5);
            dof6_hal_write(MD1_CFG, &temp, 1);
            return 0;
        }

        else if (pin == 2)
        {
            dof6_hal_read(MD2_CFG, &temp, 1);
            temp |= (1<<5);
            dof6_hal_write(MD2_CFG, &temp, 1);
            return 0;
        }

        else return -1;
    }

    else if (int_enable == false)
    {
        if (pin == 1)
        {
            dof6_hal_read(MD1_CFG, &temp, 1);
            temp &= ~(1<<5);
            dof6_hal_write(MD1_CFG, &temp, 1);
            return 0;
        }

        else if (pin == 2)
        {
            dof6_hal_read(MD2_CFG, &temp, 1);
            temp &= (1<<5);
            dof6_hal_write(MD2_CFG, &temp, 1);
            return 0;
        }
        else return -1;
    }

    else return -1;
}

int8_t dof6_configure_d6_interrupt(bool int_enable, d6d_threshold_t threshold, uint8_t pin )
{
    uint8_t temp;
    int8_t temp_check;

    if( int_enable == true)
    {
        temp_check = dof6_6d_set_threshold(threshold);
        if (temp_check == -1) return -1;
        dof6_accel_hp_lpf2_enable(true);
        dof6_6d_low_pass_enable(true);
        if (pin == 1)
        {
            dof6_hal_read(MD1_CFG, &temp, 1);
            temp |= (1<<2);
            dof6_hal_write(MD1_CFG, &temp, 1);
            return 0;
        }
        else if (pin == 2)
        {
            dof6_hal_read(MD2_CFG, &temp, 1);
            temp |= (1<<2);
            dof6_hal_write(MD2_CFG, &temp, 1);
            return 0;
        }
        else return -1;
    }

    else if (int_enable == false)
    {
       dof6_6d_low_pass_enable(false);
       if (pin == 1)
       {
            dof6_hal_read(MD1_CFG, &temp, 1);
            temp &= ~(1<<2);
            dof6_hal_write(MD1_CFG, &temp, 1);
            return true;
       }
       else if (pin == 2)
       {
           dof6_hal_read(MD2_CFG, &temp, 1);
           temp &= ~(1<<2);
           dof6_hal_write(MD2_CFG, &temp, 1);
           return 0;
       }
       else return -1;
    }

    else return -1;
}

int8_t dof6_configure_tilt_interrupt(bool int_enable, uint8_t pin )
{

     uint8_t temp;
    if (int_enable == ENABLE)
    {
        dof6_embedded_functions_enable(true);
        dof6_tilt_enable(true);
        if(pin == 1)
        {
            dof6_hal_read(MD1_CFG, &temp, 1);
            temp |= (1<<1);
            dof6_hal_write(MD1_CFG, &temp, 1);
            return 0;
        }

        else if(pin == 2)
        {
            dof6_hal_read(MD2_CFG, &temp, 1);
            temp |= (1<<1);
            dof6_hal_write(MD2_CFG, &temp, 1);
            return 0;
        }

        else return -1;
    }

    else if (int_enable == false)
    {
        dof6_tilt_enable(false);
        if(pin == 1)
        {
            dof6_hal_read(MD1_CFG, &temp, 1);
            temp &= ~(1<<1);
            dof6_hal_write(MD1_CFG, &temp, 1);
            return 0;
        }

        else if(pin == 2)
        {
            dof6_hal_read(MD2_CFG, &temp, 1);
            temp &= ~(1<<1);
            dof6_hal_write(MD2_CFG, &temp, 1);
            return 0;
        }

        else return -1;
    }

    else return -1;
}

int8_t dof6_configure_timer_interrupt(bool int_enable, timer_resolution_t resolution )
{
    uint8_t temp;
    int8_t temp_check;
    if (int_enable == true)
    {
        dof6_timer_enable(true);
        temp_check = dof6_timer_set_resolution(resolution);
        if (temp_check == -1) return -1;
        dof6_hal_read(MD1_CFG, &temp, 1);
        temp |= (1);
        dof6_hal_write(MD1_CFG, &temp, 1);
        return 0;
    }

    else if (int_enable == false)
    {
        dof6_timer_enable(false);
        dof6_hal_read(MD1_CFG, &temp, 1);
        temp |= ~(1);
        dof6_hal_write(MD1_CFG, &temp, 1);
        return 0;
    }

    else return -1;
}

int8_t dof6_configure_step_interrupt(bool int_enable, bool pulsed, uint8_t pin)
{
    uint8_t temp;

    if (int_enable == true)
    {
        temp = dof6_accel_get_output_data_rate();
        if (temp < HZ_26) return -1;

        dof6_embedded_functions_enable(true);
        dof6_pedometer_algorithm_enable(true);
        dof6_pedometer_set_time_period_value(0);
        if (pulsed == true)
        {
            dof6_latched_interrupt_enable(false);
        }

        else if (pulsed == false)
        {
            dof6_latched_interrupt_enable(false);
        }

        else return -1;

        if (pin == 1)
        {
            dof6_hal_read(INT1_CTRL, &temp, 1);
            temp |= (1 << 7);
            dof6_hal_write(INT1_CTRL, &temp, 1);
            return 0;
        }

        if (pin == 2)
        {
            dof6_hal_read(INT1_CTRL, &temp, 1);
            temp |= (1 << 7);
            dof6_hal_write(INT1_CTRL, &temp, 1);
            return 0;
        }

        else return -1;
    }

    else if (int_enable == false)
    {
        dof6_embedded_functions_enable(false);
        dof6_pedometer_algorithm_enable(false);
        return 0;
    }

    else return -1;

}

int8_t dof6_configure_step_time_interrupt(bool int_enable, bool pulsed, uint8_t delta_time)
{
    uint8_t temp;
    int8_t temp_check;

    if (int_enable == true)
    {
        temp = dof6_accel_get_output_data_rate();
        if (temp < HZ_26) return -1;

        dof6_embedded_functions_enable(true);
        dof6_pedometer_algorithm_enable(true);
        dof6_timer_enable(true);
        dof6_timer_set_resolution(ms_6_4);
        temp_check = dof6_pedometer_set_time_period_value(delta_time);
        if (temp_check == -1) return -1;

        if (pulsed == true)
        {
            dof6_latched_interrupt_enable(false);
        }

        else if (pulsed == false)
        {
            dof6_latched_interrupt_enable(false);
        }

        else return -1;

        dof6_hal_read(INT2_CTRL, &temp, 1);
        temp |= (1 << 7);
        dof6_hal_write(INT2_CTRL, &temp, 1);
        return 0;
    }

    else if (int_enable == false)
    {
        dof6_pedometer_algorithm_enable(false);
        dof6_embedded_functions_enable(false);
        dof6_timer_enable(false);

        dof6_hal_read(INT2_CTRL, &temp, 1);
        temp &= ~(1 << 7);
        dof6_hal_write(INT2_CTRL, &temp, 1);
        return 0;
    }

    else return -1;

}

int8_t dof6_configure_step_count_interrupt(bool int_enable, bool pulsed)
{
    uint8_t temp;

    if (int_enable == true)
    {
        temp = dof6_accel_get_output_data_rate();
        if (temp < HZ_26) return -1;

        dof6_reset_pedometer_counter();
        dof6_embedded_functions_enable(true);
        dof6_pedometer_algorithm_enable(true);
        dof6_pedometer_set_time_period_value(0);

        if (pulsed == true)
        {
            dof6_latched_interrupt_enable(false);
        }

        else if (pulsed == false)
        {
            dof6_latched_interrupt_enable(false);
        }

        else return -1;

        dof6_hal_read(INT2_CTRL, &temp, 1);
        temp |= (1 << 6);
        dof6_hal_write(INT2_CTRL, &temp, 1);
    }

    else if (int_enable == false)
    {
        dof6_pedometer_algorithm_enable(false);
        dof6_embedded_functions_enable(false);
    }

    else return -1;
}

int8_t dof6_configure_sign_motion_interrupt(bool int_enable, uint8_t threshold, bool pulsed)
{
    uint8_t temp;
    int8_t temp_check;

    if (int_enable == true)
    {
        temp = dof6_accel_get_output_data_rate();
        if (temp < HZ_26) return -1;

        dof6_embedded_functions_access_enable(true);
        temp_check = dof6_significant_motion_set_threshold(threshold);
        if (temp_check == -1)
        {
            dof6_embedded_functions_access_enable(false);
            return -1;
        }

        dof6_embedded_functions_access_enable(false);

        dof6_embedded_functions_enable(true);
        dof6_significant_motion_enable(true);

        if (pulsed == true)
            dof6_latched_interrupt_enable(false);

        else if (pulsed == false)
            dof6_latched_interrupt_enable(false);

        else return -1;

        dof6_hal_read(INT1_CTRL, &temp, 1);
        temp |= (1 << 6);
        dof6_hal_write(INT1_CTRL, &temp, 1);

        return 0;
    }

    else if (int_enable == false)
    {
        dof6_embedded_functions_enable(false);
        dof6_significant_motion_enable(false);
        return 0;
    }

    else return -1;

}

int8_t dof6_configure_fifo_full_interrupt(bool int_enable, uint8_t pin)
{
    uint8_t temp;
    if (int_enable == true)
    {
        if (pin == 1)
        {
            dof6_hal_read(INT1_CTRL, &temp,1);
            temp |= (1<<5);
            dof6_hal_read(INT1_CTRL, &temp,1);
            return 0;
        }

        else if (pin == 2)
        {
            dof6_hal_read(INT1_CTRL, &temp,1);
            temp |= (1<<5);
            dof6_hal_read(INT1_CTRL, &temp,1);
            return 0;
        }
        else return -1;
    }

    else if (int_enable == false)
    {
        if (pin == 1)
        {
            dof6_hal_read(INT1_CTRL, &temp,1);
            temp &= ~(1<<5);
            dof6_hal_read(INT1_CTRL, &temp,1);
            return 0;
        }

        else if (pin == 2)
        {
            dof6_hal_read(INT2_CTRL, &temp,1);
            temp &= ~(1<<5);
            dof6_hal_read(INT2_CTRL, &temp,1);
            return 0;
        }

        else return -1;
    }

    else return -1;
}

int8_t dof6_configure_fifo_ovr_interrupt(bool int_enable, uint8_t pin)
{
    uint8_t temp;

    if (int_enable == true)
    {
        if (pin == 1)
        {
            dof6_hal_read(INT1_CTRL, &temp,1);
            temp |= (1<<4);
            dof6_hal_read(INT1_CTRL, &temp,1);
            return 0;
        }

        else if (pin == 2)
        {
            dof6_hal_read(INT1_CTRL, &temp,1);
            temp |= (1<<4);
            dof6_hal_read(INT1_CTRL, &temp,1);
            return 0;
        }
        else return -1;
    }

    else if (int_enable == false)
    {
        if (pin == 1)
        {
            dof6_hal_read(INT1_CTRL, &temp,1);
            temp &= ~(1<<4);
            dof6_hal_read(INT1_CTRL, &temp,1);
            return 0;
        }

        else if (pin == 2)
        {
            dof6_hal_read(INT2_CTRL, &temp,1);
            temp &= ~(1<<4);
            dof6_hal_read(INT2_CTRL, &temp,1);
            return 0;
        }

        else return -1;
    }

    else return -1;
}

int8_t dof6_configure_fifo_thrs_interrupt(bool int_enable, uint8_t pin, uint16_t threshold)
{
    uint8_t temp;

    if (int_enable == true)
    {
        dof6_fifo_threshold_level_enable(ENABLE);
        dof6_fifo_set_threshold_level(threshold);
        if (pin == 1)
        {
            dof6_hal_read(INT1_CTRL, &temp,1);
            temp |= (1<<3);
            dof6_hal_read(INT1_CTRL, &temp,1);
            return 0;
        }

        else if (pin == 2)
        {
            dof6_hal_read(INT1_CTRL, &temp,1);
            temp |= (1<<3);
            dof6_hal_read(INT1_CTRL, &temp,1);
            return 0;
        }
        else return -1;
    }

    else if (int_enable == false)
    {
        if (pin == 1)
        {
            dof6_hal_read(INT1_CTRL, &temp,1);
            temp &= ~(1<<3);
            dof6_hal_read(INT1_CTRL, &temp,1);
            return 0;
        }

        else if (pin == 2)
        {
            dof6_hal_read(INT2_CTRL, &temp,1);
            temp &= ~(1<<3);
            dof6_hal_read(INT2_CTRL, &temp,1);
            return 0;
        }

        else return -1;
    }

    else return -1;
}

int8_t dof6_configure_boot_interrupt(bool int_enable)
{
    uint8_t temp;

    if (int_enable == true)
    {
        dof6_hal_read(INT1_CTRL, &temp, 1);
        temp |= (1<<2);
        dof6_hal_write(INT1_CTRL, &temp, 1);
        return 0;
    }

    else if (int_enable == false)
    {
        dof6_hal_read(INT1_CTRL, &temp, 1);
        temp &= ~(1<<2);
        dof6_hal_write(INT1_CTRL, &temp, 1);
        return 0;
    }

    else return -1;
}

int8_t dof6_configure_accel_data_ready_interrupt(bool int_enable, uint8_t pin)
{
    uint8_t temp;

    if (int_enable == true)
    {
        if (pin == 1)
        {
            dof6_hal_read(INT1_CTRL, &temp, 1);
            temp |= (1);
            dof6_hal_write(INT1_CTRL, &temp, 1);
            return 0;
        }

        else if (pin == 2)
        {
            dof6_hal_read(INT2_CTRL, &temp, 1);
            temp |= (1);
            dof6_hal_write(INT2_CTRL, &temp, 1);
            return 0;
        }

        else return -1;
    }

    else if (int_enable == false)
    {
        dof6_hal_read(INT1_CTRL, &temp, 1);
        temp &= ~(1);
        dof6_hal_write(INT1_CTRL, &temp, 1);
        return 0;
    }

    else return -1;

}

int8_t dof6_configure_gyro_data_ready_interrupt(bool int_enable, uint8_t pin)
{
    uint8_t temp;

    if (int_enable == true)
    {
        if (pin == 1)
        {
           dof6_hal_read(INT1_CTRL, &temp, 1);
            temp |= (1<<1);
            dof6_hal_write(INT1_CTRL, &temp, 1);
            return 0;
        }

        if (pin == 2)
        {
            dof6_hal_read(INT2_CTRL, &temp, 1);
            temp |= (1<<1);
            dof6_hal_write(INT2_CTRL, &temp, 1);
            return 0;
        }

        else return -1;
    }

    else if (int_enable == false)
    {
        if (pin == 1)
        {
            dof6_hal_read(INT1_CTRL, &temp, 1);
            temp &= ~(1<<1);
            dof6_hal_write(INT1_CTRL, &temp, 1);
            return 0;
        }

        else if (pin == 2)
        {
            dof6_hal_read(INT2_CTRL, &temp, 1);
            temp &= ~(1<<1);
            dof6_hal_write(INT2_CTRL, &temp, 1);
            return 0;
        }
        else return -1;
    }

    else return -1;
}

int8_t dof6_configure_temp_data_ready_interrupt(bool int_enable)
{
    uint8_t temp;

    if (int_enable == true)
    {
        dof6_hal_read(INT2_CTRL, &temp, 1);
        temp |= (1<<2);
        dof6_hal_write(INT2_CTRL, &temp, 1);
        return 0;
    }

    else if (int_enable == false)
    {
        dof6_hal_read(INT2_CTRL, &temp, 1);
        temp &= ~(1<<2);
        dof6_hal_write(INT2_CTRL, &temp, 1);
        return 0;
    }

    else return -1;
}

















/*************** END OF FUNCTIONS ***************************************************************************/
