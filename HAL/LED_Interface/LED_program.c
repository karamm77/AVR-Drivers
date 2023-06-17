#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include <util/delay.h>


#include "DIO_interface.h"

#include "LED_cfg.h"
#include "LED_prv.h"
#include "LED_interface.h"


void Led_voidLedON(Led_t *object)
{
	DIO_u8SetPinDirection(object->Port, object->Pin, DIO_u8PIN_OUTPUT);

		if(object->Type == Active_High)
		{
			DIO_u8SetPinValue(object->Port, object->Pin, DIO_u8PIN_HIGH);
		}
		else if(object->Type == Active_Low)
		{
			DIO_u8SetPinValue(object->Port, object->Pin, DIO_u8PIN_LOW);

		}
}


void Led_voidLedOFF(Led_t *object)
{
	DIO_u8SetPinDirection(object->Port, object->Pin, DIO_u8PIN_OUTPUT);

		if(object->Type == Active_Low)
		{
			DIO_u8SetPinValue(object->Port, object->Pin, DIO_u8PIN_LOW);
		}
		else if(object->Type == Active_High)
		{
			DIO_u8SetPinValue(object->Port, object->Pin, DIO_u8PIN_HIGH);

		}
}



void Led_voidLedToggle(Led_t *object)
{
	DIO_u8SetPinDirection(object->Port, object->Pin, DIO_u8PIN_OUTPUT);

	DIO_u8SetPinValue(object->Port, object->Pin, DIO_u8PIN_HIGH);
	_delay_ms(500);
	DIO_u8SetPinValue(object->Port, object->Pin, DIO_u8PIN_LOW);
	_delay_ms(500);

}

