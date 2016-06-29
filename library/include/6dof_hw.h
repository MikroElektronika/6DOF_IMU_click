/****************************************************************************
* Title                 :   6DOF IMU hardware layer
* Filename              :   6dof_hw.h
* Author                :   Viktor Milovanovic
* Origin Date           :   10/06/2016
* Notes                 :   None
*****************************************************************************/
/**************************CHANGE LIST **************************************
*
*    Date    Software Version    Initials   Description
*  10/07/16    1.0.0               VM      Interface Created.
*
*****************************************************************************/
/** @file 6dof_hw.h
 *  @brief Hardware layer for working with the 6DOF IMU Click board
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

/**
 * @mainpage
 * @section Main General Description
 * @par
 * 6DOF IMU click is a mikroBUS™ add-on board that carries ST’s LSM6D33 IC, which is 6-axis inertial measurement unit comprising a 3-axis gyroscope
 * and a 3-axis accelerometer. The chip is a highly accurate 6 DOF inertial measurement unit with long-term stable operation over a wide range
 * of temperatures. It’s high robustness to mechanical shock makes is suitable for designing reliable platform stabilization systems,
 * for example in cameras and drones. The board communicates with the target MCU either through I2C or SPI interfaces
 * (along with an additional INT pin).
 *
 */

#ifndef DOF6_HW_H_
#define DOF6_HW_H_
/******************************************************************************
* Includes
*******************************************************************************/
#include <stdint.h>
#include <stdbool.h>
#include <6dof_hal.h>
/******************************************************************************
* Preprocessor Constants
*******************************************************************************/
#define FUNC_CFG_ACCESS          0x01

#define       FIFO_CTRL1         0x06
#define       FIFO_CTRL2         0x07
#define       FIFO_CTRL3         0x08
#define       FIFO_CTRL4         0x09
#define       FIFO_CTRL5         0x0A
#define       ORIENT_CFG_G       0x0B

#define       INT1_CTRL          0x0D
#define       INT2_CTRL          0x0E
#define       WHO_AM_I           0x0F
#define       CTRL1_XL           0x10
#define       CTRL2_G            0x11
#define       CTRL3_C            0x12
#define       CTRL4_C            0x13
#define       CTRL5_C            0x14
#define       CTRL6_C            0x15
#define       CTRL7_G            0x16
#define       CTRL8_XL           0x17
#define       CTRL9_XL           0x18
#define       CTRL10_C           0x19

#define       WAKE_UP_SRC        0x1B
#define       TAP_SRC            0x1C
#define       D6D_SRC            0x1D
#define       STATUS_REG         0x1E
#define       OUT_TEMP_L         0x20
#define       OUT_TEMP_H         0x21
#define       OUTX_L_G           0x22
#define       OUTX_H_G           0x23
#define       OUTY_L_G           0x24
#define       OUTY_H_G           0x25
#define       OUTZ_L_G           0x26
#define       OUTZ_H_G           0x27
#define       OUTX_L_XL          0x28
#define       OUTX_H_XL          0x29
#define       OUTY_L_XL          0x2A
#define       OUTY_H_XL          0x2B
#define       OUTZ_L_XL          0x2C
#define       OUTZ_H_XL          0x2D

#define       FIFO_STATUS1       0x3A
#define       FIFO_STATUS2       0x3B
#define       FIFO_STATUS3       0x3C
#define       FIFO_STATUS4       0x3D
#define       FIFO_DATA_OUT_L    0x3E
#define       FIFO_DATA_OUT_H    0x3F
#define       TIMESTAMP0_REG     0x40
#define       TIMESTAMP1_REG     0x41
#define       TIMESTAMP2_REG     0x42

#define       STEP_TIMESTAMP_L   0x49
#define       STEP_TIMESTAMP_H   0x4A
#define       STEP_COUNTER_L     0x4B
#define       STEP_COUNTER_H     0x4C

#define       FUNC_SRC           0x53
#define       TAP_CFG            0x58
#define       TAP_THS_6D         0x59
#define       INT_DUR2           0x5A
#define       WAKE_UP_THS        0x5B
#define       WAKE_UP_DUR        0x5C
#define       FREE_FALL          0x5D
#define       MD1_CFG            0x5E
#define       MD2_CFG            0x5F



/******************************************************************************
* Configuration Constants
*******************************************************************************/


/******************************************************************************
* Macros
*******************************************************************************/

/******************************************************************************
* Typedefs
*******************************************************************************/

/**
  * @struct
  * Interrupt pin 1 routing structure. Set desired interrupts to TRUE
  **/
typedef struct
{
    bool inactive_state;
    bool single_tap;
    bool wake_up;
    bool free_fall;
    bool double_tap;
    bool d6;
    bool tilt;
    bool timer;
} int1_routing_t;

/**
  * @struct
  * Interrupt pin 2 routing structure. Set desired interrupts to TRUE
  **/
typedef struct
{
    bool inactive_state2;
    bool single_tap2;
    bool wake_up2;
    bool free_fall2;
    bool double_tap2;
    bool d62;
    bool tilt2;
} int2_routing_t;

/**
 * @enum
 * Output data rate modes
 **/
typedef enum
{
    POWER_DOWN = 0,     /**< Power down mode */
    HZ_13,              /**< 13 Hz*/
    HZ_26,              /**< 26 Hz*/
    HZ_52,              /**< 52 Hz*/
    HZ_104,             /**< 104 Hz*/
    HZ_208,             /**< 208 Hz*/
    HZ_416,             /**< 416 Hz*/
    HZ_833,             /**< 833 Hz*/
    KHZ_1_6,            /**< 1.66 Hz*/
    KHZ_3_3,            /**< 3.33 Hz*/
    KHZ_6_6             /**< 6.66 Hz*/
} odr_t;

/**
 * @enum
 * Acellerometer range values
 **/
