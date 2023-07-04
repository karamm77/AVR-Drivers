#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "DIO_interface.h"
#include "ADC_interface.h"

#include "CLCD_interface.h"
#include "Keypad_interface.h"

#include "util/delay.h"

void main(void)
{
	uint16 Local_u8DigitalVal = 0;
	uint16 Local_u8DigitalValMV = 0;

	uint16 Local_u8FinalVolRead = 0;
	uint16 Local_u8FinalResRead = 0;
	uint16 Resistance = 0;
	uint8 Read = 0xFF;
/*******************************************/

	/*** Set LDR as input for A0 ***/

	DIO_u8SetPinDirection(DIO_u8PORTA, DIO_u8PIN0, DIO_u8PIN_INPUT);

	/*** Initializing LCD and ADC and Keypad ***/
	ADC_voidInit();
	ADC_voidEnable();

	CLCD_voidInit();
	KEYPAD_voidInit();


	CLCD_u8SendString("System:");
	CLCD_voidGoToXY(1, 0);
	CLCD_u8SendString("1 Vol");
	CLCD_voidGoToXY(2, 0);
	CLCD_u8SendString("2 OHM");

/*********************************************/


	do
	{
		Read = KEYPAD_GetPressedKey();
	}
	while(Read != 0xFF);

	while (1)
	{
		Read = KEYPAD_GetPressedKey();

		switch (Read)
		{
		case 1:
			CLCD_voidClrScr();
			while (1)
			{
				CLCD_voidGoToXY(0, 0);
				CLCD_u8SendString("Vol Sys");
				CLCD_voidGoToXY(1, 0);

				Local_u8DigitalVal = ADC_uint16GetDigitalValue(ADC_uint8_CHANNEL_0);
				Local_u8DigitalValMV = (Local_u8DigitalVal * 5000UL) / 1023;
				Local_u8FinalVolRead = Local_u8DigitalValMV / 1000UL;
				_delay_ms(500);

				CLCD_voidSendNumber(Local_u8FinalVolRead);
				CLCD_u8SendString("V");
			}
			break;

		case 2:
			CLCD_voidClrScr();
			while (1)
			{
				CLCD_voidGoToXY(0, 0);
				CLCD_u8SendString("OHM SYS");
				CLCD_voidGoToXY(1, 0);

				Local_u8DigitalVal = ADC_uint16GetDigitalValue(ADC_uint8_CHANNEL_0);
				Local_u8DigitalValMV = (Local_u8DigitalVal * 5000UL) / 1023;
				Resistance = Local_u8DigitalValMV / 40;
				Local_u8FinalResRead = Resistance / 1000UL;
				_delay_ms(1500);

				CLCD_voidSendNumber(Resistance);
				CLCD_u8SendString("OHM");
			}
			break;

		default:
			break;
		}
	}
}
