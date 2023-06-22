#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "DIO_interface.h"
#include "CLCD_interface.h"
#include "ADC_interface.h"


void main(void)
{

/***************Configuring Led level indicators for only two levels********/


	DIO_u8SetPinDirection(DIO_u8PORTA, DIO_u8PIN5, DIO_u8PIN_OUTPUT);/**Led 1**/
	DIO_u8SetPinDirection(DIO_u8PORTA, DIO_u8PIN6, DIO_u8PIN_OUTPUT);/**Led 2**/

/******Selecting A0 and A1 For Channel 0 and 1 for ADC and make it INPUT*******/


	DIO_u8SetPinDirection(DIO_u8PORTA, DIO_u8PIN0, DIO_u8PIN_INPUT);/**Channel 0**/
	DIO_u8SetPinDirection(DIO_u8PORTA, DIO_u8PIN1, DIO_u8PIN_INPUT);/**Channel 1**/

/*************** Initialization ***********************************/
	CLCD_voidInit();
	ADC_voidInit();
	ADC_voidEnable();

	CLCD_u8SendString("Start");


	uint16 Local_u16GigitalVal1 = 0;
	uint16 Local_u16GigitalVal2 = 0;
	uint16 Local_u16GigitalVal1MV = 0;
	uint16 Local_u16GigitalVal2MV = 0;

	while(1)
	{

		Local_u16GigitalVal1 = ADC_uint16GetDigitalValue(ADC_uint8_CHANNEL_0);
		Local_u16GigitalVal1MV = (Local_u16GigitalVal1*5000UL)/1024;

		CLCD_voidClrScr();
		CLCD_voidSendNumber(Local_u16GigitalVal1MV);
		if(Local_u16GigitalVal1 > 230)/**** if true turn led 1 on***/
		{
			DIO_u8SetPinValue(DIO_u8PORTA, DIO_u8PIN5, DIO_u8PIN_HIGH);/**Led 1**/

		}
		else
		{
			DIO_u8SetPinValue(DIO_u8PORTA, DIO_u8PIN5, DIO_u8PIN_LOW);/**Led 1**/

		}


		Local_u16GigitalVal2 = ADC_uint16GetDigitalValue(ADC_uint8_CHANNEL_1);
		Local_u16GigitalVal2MV = (Local_u16GigitalVal2*5000UL)/1024;


		CLCD_voidClrScr();

		CLCD_voidSendNumber(Local_u16GigitalVal2MV);

		if(Local_u16GigitalVal2 > 230)
		{
			DIO_u8SetPinValue(DIO_u8PORTA, DIO_u8PIN6, DIO_u8PIN_HIGH);/**Led 2**/

		}
		else
		{
			DIO_u8SetPinValue(DIO_u8PORTA, DIO_u8PIN6, DIO_u8PIN_LOW);/**Led 2**/
		}







	}










}
