/** @file 6dof_api.h
 *  @brief API layer for working with the 6DOF IMU Click board, easily configures all desired interrupts
 *
 *  @date 10 Jun 2016
 *  @author Viktor Milovanovic
 *  @copyright GNU Public License
 *
 *  @version 1 - Initial testing and verification
 *
 *  @note Test configuration:
 *   MCU:             STM32F107VC
 *   Dev.Board:       EasyMx Pro v7
 *   Oscillator:      72 Mhz internal
 *   Ext. Modules:    GPS Click
 *   SW:              ARM 4.5.2
 *
 */

#ifndef DOF6_API_H
#define DOF6_API_H

#include "6dof_hw.h"
/**
 * @brief dof6_accel_configure
 * - Starts up and fully configures the accelerometer based on the provided parameters
 * @param odr
 * Desired output data rate, as defined in the odr_t structure
 * @param accel_x
 * true - accelerometer X axis enabled, false - disabled
 * @param accel_y
 * true - accelerometer Y axis enabled, false - disabled
 * @param accel_z
 * true - accelerometer Z axis enabled, false - disabled
 * @param range
 * Desired range as defined in the acl_range_t structure
 * @return
 * 0 if successful, -1 if failed (wrong parameters)
 */
int8_t dof6_accel_configure(odr_t odr, bool accel_x,bool accel_y, bool accel_z, acl_range_t range);
/**
 * @brief dof6_gyro_configure
 * - Starts up and fully configures the gyroscope based on the provided parameters
 * @param odr
 * Desired output data rate, as defined in the odr_t structure
 * @param gyro_x
 * true - gyroscope X axis enabled, false - disabled
 * @param gyro_y
 * true - gyroscope X axis enabled, false - disabled
 * @param gyro_z
 * true - gyroscope Z axis enabled, false - disabled
 * @param range
 * Desired range as defined in the gyro_range_t structure
 * @return
 * 0 if successful, -1 if failed (wrong parameters)
 */
int8_t dof6_gyro_configure(odr_t odr, bool gyro_x,bool gyro_y, bool gyro_z, gyro_range_t range);
/**
 * @brief dof6_accel_read_x
 * - Returns the value of the accelerometer X axis. This function currently just returns
 * the return value from dof6_get_accel_x() function. The function is left to be reimplemented by the user whether
 * or not he/she wants to manipulate the data in this api function
 * @return
 * 16bit value from the x axis
 */
int16_t dof6_accel_read_x();
/**
 * @brief dof6_accel_read_y
 * - Returns the value of the accelerometer Y axis. This function currently just returns
 * the return value from dof6_get_accel_y() function. The function is left to be reimplemented by the user whether
 * or not he/she wants to manipulate the data in this api function
 * @return
 * 16bit value from the y axis
 */
int16_t dof6_accel_read_y();
/**
 * @brief dof6_accel_read_z
 * - Returns the value of the accelerometer Z axis. This function currently just returns
 * the return value from dof6_get_accel_z() function. The function is left to be reimplemented by the user whether
 * or not he/she wants to manipulate the data in this api function
 * @return
 * 16bit value from the z axis
 */
int16_t dof6_accel_read_z();
/**
 * @brief dof6_gyro_read_x
 * - Returns the value of the gyroscope X axis. This function currently just returns
 * the return value from dof6_get_gyro_x() function. The function is left to be reimplemented by the user whether
 * or not he/she wants to manipulate the data in this api function
 * @return
 * 16bit value from the x axis
 */
int16_t dof6_gyro_read_x();
/**
 * @brief dof6_gyro_read_y
 * - Returns the value of the gyroscope Y axis. This function currently just returns
 * the return value from dof6_get_gyro_y() function. The function is left to be reimplemented by the user whether
 * or not he/she wants to manipulate the data in this api function
 * @return
 * 16bit value from the y axis
 */
int16_t dof6_gyro_read_y();
/**
 * @brief dof6_gyro_read_z
 * - Returns the value of the gyroscope Z axis. This function currently just returns
 * the return value from dof6_get_gyro_z() function. The function is left to be reimplemented by the user whether
 * or not he/she wants to manipulate the data in this api function
 * @return
 * 16bit value from the z axis
 */