typedef enum
{
    ACL_RANGE_2G = 0,       /**< +- 2G */
    ACL_RANGE_16G,          /**< +- 16G */
    ACL_RANGE_4G,           /**< +- 4G */
    ACL_RANGE_8G            /**< +- 8G */
} acl_range_t;

/**
 * @enum
 * Fifo mode values
 **/
typedef enum
{
    FIFO_BYPASS_MODE = 0,   /**< Bypass mode. FIFO disabled */
    FIFO_FULL_MODE,         /**< FIFO mode. Stops collecting data when FIFO is full.*/
    CONTINOUS_TO_FIFO = 3, /**< Continuous mode until trigger is deasserted, then FIFO mode.*/
    BYPASS_TO_CONTINOUS,    /**< Bypass mode until trigger is deasserted, then Continuous mode.*/
    CONTINOUS = 6,          /**< Continuous mode. If the FIFO is full, the new sample overwrites the older one.*/
} fifo_mode_t;

/**
 * @enum
 * Gyro and Accel sign values for self test
 **/
typedef enum
{
    POSITIVE = 0,  /**< Positive sign*/
    NEGATIVE       /**< Negative sign*/
} gyro_sign_t;

/**
 * @enum
 * Orientation values, different axis orientation
 **/
typedef enum
{
    X_Y_Z = 0,
    X_Z_Y,
    Y_X_Z,
    Y_Z_X,
    Z_X_Y,
    Z_Y_X
} orientation_t;

/**
 * @enum
 * Filter bandwith values for anti-aliasing filter bandwitch selection
 **/
typedef enum
{
    HZ_400 = 0,
    HZ_200,
    HZ_100,
    HZ_50
} filter_bandwith_t;

/**
 * @enum
 * Gyroscope range values
 **/
typedef enum
{
    DPS_125 = 0,
    DPS_245,
    DPS_500,
    DPS_1000,
    DPS_2000
} gyro_range_t;

/**
 * @enum
 * Interrupt level values
 **/
typedef enum
{
    LOW = 0,
    HIGH,
} level_t;

/**
 * @enum
 * Interrupt mode values
 **/
typedef enum
{
    PUSH_PULL = 0,
    OPEN_DRAIN
} int_mode_t;

/**
 * @enum
 * Rounding values
 **/
typedef enum
{
    NO_ROUNDING = 0,  /**< No rounding*/
    ACC_ONLY,         /**< Accelerometer only rounding*/
    GYRO_ONLY,        /**< Gyroscope only rounding*/
    GYRO_AND_ACC,     /**< Both Gyroscope and Accelerometer rounding*/
} rounding_t;

/**
 * @enum
 * Self test values
 **/
typedef enum
{
    NORMAL_MODE,
    POS_SIGN,
    NEG_SIGN
} selftest_t;

/**
 * @enum
 * High pass cutoff frequency values
 **/
typedef enum
{
    HZ_0_0081 = 0,
    HZ_0_0324,
    HZ_2_07,
    HZ_16_32
} hp_cutoff_freq_t;

/**
 * @enum
 * Accelerometer slope and high-pass filter selection and cutoff frequency
 **/
typedef enum
{
    ODR_XL_50 = 0,      /**< ODR_XL/50*/
    ODR_XL_100,         /**< ODR_XL/100*/
    ODR_XL_9,           /**< ODR_XL/9*/
    ODR_XL_400          /**< ODR_XL/400*/
} slope_hp_config_t;

/**
 * @enum
 * D6D threshold values
 **/
typedef enum
{
    DEGREES_80 = 0,
    DEGREES_70,
    DEGREES_60,
    DEGREES_50
} d6d_threshold_t;

/**
 * @enum
 * Tap interrupt configuration values, configuring tap interrupt to be only on single tap, or both single and double tap
 **/
typedef enum
{
    SINGLE_ONLY = 0,
    SINGLE_AND_DOUBLE
} tap_wakeup_t;

/**
 * @enum
 * Timer resolution values
 **/
typedef enum
{
    MS_6_4 = 0,
    MS_25

} timer_resolution_t;

/**
 * @enum
 * Free fall interrupt threshold values
 **/
typedef enum
{
    MG_156 = 0,
    MG_219,
    MG_250,
    MG_312,
    MG_344,
    MG_406,
    MG_469,
    MG_500
} free_fall_threshold_t;

/**
  * @struct
  * Interrupt 1 configuring structure, set desired interrupts to TRUE
  * */
typedef struct
{
    bool step_detector;
    bool sign_motion;
    bool fifo_full;
    bool fifo_ovr;
    bool fifo_thrs;
    bool boot;
    bool gyro_drdy;
    bool accel_drdy;
} interrupt1_config_t;

/**
  * @struct
  * Interrupt 2 configuring structure, set desired interrupts to TRUE
  * */
typedef struct
{
    bool step_delta;
    bool step_count_ovr;
    bool fifo_full2;
    bool fifo_ovr2;
    bool fifo_thrs2;
    bool temp_drdy;
    bool gyro_drdy2;
    bool accel_drdy2;
} interrupt2_config_t;



/******************************************************************************
* Variables
*******************************************************************************/


/******************************************************************************
* Function Prototypes
*******************************************************************************/
#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief dof6_init
 * - Initializes the HAL, sets appropriate function pointers
 * @param address
 * I2C slave address of the 6dof IMU click
 * @return
 * 0 if successful, -1 if failed
 */
int8_t dof6_init ( uint8_t address );
/**
 * @brief dof6_embedded_functions_access_enable
 * - Enables/disables access to embedded functions (see datasheet for more info
 * @param set
 * true - enables, false - disables
 */
void dof6_embedded_functions_access_enable(bool set);
/**
 * @brief dof6_embedded_functions_enable
 * - Enables access to embedded functions register
 * @param set
 * TRUE - Enabled, FALSE - Disabled
 */
void dof6_embedded_functions_enable(bool set);
/**
 * @brief dof6_fifo_set_threshold_level
 * - Set's the threshold level of the fifo buffer. The watermark flag rises when the number of bytes written to FIFO after next write is greater than or equal to the threshold level.
 * @param threshold_level
 * Desired threshold level
 * @return
 */
