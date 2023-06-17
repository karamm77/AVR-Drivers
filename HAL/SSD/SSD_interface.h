/**************************************************************************************************/
/**************************************************************************************************/
/**************************************************************************************************/
/*								 Author : Abdelrahman Elnahas 									  */									
/*								 SWC	: SSD													  */
/*								 Layer  : HAL													  */
/**************************************************************************************************/
/**************************************************************************************************/
/**************************************************************************************************/

#ifndef SSD_INTERFACE_H
#define SSD_INTERFACE_H

#include "STD_TYPES.h"
#include "BIT_MATH.h"



#define SSD_ZERO 				0b0111111
#define SSD_ONE					0b0000110
#define SSD_TWO					0b1011011
#define SSD_THREE				0b1001111
#define SSD_FOUR				0b1100110
#define SSD_FIVE				0b1101101
#define SSD_SIX					0b1111101
#define SSD_SEVEN				0b0000111
#define SSD_EIGHT				0b1111111
#define SSD_NINE				0b1101111


#define SSD_PIN0				DIO_PIN0
#define SSD_PIN1				DIO_PIN1
#define SSD_PIN2				DIO_PIN2
#define SSD_PIN3				DIO_PIN4


#define SSD_ZERO_DECODER			0
#define SSD_ONE_DECODER				1
#define SSD_TWO_DECODER				2
#define SSD_THREE_DECODER			3
#define SSD_FOUR_DECODER			4
#define SSD_FIVE_DECODER			5
#define SSD_SIX_DECODER				6
#define SSD_SEVEN_DECODER			7
#define SSD_EIGHT_DECODER			8
#define SSD_NINE_DECODER			9


#define SSD_COM_ANODE				1
#define SSD_COM_CATHODE				0



typedef struct name
{
	uint8 SSD_uint8Port;
	uint8 SSD_uint8Common;
	uint8 SSD_uint8EnablePort;
	uint8 SSD_uint8EnablePin;
}SSD_t;



void SSD_vidInitSSD(SSD_t * Copy_SSDInfo);

void SSD_vidDisplaySSD(SSD_t * Copy_SSDInfo , uint8 Copy_uint8Number);






typedef struct name2
{
	uint8 SSD_uint8Port;
	uint8 SSD_uint8Pins[4];
	uint8 SSD_uint8Common;
	uint8 SSD_uint8EnablePort;
	uint8 SSD_uint8EnablePin;
}SSD_t_decoder;

void SSD_vidInitSSDDecoder(SSD_t_decoder * Copy_SSDInfo);

void SSD_vidDisplaySSDDecoder(SSD_t_decoder * Copy_SSDInfo , uint8 Copy_uint8Number);

void SSD_vidDisableSSDDecoder(SSD_t_decoder * Copy_SSDInfo) ;


#endif 