int16_t dof6_gyro_read_z();
/**
 * @brief dof6_configure_single_tap_interrupt
 * - Fully configures the single tap interrupt with the given parameters
 * @param int_enable
 * enables/disables the interrupt.
 * TRUE - interrupt enabled
 * FALSE - interrupt disabled
 * @param threshold
 * Sets the desired threshold for the tap interrupt. See dof6_tap_set_threshold() for more information
 * @param quiet_time
 * Sets the desired quiet time for the tap interrupt. See dof6_tap_set_quiet_time() for more information
 * @param shock_time
 * Sets the desired shock time for the tap interrupt. See dof6_tap_set_shock_time() for more information
 * @param pin
 * Enables the interrupt on INT1 or INT2 pin
 * 1 - interrupt enabled on INT1 pin
 * 2 - interrupt enabled on INT2 pin
 * @return
 * 0 if successful, -1 if failed
 */
int8_t dof6_configure_single_tap_interrupt ( bool int_enable, uint8_t threshold,uint8_t quiet_time, uint8_t shock_time, uint8_t pin );
/**
 * @brief dof6_configure_double_tap_interrupt
 * - Fully configures the single tap interrupt with the given parameters
 * @param pin
 * Enables the interrupt on INT1 or INT2 pin
 * @param int_enable
 * enables/disables the interrupt.
 * TRUE - interrupt enabled
 * FALSE - interrupt disabled
 * @param threshold
 * Sets the desired threshold for the tap interrupt. See dof6_tap_set_threshold() for more information
 * @param quiet_time
 * Sets the desired quiet time for the tap interrupt. See dof6_tap_set_quiet_time() for more information
 * @param shock_time
 * Sets the desired shock time for the tap interrupt. See dof6_tap_set_shock_time() for more information
 * @param time_gap
 * Sets the desired time gap between two taps. See dof6_double_tap_set_time_gap() for more information
 * @return
 * 0 if successful, -1 if failed
 */
int8_t dof6_configure_double_tap_interrupt(uint8_t pin, bool int_enable, uint8_t threshold,uint8_t quiet_time, uint8_t shock_time, uint8_t time_gap );
/**
 * @brief dof6_configure_free_fall_interrupt
 * - Fully configures the free fall interrupt with the given parameters
 * @param pin
 * Enables the interrupt on INT1 or INT2 pin
 * 1 - interrupt enabled on INT1 pin
 * 2 - interrupt enabled on INT2 pin
 * @param int_enable
 * enables/disables the interrupt.
 * TRUE - interrupt enabled
 * FALSE - interrupt disabled
 * @param duration
 * Sets the desired free fall duration, see dof6_free_fall_set_duration() for more information
 * @param threshold
 * Sets the desired free fall threshold, see dof6_free_fall_set_threshold() for more information
 * @return
 * 0 if successful, -1 if failed
 */
int8_t dof6_configure_free_fall_interrupt(uint8_t pin, bool int_enable, uint8_t duration, uint8_t threshold );
/**
 * @brief dof6_configure_inactive_interrupt
 * - Configures the inactive interrupt with the desired parameter
 * @param int_enable
 * enables/disables the interrupt.
 * TRUE - interrupt enabled
 * FALSE - interrupt disabled
 * @param pin
 * Enables the interrupt on INT1 or INT2 pin
 * 1 - interrupt enabled on INT1 pin
 * 2 - interrupt enabled on INT2 pin
 * @param inactivity_duration
 * Desired inactivity duration, see dof6_sleep_set_duration() for more information
 * @param activity_duration
 * Desired activity duration, see dof6_wakeup_set_duration() for more information
 * @param threshold
 * Desired threshold, see dof6_wakeup_set_threshold() for more information
 * @return
 * 0 if successful, -1 if failed
 */
int8_t dof6_configure_inactive_interrupt(bool int_enable, uint8_t pin, uint8_t inactivity_duration, uint8_t activity_duration, uint8_t threshold);
/**
 * @brief dof6_configure_wakeup_interrupt
 * - Fully configures the wakeup interrupt based on the given parameters.
 * @param int_enable
 * enables/disables the interrupt.
 * TRUE - interrupt enabled
 * FALSE - interrupt disabled
 * @param pin
 * Enables the interrupt on INT1 or INT2 pin
 * 1 - interrupt enabled on INT1 pin
 * 2 - interrupt enabled on INT2 pin
 * @param high_pass
 * Enables/disables the high pass filter, see dof6_accel_hp_lpf2_enable() for more information
 * @param threshold
 * Desired threshold, see dof6_wakeup_set_threshold() for more information
 * @param duration
 * Desired wake up duration, see dof6_wakeup_set_duration() for more information
 * @return
 * 0 if successful, -1 if failed
 */