int8_t dof6_fifo_set_threshold_level(uint16_t threshold_level);
/**
 * @brief dof6_fifo_pedometer_timestamp_enable
 * - Enable pedometer step counter and time stamp.
 * @param set
 * true - enables, false - disables
 */
void dof6_fifo_pedometer_timestamp_enable(bool set);
/**
 * @brief dof6_fifo_set_write_enable
 * - Enable/Disable write in FIFO based on XL/Gyro data-ready;
 * @param set
 * true - enable, false - disable
 */
void dof6_fifo_set_write_enable(bool set);
/**
 * @brief dof6_fifo_set_gyro_decimation
 * - Set gyro FIFO data decimation
 * @param set
 * Desired decimation
 * @return
 * 0 if succesful, -1 if failed
 */
int8_t dof6_fifo_set_gyro_decimation(uint8_t set);
/**
 * @brief dof6_fifo_set_accel_dcimation
 * - Set accel FIFO data decimation
 * @param set
 * desired decimation
 * @return
 * 0 if succesful, -1 if failed
 */
int8_t dof6_fifo_set_accel_dcimation (uint8_t set);
/**
 * @brief dof6_fifo_8bit_enable
 * - Enable/disable 8-bit data storage in FIFO.
 * @param set
 * true - enable, false - disable
 */
void dof6_fifo_8bit_enable(bool set);
/**
 * @brief dof6_fifo_set_third_data_decimation
 * - Third FIFO data set decimation setting
 * @param set
 * Desired decimation
 * @return
 * 0 if successful, -1 if failed
 */
int8_t dof6_fifo_set_third_data_decimation(uint8_t set);
/**
 * @brief dof6_fifo_set_output_data_rate
 * - Set desired data output rate
 * @param odr
 * Desired output rate defined in the odr_t data structure
 * @return
 * 0 if successful, -1 if failed
 */
int8_t dof6_fifo_set_output_data_rate(odr_t odr);
/**
 * @brief dof6_fifo_set_mode
 * - Sets the desired fifo mode as described in the datasheet
 * @param mode
 * Desired mode as defined in the fifo_mode_t data structure
 * @return
 * 0 if sucessfull, -1 if failed
 */
int8_t dof6_fifo_set_mode(fifo_mode_t mode);
/**
 * @brief dof6_gyro_set_sign_x
 * - Pitch axis (X) angular rate sign
 * @param sign
 * Sign as defined in the gyro_sign_t data structure (positive or negative).
 * @return
 * 0 if successful, -1 if failed
 */
int8_t dof6_gyro_set_sign_x(gyro_sign_t sign);
/**
 * @brief dof6_gyro_set_sign_y
 * - Roll axis (Y) angular rate sign.
 * @param sign
 * Sign as defined in the gyro_sign_t data structure (positive or negative).
 * @return
 * 0 if successful, -1 if failed
 */
int8_t dof6_gyro_set_sign_y(gyro_sign_t sign);
/**
 * @brief dof6_gyro_set_sign_z
 * - Yaw axis (Z) angular rate sign.
 * @param sign
 * Sign as defined in the gyro_sign_t data structure (positive or negative).
 * @return
 * 0 if successful, -1 if failed
 */
int8_t dof6_gyro_set_sign_z(gyro_sign_t sign);
/**
 * @brief dof6_gyro_set_directional_oritentation
 * - Directional user-orientation selection
 * @param orientation
 * Desired orientation as defined in the orientation_t data structure
 * @return
 * 0 if successful, -1 if failed
 */
int8_t dof6_gyro_set_directional_oritentation(orientation_t orientation);
/**
 * @brief dof6_int1_configure
 * - Configures the interrupt1 control register.
 * @param interrupt1
 * Data structure for configure the register, set the desired interrupts to TRUE or FALSE to enable or disable them.
 */
void dof6_int1_configure(interrupt1_config_t interrupt1);
/**
 * @brief dof6_int2_configure
 * - Configures the interrupt2 control register.
 * @param interrupt2
 * Data structure for configure the register, set the desired interrupts to TRUE or FALSE to enable or disable them.
 */
void dof6_int2_configure(interrupt2_config_t interrupt2);
/**
 * @brief dof6_accel_set_output_data_rate
 * - Accelerometer output data rate selection
 * @param data_rate
 * Desired data rate as defined in the odr_t data structure
 * @return
 * 0 if successful, -1 if failed
 */
int8_t dof6_accel_set_output_data_rate (odr_t data_rate);
/**
 * @brief dof6_accel_get_output_data_rate
 * - Returns the current data rate of the accelerometer
 * @return
 * The current data rate of the accelerometer as defined odr_t data structure
 */
odr_t dof6_accel_get_output_data_rate();
/**
 * @brief dof6_accel_set_range
 * - Set's the accelerometer full-scale range as defined in the acl_range_t data structure
 * @param range
 * Desired range as defined in the acl_range_t data structure
 * @return
 * 0 if succesful, -1 if failed
 */
int8_t dof6_accel_set_range (acl_range_t range);
/**
 * @brief dof6_accel_get_range
 * - Returns the current accelerometer range as defined in the acl_range_t data structure
 * @return
 * The current accelerometer range as defined in the acl_range_t data structure
 */
acl_range_t dof6_accel_get_range();
/**
 * @brief dof6_accel_set_filter_bandwith
 * - Anti-aliasing filter bandwidth selection
 * @param bandwith
 * Desired bandwith as defined in the filter_bandwith_t data structure
 * @return
 * 0 if successful, -1 if failed
 */
int8_t dof6_accel_set_filter_bandwith (filter_bandwith_t bandwith);
/**
 * @brief dof6_accel_get_filter_bandwith
 * - Gets the current accel anti aliasing filter bandwith
 * @return
 * The current accel filter bandwith as defined in the filter_bandwith_t structure
 */
