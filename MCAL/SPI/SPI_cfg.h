#ifndef SPI_CFG_H_
#define SPI_CFG_H_

/*
 * Choose the node is master or slave	1:MASTER
 * 										2:SLAVE
 */

#define NODE_STATE						MASTER


/*
 * Choose the idle state "State of no communication" either 1:CPOL_RISING
 * 															2:CPOL_FALLING
 */

#define CPOL_STATE						CPOL_RISING


/*
 * Choose the clock phase; setup"send first" or sample"receive first" 1:CPHA_SETUP
 * 																	  2:CPHA_SAMPLE
 *
 *
 */

#define CPHA_STATE						CPHA_SETUP

#define PRESCALER_USED					PRESCALER_128

/*
 * choose the order of sending data										1:LSB_ORDER
 * 																		2:MSB_ORDER
 */

#define ORDER_USED						LSB_ORDER












#define
