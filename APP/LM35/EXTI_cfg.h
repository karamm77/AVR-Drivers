/**
 * @this file configures the EXTI module in prebuilt configuration method
 *
 */



#ifndef EXTI_CFG_H_
#define EXTI_CFG_H_



/**
 * options for control sense of INT0 are 1- EXTI_u8_LOW_LEVEL
 * 			   							 2- EXTI_u8_LOGICAL_CHANGE
 * 			  							 3- EXTI_u8FALLING_EDGE
 * 										 4-EXTI_u8RISING_EDGE
 */
#define EXTI_INT0_CTRL_SENSE			EXTI_u8FALLING_EDGE


/**
 * Options for INT0 Initial State: 1- ENABLED
 * 								   2- DISABLED
 */

#define EXTI_INT0_STATE					ENABLED


/**
 * options for control sense of INT1 are 1- EXTI_u8_LOW_LEVEL
 * 			   							 2- EXTI_u8_LOGICAL_CHANGE
 * 			  							 3- EXTI_u8FALLING_EDGE
 * 										 4-EXTI_u8RISING_EDGE
 */
#define EXTI_INT1_CTRL_SENSE			EXTI_u8FALLING_EDGE

/**
 * Options for INT1 Initial State: 1- ENABLED
 * 								   2- DISABLED
 */


#define EXTI_INT1_STATE					ENABLED


/**
 * options for control sense of INT2 are 1- EXTI_u8FALLING_EDGE
 * 			   							 2- EXTI_u8RISING_EDGE

 */
#define EXTI_INT2_CTRL_SENSE			EXTI_u8FALLING_EDGE

/**
 * Options for INT2 Initial State: 1- ENABLED
 * 								   2- DISABLED
 */


#define EXTI_INT2_STATE					ENABLED



#endif