filter_bandwith_t dof6_accel_get_filter_bandwith();
/**
 * @brief dof6_gyro_set_output_data_rate
 * - Gyroscope output data rate selection
 * @param data_rate
 * Desired data rate as defined in the odr_t data structure
 * @return
 * 0 if successful, -1 if failed
 */
int8_t dof6_gyro_set_output_data_rate ( odr_t data_rate );
/**
 * @brief dof6_gyro_get_output_data_rate
 * - Returns the current data output rate of the gyroscope
 * @return
 * Current data output rate of the gyroscope as defined in the odr_t structure.
 */
odr_t dof6_gyro_get_output_data_rate ();
/**
 * @brief dof6_gyro_set_range
 * - Gyroscope range selection
 * @param range
 * Desired range as defined in the gyro_range_t data structure
 * @return
 * 0 if successful, 01 if failed
 */
int8_t dof6_gyro_set_range(gyro_range_t range);
/**
 * @brief dof6_gyro_get_range
 * - Returns the current range of the gyroscope
 * @return
 * Current range of the gyroscope as defined in the gyro_range_t structure.
 */
gyro_range_t dof6_gyro_get_range();
/**
 * @brief dof6_reboot_enable
 * - Reboot memory content
 * @param set
 * True - reboot, false - don't reboot
 */
void dof6_reboot_enable(bool set);
/**
 * @brief dof6_continous_data_update_enable
 * - Set block data update to be continuous or to not be updated until MSB and LSB have been read
 * @param update
 * TRUE - continuous update, FALSE - output registers not updated until MSB and LSB have
 * been read
 */
void dof6_continous_data_update_enable(bool update);
/**
 * @brief dof6_set_interrupt_activation_level
 * - Sets the interrupt activation level
 * @param level
 * 0 - interrupt output pads active high; 1 - interrupt output pads active low
 * @return
 * 0 if successful, -1 if failed
 */
int8_t dof6_set_interrupt_activation_level(level_t level);
/**
 * @brief dof6_set_int_mode
 * - Push-pull/open-drain selection on INT1 and INT2 pads
 * @param mode
 * 0 - push-pull mode; 1 - open-drain mode, or as defined in the int_mode_t structure
 * @return
 * 0 if successful, -1 if failed
 */
int8_t dof6_set_int_mode(int_mode_t mode);
/**
 * @brief dof6_software_reset
 * - Software reset
 */
void dof6_software_reset();
/**
 * @brief dof6_accel_bandwith_selection_enable
 * - Accelerometer bandwidth selection
 * @param set
 * TRUE - bandwidth determined by setting, FALSE - bandwidth determined by ODR selection
 */
void dof6_accel_bandwith_selection_enable (bool set);
/**
 * @brief dof6_gyro_sleepmode_enable
 * - Gyroscope sleep mode enable
 * @param set
 * TURE - enable, FALSE - disable
 */
void dof6_gyro_sleepmode_enable(bool set);
/**
 * @brief dof6_int2_on_int1_enable
 *  - All interrupt signals available on INT1 pad enable
 * @param set
 * TRUE - all interrupt signals in logic or on INT1 pad
 * FALSE - interrupt signals divided between INT1 and INT2 pads
 */
void dof6_int2_on_int1_enable(bool set);
/**
 * @brief dof6_fifo_temp_enable
 * - Enable temperature data as 4 th FIFO data set
 * @param set
 * TRUE - enabled, FALSE - disabled
 */
void dof6_fifo_temp_enable(bool set);
/**
 * @brief dof6_da_timer_enable
 * - Enable/disable the DA timer
 * @param set
 * TRUE - enabled, FALSE - disabled
 */
void dof6_da_timer_enable(bool set);
/**
 * @brief dof6_fifo_threshold_level_enable
 * - Enable/disable FIFO threshold level use
 * @param set
 * TRUE - enabled, FALSE - disabled
 */
void dof6_fifo_threshold_level_enable(bool set);
/**
 * @brief dof6_set_burstmode_rounding
 * - Configure circular burst-mode (rounding) read from output registers
 * @param rounding
 * Desired rounding as defined in the rounding_t structure
 * @return
 * 0 if successful, -1 if failed
 */
int8_t dof6_set_burstmode_rounding(rounding_t rounding);
/**
 * @brief dof6_gyro_set_selftest
 * - Angular rate sensor self-test enable
 * @param set
 * Desired self test as defined in the selftest_t structure
 * @return
 * 0 if successful, -1 if failed
 */
int8_t dof6_gyro_set_selftest(selftest_t set);
/**
 * @brief dof6_accel_set_selftest
 * - Linear acceleration sensor self-test enable
 * @param set
 * Desired self test as defined in the selftest_t structure
 * @return
 * 0 if successful, -1 if failed
 */
int8_t dof6_accel_set_selftest(selftest_t set);
/**
 * @brief dof6_gyro_data_egde_trigger_enable
 * - Gyroscope data edge-sensitive trigger enable
 * @param set
 * TRUE - external trigger enabled, FALSE - external trigger disabled
 */
void dof6_gyro_data_egde_trigger_enable(bool set);
/**
 * @brief dof6_gyro_data_level_trigger_enable
 * - Gyroscope data level-sensitive trigger enable
 * @param set
 * TRUE - level sensitive trigger enabled, FALSE - level sensitive trigger disabled
 */
void dof6_gyro_data_level_trigger_enable(bool set);
/**
 * @brief dof6_gyro_level_sensitive_latch_enable
 * - Gyroscope level-sensitive latched enable
 * @param set
 * TRUE - level sensitive latched enabled, FALSE - level-sensitive latched disabled
 */
void dof6_gyro_level_sensitive_latch_enable(bool set);
/**
 * @brief dof6_accel_high_perfomance_operating_mode_enable
 * - High-performance operating mode enable/disable for accelerometer
 * @param set
 * TRUE - enabled, FALSE - disabled
 */