int8_t dof6_configure_wakeup_interrupt(bool int_enable, uint8_t pin, bool high_pass, uint8_t threshold, uint8_t duration);
/**
 * @brief dof6_configure_d6_interrupt
 * - Fully configures the d6 interrupt with the given parameters
 * @param int_enable
 * enables/disables the interrupt.
 * TRUE - interrupt enabled
 * FALSE - interrupt disabled
 * @param threshold
 * Desired threshold, see dof6_6d_set_threshold() for more information
 * @param pin
 * Enables the interrupt on INT1 or INT2 pin
 * 1 - interrupt enabled on INT1 pin
 * 2 - interrupt enabled on INT2 pin
 * @return
 * 0 if successful, -1 if failed
 */
int8_t dof6_configure_d6_interrupt(bool int_enable, d6d_threshold_t threshold, uint8_t pin );
/**
 * @brief dof6_configure_tilt_interrupt
 * - Fully configures the tilt interrupt based on the given parameters
 * @param int_enable
 * enables/disables the interrupt
 * TRUE - interrupt enabled
 * FALSE - interrupt disabled
 * @param pin
 * Enables the interrupt on INT1 or INT2 pin
 * 1 - interrupt enabled on INT1 pin
 * 2 - interrupt enabled on INT2 pin
 * @return
 * 0 if successful, -1 if failed
 */
int8_t dof6_configure_tilt_interrupt(bool int_enable, uint8_t pin );
/**
 * @brief dof6_configure_step_interrupt
 * - Configures the step interrupt based on the given parameters
 * @param int_enable
 * enables/disables the interrupt
 * TRUE - interrupt enabled
 * FALSE - interrupt disabled
 * @param pulsed
 * enables/disables the pulsed interrupt
 * @param pin
 * Enables the interrupt on INT1 or INT2 pin
 * 1 - interrupt enabled on INT1 pin
 * 2 - interrupt enabled on INT2 pin
 * @return
 * 0 if successful, -1 if not
 */
int8_t dof6_configure_step_interrupt(bool int_enable, bool pulsed, uint8_t pin);
/**
 * @brief dof6_configure_boot_interrupt
 * - Configures the boot interruot based on the given parameters
 * @param int_enable
 * enables/disables the interrupt
 * TRUE - interrupt enabled
 * FALSE - interrupt disabled
 * @return
 * 0 if successful, -1 if failed
 */
int8_t dof6_configure_boot_interrupt(bool int_enable);
/**
 * @brief dof6_configure_accel_data_ready_interrupt
 * - Configures the accelerometer data ready interrupt based on the given parameters
 * @param int_enable
 * enables/disables the interrupt
 * TRUE - interrupt enabled
 * FALSE - interrupt disabled
 * @param pin
 * Enables the interrupt on INT1 or INT2 pin
 * 1 - interrupt enabled on INT1 pin
 * 2 - interrupt enabled on INT2 pin
 * @return
 * 0 if successful, -1 if failed
 */
int8_t dof6_configure_accel_data_ready_interrupt(bool int_enable, uint8_t pin);
/**
 * @brief dof6_configure_gyro_data_ready_interrupt
 * - Configures the gyroscope data ready interrupt based on the given parameters
 * @param int_enable
 * enables/disables the interrupt
 * TRUE - interrupt enabled
 * FALSE - interrupt disabled
 * @param pin
 * Enables the interrupt on INT1 or INT2 pin
 * 1 - interrupt enabled on INT1 pin
 * 2 - interrupt enabled on INT2 pin
 * @return
 * 0 if successful, -1 if failed
 */
int8_t dof6_configure_gyro_data_ready_interrupt(bool int_enable, uint8_t pin);
/**
 * @brief dof6_configure_temp_data_ready_interrupt
 * - Configures the temperature data ready interrupt based on the given parameters
 * @param int_enable
 * enables/disables the interrupt
 * TRUE - interrupt enabled
 * FALSE - interrupt disabled
 * @return
 * 0 if successful, -1 if failed
 */
int8_t dof6_configure_temp_data_ready_interrupt(bool int_enable);




#endif // DOF6_API_H

