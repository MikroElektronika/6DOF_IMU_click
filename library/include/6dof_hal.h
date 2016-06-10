/****************************************************************************
* Title                 :   6DOF IMU Click
* Filename              :   6dof_hal.h
* Author                :   VM
* Origin Date           :   10/06/2016
* Notes                 :   None
*****************************************************************************/
/**************************CHANGE LIST **************************************
*
*    Date    Software Version    Initials   Description
*  10/06/16    1.0.0               VM      Interface Created.
*
*****************************************************************************/
/**
 * @file 6dof_hal.h
 *  @brief Contains the HAL for working with the 6DOF IMU Click board
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
#ifndef DOF6_HAL_H_
#define DOF6_HAL_H_
/******************************************************************************
* Includes
*******************************************************************************/
#include "stdint.h"
/******************************************************************************
* Preprocessor Constants
*******************************************************************************/
#define READ                    1		// READ BIT
#define WRITE                   0		// WRITE BIT
#define COMMAND_SIZE            1		// COMMAND OR REGISTER SIZE ( Bytes )
#define MAX_BUFF_SIZE           256		// BUFFER SIZE ( Bytes )
/******************************************************************************
* Configuration Constants
*******************************************************************************/

/******************************************************************************
* Macros
*******************************************************************************/
	
/******************************************************************************
* Typedefs
*******************************************************************************/

/******************************************************************************
* Variables
*******************************************************************************/

/******************************************************************************
* Function Prototypes
*******************************************************************************/
#ifdef __cplusplus
extern "C"{
#endif
/**
 * @brief dof6_hal_init
 * Initializes the HAL, sets appropriate function pointers
 * @param address_id
 * I2C device slave address of the 6DOF IMU Click
 */
void dof6_hal_init( uint8_t address_id );

/**
 * @brief dof6_hal_write
 * Writes specified number of bytes to the device
 * @param command
 * Register to which the bytes will be written
 * @param buffer
 * Buffer containing the data to be written
 * @param count
 * Number of bytes to be written
 */
void dof6_hal_write( uint8_t *command,
                    	  uint8_t *buffer,
                    	  uint16_t count );
/**
 * @brief dof6_hal_read
 * Reads specified number of bytes from the device
 * @param command
 * Register from which to start reading
 * @param buffer
 * Pointer to the buffer to which to store the incoming data
 * @param count
 * Number of bytes to be read
 */
void dof6_hal_read( uint8_t *command,
                   		 uint8_t *buffer,
                   		 uint16_t count );

#ifdef __cplusplus
} // extern "C"
#endif

#endif /* CLICKNAME_HAL_H_ */

/*** End of File **************************************************************/