void dof6_accel_high_perfomance_operating_mode_enable(bool set);
/**
 * @brief dof6_gyro_high_perfomance_operating_mode_enable
 * - High-performance operating mode disable for gyroscope
 * @param set
 * TRUE - enabled, FALSE - disabled
 */
void dof6_gyro_high_perfomance_operating_mode_enable(bool set);
/**
 * @brief dof6_gyro_high_pass_filter_enable
 * - Enables/Disables the high pass filer for gyroscope
 * @param set
 * TRUE - Enabled, FALSE - Disabled
 */
void dof6_gyro_high_pass_filter_enable(bool set);
/**
 * @brief dof6_gyro_hp_filter_reset_enable
 * - Gyroscope high-pass filter reset enable
 * @param set
 * TRUE - enabled, FALSE - disabled
 */
void dof6_gyro_hp_filter_reset_enable(bool set);
/**
 * @brief dof6_rounding_function_enable
 * - Source register rounding function enable
 * @param set
 * TRUE - enabled, FALSE - disabled
 */
void dof6_rounding_function_enable ( bool set );
/**
 * @brief dof6_gyro_set_hp_filter_cutoff_freq
 * - Gyroscope high-pass filter cutoff frequency selection
 * @param set
 * Desired high-pass filter cutoff frequency as defined in the hp_cutoff_freq_t structure
 * @return
 * 0 if successful, -1 if failed
 */
int8_t dof6_gyro_set_hp_filter_cutoff_freq(hp_cutoff_freq_t set);
/**
 * @brief dof6_accel_low_pass_filter2_enable
 * - Accelerometer low-pass filter LPF2 selection
 * @param set
 * TRUE - enabled, FLASE - disabled
 */
void dof6_accel_low_pass_filter2_enable(bool set);
/**
 * @brief dof6_accel_slope_and_high_pass_config
 * - Accelerometer slope filter and high-pass filter configuration and cutoff setting
 * @param configuration
 * Desired configuration as defined in the slope_hp_config_t structure
 * @return
 * 0 if successful, -1 if failed
 */
int8_t dof6_accel_slope_and_high_pass_config(slope_hp_config_t configuration);
/**
 * @brief dof6_accel_slope_filter_enable
 * - Accelerometer slope filter / high-pass filter selection
 * @param set
 * TRUE - enabled, FALSE - disabled
 */
void dof6_accel_slope_filter_enable(bool set);
/**
 * @brief dof6_6d_low_pass_enable
 * - Low-pass filter on 6D function selection
 * @param set
 * TRUE - enabled, FALSE - disabled
 */
void dof6_6d_low_pass_enable(bool set);
/**
 * @brief dof6_accel_z_enable
 * - Accelerometer Z-axis output enable
 * @param set
 * TRUE - enabled, FALSE - disabled
 */
void dof6_accel_z_enable(bool set);
/**
 * @brief dof6_accel_y_enable
 * - Accelerometer Y-axis output enable
 * @param set
 * TRUE - enabled, FALSE - disabled
 */
void dof6_accel_y_enable(bool set);
/**
 * @brief dof6_accel_x_enable
 * - Accelerometer X-axis output enable
 * @param set
 * TRUE - enabled, FALSE - disabled
 */
void dof6_accel_x_enable(bool set);
/**
 * @brief dof6_gyro_x_enable
 * - Gyroscope pitch axis (X) output enable
 * @param set
 * TRUE - enabled, FALSE - disabled
 */
void dof6_gyro_x_enable(bool set);
/**
 * @brief dof6_gyro_y_enable
 * - Gyroscope roll axis (Y) output enable
 * @param set
 * TRUE - enabled, FALSE - disabled
 */
void dof6_gyro_y_enable(bool set);
/**
 * @brief dof6_gyro_z_enable
 * - Gyroscope yaw axis (Z) output enable
 * @param set
 * TRUE - enabled, FALSE - disabled
 */
void dof6_gyro_z_enable(bool set);
/**
 * @brief dof6_reset_pedometer_counter
 * - Reset pedometer step counter
 */
void dof6_reset_pedometer_counter();
/**
 * @brief dof6_significant_motion_enable
 * - Enable significant motion function
 * @param set
 * TRUE - enabled, FALSE - disabled
 */
void dof6_significant_motion_enable(bool set);

/*******************************************************/
/**
 * @brief dof6_is_free_fall
 * - Free-fall event detection status.
 * @return
 * 1 if free-fall event detected, 0 if not
 */
int8_t dof6_is_free_fall();
/**
 * @brief dof6_is_sleep_event
 * - Sleep event status
 * @return
 * 1 if sleep event detected, 0 if not
 */
int8_t dof6_is_sleep_event();
/**
 * @brief dof6_is_wakeup_event
 * - Wakeup event detection status
 * @return
 * 1 if wakeup event detected, 0 if not
 */
int8_t dof6_is_wakeup_event();
/**
 * @brief dof6_is_wakeup_event_on_x
 * - Wakeup event detection status on X-axis
 * @return
 * 1 if wakeup event on X-axis detected, 0 if not
 */
int8_t dof6_is_wakeup_event_on_x();
/**
 * @brief dof6_is_wakeup_event_on_y
 * - Wakeup event detection status on Y-axis
 * @return
 * 1 if wakeup event on Y-axis detected, 0 if not
 */
int8_t dof6_is_wakeup_event_on_y();
/**
 * @brief dof6_is_wakeup_event_on_z
 * - Wakeup event detection status on Z-axis
 * @return
 * 1 if wakeup event on Z-axis detected, 0 if not
 */
int8_t dof6_is_wakeup_event_on_z();
/**
 * @brief dof6_is_tap_event
 * - Tap event detection status
 * @return
 * 1 if tap event detected, 0 if not
 */
int8_t dof6_is_tap_event();
/**
 * @brief dof6_is_single_tap_event
 * - Single-tap event status
 * @return
 * 1 if single-tap event detected, 0 if not
 */
