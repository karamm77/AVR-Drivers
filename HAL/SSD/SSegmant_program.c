
/**************************************************************************************************/
/**************************************************************************************************/
/**************************************************************************************************/
/*								 Author : KARAM ALBENDARY 										  */
/*								 SWC	: 7SEGMANT												 */
/*								 Layer  : HAL
 * 									Program.c													  */
/**************************************************************************************************/
/**************************************************************************************************/
/**************************************************************************************************/





#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "DIO_interface.h"
#include "SSegmant_interface.h"
#include "SSegmant_prv.h"
#include "SSegmant_cfg.h"
#include "DIO_reg.h"




void SSD_voidInit(uint8 Copy_u8Port, uint8 Copy_u8Pin)
{

	DIO_u8SetPinDirection(Copy_u8Port, Copy_u8Pin, DIO_u8PIN_OUTPUT);

#if CoMMON_USED == Common_Anode
	DIO_u8SetPinValue(Copy_u8Port, Copy_u8Pin, DIO_u8PIN_LOW);
#elif CoMMON_USED == Common_Cathod
	DIO_u8SetPinValue(Copy_u8Port, Copy_u8Pin, DIO_u8PIN_HIGH);
#endif

}



void SSD_voidDecoderInit(void)
{
	DIO_u8SetPortDirection(DIO_u8PORTB, 0b00010111);
}

uint8 SSD_u8SSDisplay(uint8 Copy_u8Value)
{

	uint8 dummy = 0;

	dummy = ((0b00000111) & Copy_u8Value);
	dummy |=	((GET_BIT(Copy_u8Value,3))<<4);

	PORTB = dummy;


	return PORTB;
}
