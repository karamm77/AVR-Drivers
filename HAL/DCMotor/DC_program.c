
#include "STD_TYPES.h"

#include "DIO_interface.h"
#include "DC_interface.h"
#include "DC_cfg.h"
#include "DC_prv.h"


void DC_voidClockWise(uint8 Copy_u8Port,uint8 Copy_u8PinA,uint8 Copy_u8PinB)
{
	DIO_u8SetPinValue(Copy_u8Port,Copy_u8PinA,DIO_u8PIN_HIGH);
	DIO_u8SetPinValue(Copy_u8Port,Copy_u8PinB,DIO_u8PIN_LOW);
}


void DC_voidCountrClockWise(uint8 Copy_u8Port,uint8 Copy_u8PinA,uint8 Copy_u8PinB)
{
	DIO_u8SetPinValue(Copy_u8Port,Copy_u8PinB,DIO_u8PIN_LOW);
	DIO_u8SetPinValue(Copy_u8Port,Copy_u8PinA,DIO_u8PIN_HIGH);
}

void DC_voidStop(uint8 Copy_u8Port,uint8 Copy_u8PinA,uint8 Copy_u8PinB)
{
	DIO_u8SetPinValue(Copy_u8Port,Copy_u8PinB,DIO_u8PIN_LOW);
	DIO_u8SetPinValue(Copy_u8Port,Copy_u8PinA,DIO_u8PIN_LOW);
}