int8_t dof6_is_single_tap_event();
/**
 * @brief dof6_is_double_tap_event
 * - Double-tap event detection status
 * @return
 * 1 of double-tap event detected, 0 if not
 */
int8_t dof6_is_double_tap_event();
/**
 * @brief dof6_get_tap_detection_sign
 * - Sign of acceleration detected by tap event
 * @return
 * 0 - positive sign of acceleration detected by tap event
 * 1 - negative sign of acceleration detected by tap event
 */
int8_t dof6_get_tap_detection_sign();
/**
 * @brief dof6_is_tap_event_on_x
 * - Tap event detection status on X-axis
 * @return
 * 1 if tap event on X-axis detected, 0 if not
 */
int8_t dof6_is_tap_event_on_x();
/**
 * @brief dof6_is_tap_event_on_y
 * - Tap event detection status on y-axis
 * @return
 * 1 if tap event on y-axis detected, 0 if not
 */
int8_t dof6_is_tap_event_on_y();
/**
 * @brief dof6_is_tap_event_on_z
 * - Tap event detection status on z-axis
 * @return
 * 1 if tap event on y-axis detected, 0 if not
 */
int8_t dof6_is_tap_event_on_z();
/**
 * @brief dof6_is_changed_position
 * - Interrupt active for change position portrait, landscape, face-up, face-down
 * @return
 * 1 if change of position detected, 0 if not
 */
int8_t dof6_is_changed_position();
/**
 * @brief dof6_is_high_event_z
 * - Z-axis high event (over threshold)
 * @return
 * 1 - event (over threshold) detected
 * 0 - event not detected
 */
int8_t dof6_is_high_event_z();
/**
 * @brief dof6_is_low_event_z
 * - Z-axis high event (under threshold)
 * @return
 * 1 - event (under threshold) detected
 * 0 - event not detected
 */
int8_t dof6_is_low_event_z();
/**
 * @brief dof6_is_high_event_y
 * - Y-axis high event (over threshold)
 * @return
 * 1 - event (over threshold) detected
 * 0 - event not detected
 */
int8_t dof6_is_high_event_y();
/**
 * @brief dof6_is_low_event_y
 * - Y-axis high event (under threshold)
 * @return
 * 1 - event (under threshold) detected
 * 0 - event not detected
 */
int8_t dof6_is_low_event_y();
/**
 * @brief dof6_is_high_event_x
 * - X-axis high event (over threshold)
 * @return
 * 1 - event (over threshold) detected
 * 0 - event not detected
 */
int8_t dof6_is_high_event_x();
/**
 * @brief dof6_is_low_event_x
 * - X-axis high event (under threshold)
 * @return
 * 1 - event (under threshold) detected
 * 0 - event not detected
 */
int8_t dof6_is_low_event_x();
/**
 * @brief dof6_is_boot_running
 * - Boot running flag signal
 * @return
 * 0 - no boot running, 1 - boot running
 */
int8_t dof6_is_boot_running();
/**
 * @brief dof6_is_new_temp_data_available
 * - Temperature new data available
 * @return
 * 1 - a new set of data is available at temperature sensor output
 * 0 - no set of data is available at temperature sensor output
 */
int8_t dof6_is_new_temp_data_available();
/**
 * @brief dof6_is_new_gyro_data_available
 * - Gyroscope new data available
 * @return
 * 0 - no set of data available at gyroscope output;
 * 1 - a new set of data is available at gyroscope output)
 */
int8_t dof6_is_new_gyro_data_available();
/**
 * @brief dof6_is_new_accel_data_available
 * - Accelerometer new data available
 * @return
 * 0 - no set of data available at accelerometer output;
 * 1 - a new set of data is available at accelerometer outpu
 */
int8_t dof6_is_new_accel_data_available();
/**
 * @brief dof6_get_temp_data
 * - Reads the temperature data
 * @return
 * 16-bit value of the temperature data
 */
int16_t dof6_get_temp_data();
/**
 * @brief dof6_get_gyro_x
 * - Get's the gyroscope value of the X-axis
 * @return
 * 16bit value of the gyroscope X-axis
 */
int16_t dof6_get_gyro_x();
/**
 * @brief dof6_get_gyro_y
 * - Get's the gyroscope value of the Y-axis
 * @return
 * 16bit value of the gyroscope Y-axis
 */
int16_t dof6_get_gyro_y();
/**
 * @brief dof6_get_gyro_z
 * - Get's the gyroscope value of the Z-axis
 * @return
 * 16bit value of the gyroscope Z-axis
 */
int16_t dof6_get_gyro_z();
/**
 * @brief dof6_get_accel_x
 * - Get's the vlaue of the accelerometer X-axis
 * @return
 * 16bit value of the accelerometer X-axis
 */
int16_t dof6_get_accel_x();
/**
 * @brief dof6_get_accel_y
 * - Get's the vlaue of the accelerometer Y-axis
 * @return
 * 16bit value of the accelerometer Y-axis
 */
int16_t dof6_get_accel_y();
/**
 * @brief dof6_get_accel_z
 * - Get's the vlaue of the accelerometer Z-axis
 * @return
 * 16bit value of the accelerometer Z-axis
 */
int16_t dof6_get_accel_z();
/**
 * @brief dof6_fifo_get_unread_number
 * - Get's the number of unread words (16-bit axes) stored in FIFO
 * @return
 * The number of unread words (16-bit axes) stored in FIFO
 */
uint16_t dof6_fifo_get_unread_number();
/**
 * @brief dof6_fifo_get_watermark_status
 * - Returns the FIFO watermark status.
 * @return
 * 0 - FIFO filling is lower than watermark level
 * 1 - FIFO filling is equal to or higher than the watermark level
 */
int8_t dof6_fifo_get_watermark_status();
/**
 * @brief dof6_fifo_get_overrun_status
 * - Returns the FIFO overrun status
 * @return
 * 0 - FIFO is not completely filled, 1 - FIFO is completely filled
 */
int8_t dof6_fifo_get_overrun_status();
/**
 * @brief dof6_fifo_get_full_status
 * - Returns the FIFO full status
 * @return
 * 0 - FIFO is not full, 1 - FIFO will be full at the next ODR
 */
int8_t dof6_fifo_get_full_status();
/**
 * @brief dof6_fifo_get_empty_status
 * - Returns the FIFO empty status
 * @return
 * 0 - FIFO contains data, 1 - FIFO is empty
 */
int8_t dof6_fifo_get_empty_status();
/**
 * @brief dof6_fifo_get_pattern
 * - Returns the recursive pattern read
 * @return
 * Word of recursive pattern read at the next reading
 */
uint16_t dof6_fifo_get_pattern();
/**
 * @brief dof6_fifo_get_data
 * - Returns the data read from the FIFO
 * @return
 * 16bit value from the FIFO register
 */
uint16_t dof6_fifo_get_data();
/**
 * @brief dof6_get_timestamp
 * - Returns the time stamp
 * @return
 * 16bit value of the time stamp
 */
uint32_t dof6_get_timestamp();
/**
 * @brief dof6_get_step_timestamp
 * - Returns the pedometer time stamp
 * @return
 * 16bit value of the pedometer time stamp
 */
uint16_t dof6_get_step_timestamp();
/**
 * @brief dof6_get_step_count
 * - Returns the pedometer step count
 * @return
 * 16bit value of the pedometer step count
 */
uint16_t dof6_get_step_count();
/**
 * @brief dof6_is_step_detected_in_dt
 * - Pedometer step recognition on delta time status
 * @return
 * 0 - no step recognized during delta time
 * 1 - at least one step recognized during delta time
 */
int8_t dof6_is_step_detected_in_dt();
/**
 * @brief dof6_is_significant_motion
 * - Significant motion event detection status
 * @return
 * 0 - significant motion event not detected
 * 1 - significant motion event detected
 */
int8_t dof6_is_significant_motion();
/**
 * @brief dof6_is_tilt_event
 *-  Tilt event detection status
 * @return
 * 0 - tilt event not detected
 * 1 - tilt event detected
 */
int8_t dof6_is_tilt_event();
/**
 * @brief dof6_is_step_detected
 * - Step detector event detection status
 * @return
 * 0 - step detector event not detected
 * 1 - step detector event detected
 */
int8_t dof6_is_step_detected();
/**
 * @brief dof6_is_step_overflow_detected
 * - Step counter overflow status
 * @return
 * 0 - step counter not overflowed (less than 2^16)
 * 1 - step counter value reached 2^16
 */
int8_t dof6_is_step_overflow_detected();
/**
 * @brief dof6_timer_enable
 * - Time stamp count enable
 * @param set
 * TRUE - enabled, FALSE - disabled
 */
void dof6_timer_enable(bool set);
/**
 * @brief dof6_pedometer_algorithm_enable
 * - Pedometer algorithm enable
 * @param set
 * TRUE - enabled, FALSE - disabled
 */
void dof6_pedometer_algorithm_enable(bool set);
/**
 * @brief dof6_tilt_enable
 * - Tilt calculation enable
 * @param set
 * TRUE - enabled, FALSE - disabled
 */
void dof6_tilt_enable(bool set);
/**
 * @brief dof6_accel_hp_lpf2_enable
 * - Enable accelerometer HP and LPF2 filters
 * @param set
 * TRUE - enabled, FALSE - disabled
 */
void dof6_accel_hp_lpf2_enable(bool set);
/**
 * @brief dof6_tap_x_enable
 * - Enable X direction in tap recognition
 * @param set
 * TRUE - enabled, FALSE - disabled
 */
void dof6_tap_x_enable(bool set);
/**
 * @brief dof6_tap_y_enable
 * - Enable Y direction in tap recognition
 * @param set
 * TRUE - enabled, FALSE - disabled
 */
void dof6_tap_y_enable(bool set);
/**
 * @brief dof6_tap_z_enable
 * - Enable Z direction in tap recognition
 * @param set
 * TRUE - enabled, FALSE - disabled
 */
void dof6_tap_z_enable(bool set);
/**
 * @brief dof6_latched_interrupt_enable
 * - Latched interrupt enable/disable
 * @param set
 * TRUE - enable, FALSE - disable
 */
void dof6_latched_interrupt_enable(bool set);
/**
 * @brief dof6_4d_enable
 * - 4D orientation detection enable (Z-axis position detection is disabled).
 * @param set
 * TRUE - enabled, FALSE - disabled
 */
void dof6_4d_enable(bool set);

/**********************************************************/
/**
 * @brief dof6_6d_set_threshold
 * - Set the threshold for D6D function
 * @param threshold
 * Desired threshold as defined in the d6d_threshold_t structure
 * @return
 * 0 if successful, -1 if failed
 */
int8_t dof6_6d_set_threshold(d6d_threshold_t threshold);
/**
 * @brief dof6_tap_set_threshold
 * - Set the threshold for tap recognition
 * @param threshold
 * Desired threshold, cannot be over 15
 * @return
 * 0 if successful, -1 if failed
 */
int8_t dof6_tap_set_threshold(uint8_t threshold);
/**
 * @brief dof6_double_tap_set_time_gap
 * - Duration of maximum time gap for double tap recognition, the maximum time
 * between two consecutive detected taps to determine a double tap event.
 * @param max_time_tap
 * Desired time gap, cannot be over 7
 * @return
 * 0 if successful, -1 if failed
 */
int8_t dof6_double_tap_set_time_gap(uint8_t max_time_tap);
/**
 * @brief dof6_tap_set_quiet_time
 * - Set expected quiet time after a tap detection.
 * Quiet time is the time after the first detected tap in which there must not be any
 * overthreshold event.
 * @param quiet_time
 * Desired quiet_time, cannot be over 3
 * @return
 * 0 if successful, -1 if failed
 */
int8_t dof6_tap_set_quiet_time(uint8_t quiet_time);
/**
 * @brief dof6_tap_set_shock_time
 * - Set maximum duration of overthreshold event.
 * Maximum duration is the maximum time of an overthreshold signal detection to be
 * recognized as a tap event
 * @param duration
 * Desired shock time, can't be over 3
 * @return
 * 0 if successful, -1 if failed
 */
int8_t dof6_tap_set_shock_time( uint8_t duration );
/**
 * @brief dof6_tap_event_select
 * - Single/double-tap event enable
 * @param select
 * SINGLE_ONLY - only single-tap enabled
 * SINGLE_AND_DOUBLE - both single and double tap enabled
 * @return
 * 0 if successful, -1 if failed
 */
int8_t dof6_tap_event_select(tap_wakeup_t select);
/**
 * @brief dof6_inactivity_event_enable
 * - Inactivity event enable
 * @param set
 * TRUE - enabled, FALSE - disabled
 */
void dof6_inactivity_event_enable(bool set);
/**
 * @brief dof6_wakeup_set_threshold
 * - Set the threshold for wakeup
 * @param threshold
 * Desired threshold, cannot be over 31
 * @return
 * 0 if successful, -1 if failed
 */
int8_t dof6_wakeup_set_threshold(uint8_t threshold);
/**
 * @brief dof6_free_fall_set_duration
 * - Set the free fall duration event.
 * @param duration
 * Desired duration, cannot be over 63
 * @return
 * 0 if successful, -1 if failed
 */
int8_t dof6_free_fall_set_duration(uint8_t duration);
/**
 * @brief dof6_wakeup_set_duration
 * - Wake up duration event
 * @param duration
 * Duration is calculated as 1LSB = 1 ODR_time. Parameter cannot be over 3 (00000011)
 * @return
 * 0 if successful, -1 if failed
 */
int8_t dof6_wakeup_set_duration(uint8_t duration);
/**
 * @brief dof6_timer_set_resolution
 * - Time stamp register resolution setting
 * @param resolution
 * 0 - 1LSB = 6.4 ms
 * 1 - 1LSB = 25 μs
 * @return
 * 0 if successful, -1 if failed
 */
int8_t dof6_timer_set_resolution(timer_resolution_t resolution);
/**
 * @brief dof6_sleep_set_duration
 * - Duration to go in sleep mode
 * @param duration
 * Desired duration, cannot be over 15
 * @return
 * 0 if successful, -1 if failed
 */
int8_t dof6_sleep_set_duration(uint8_t duration);
/**
 * @brief dof6_free_fall_set_threshold
 * - Free fall threshold setting.
 * @param threshold
 * Desired threshold, as defined in the free_fall_threshold_t structure
 * @return
 * 0 if successful, -1 if failed
 */
int8_t dof6_free_fall_set_threshold (free_fall_threshold_t threshold);
/**
 * @brief dof6_int1_set_routing_functions
 * - Routing different interrupts on the INT1 pin. Create an instance of the int1_routing_t struct,
 * and set the desired interrupts to TRUE for them to be routed on the INT1 pin
 * @param interrupt1
 * int1_routing_t type parameter, all fields set to TRUE will be enabled interrupts,
 * other will be disabled
 * @return
 * 0 if successful, -1 if failed
 */
int8_t dof6_int1_set_routing_functions(int1_routing_t interrupt1);
/**
 * @brief dof6_int2_set_routing_functions
 * - Routing different interrupts on the INT2 pin. Create an instance of the int2_routing_t struct,
 * and set the desired interrupts to TRUE for them to be routed on the INT2 pin
 * @param interrupt2
 * int2_routing_t type parameter, all fields set to TRUE will be enabled interrupts,
 * other will be disabled
 * @return
 */
int8_t dof6_int2_set_routing_functions(int2_routing_t interrupt2);

/** EMBEDDED FUNCTIONS REGISTERS AND IT'S FUNCTIONS **/

/**
 * @brief dof6_pedometer_set_internal_full_scale
 * - Sets the internal full scale used in pedometer functions.
 * @param scale
 * 0: internal full scale = 2 g.
 * 1: internal full scale 4 g (acclerometer full scale must be ≥ 4 g, otherwise internal full scale is 2 g
 * @return
 * 0 if successful, -1 if failed
 */
int8_t dof6_pedometer_set_internal_full_scale(acl_range_t scale);
/**
 * @brief dof6_pedometer_set_minimum_threshold
 * - Configurable minimum threshold for the pedometer
 * @param threshold
 * Desired threshold, cannot be over 31
 * @return
 * 0 if successful, -1 if failed
 */
int8_t dof6_pedometer_set_minimum_threshold(uint8_t threshold);
/**
 * @brief dof6_significant_motion_set_threshold
 * - Significant motion threshold
 * @param threshold
 * Desired threshold
 * @return
 * 0 if successful, -1 if failed
 */
int8_t dof6_significant_motion_set_threshold(uint8_t threshold);
/**
 * @brief dof6_pedometer_set_debounce_time
 * - If the time between steps is greater than DEB_TIME*80ms, the debouncer is reactivated
 * @param debounce_time
 * Desired debounce time
 * @return
 * 0 if successful, -1 if failed
 */
int8_t dof6_pedometer_set_debounce_time(uint8_t debounce_time);
/**
 * @brief dof6_pedometer_set_debounce_number
 * - Minimum number of steps to increment step counter (debouncer)
 * @param number
 * Desired number, cannot be over 7
 * @return
 * 0 if successful, -1 if failed
 */
int8_t dof6_pedometer_set_debounce_number(uint8_t number);
/**
 * @brief dof6_pedometer_set_time_period_value
 * - Sets the desired period value for step detection
 * @param time_period
 * Desired time period
 * @return
 * 0 if successful, -1 if failed
 */
int8_t dof6_pedometer_set_time_period_value(uint8_t time_period);

#ifdef __cplusplus
} // extern "C"
#endif

#endif

/*** End of File **************************************************************/
