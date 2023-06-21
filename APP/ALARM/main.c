/******************************************************/
/******************Alarm Project***********************/
/**************** Auth: Karam ************************/
/*******************************************************/






#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "DIO_interface.h"
#include "CLCD_interface.h"
#include "Keypad_interface.h"
#include "util/delay.h"

void main(void)
{
	uint8 Alarm = 0;
	uint8 Read = 0xFF;


	CLCD_voidInit();
	KEYPAD_voidInit();

	DIO_u8SetPinDirection(DIO_u8PORTC, DIO_u8PIN6,DIO_u8PIN_OUTPUT);




	while(1)
	{

		while(Read != 13)
		{
			Read = KEYPAD_GetPressedKey();
			if(Read != 0xFF)
			{
				CLCD_voidSendNumber(Read);
				if(Read != 13)
				{
					Alarm = (Alarm * 10) + Read;
				}
			}
		}
		_delay_ms(500);
		CLCD_voidClrScr();

		while(Alarm != 0)
		{
			Alarm --;
			_delay_ms(1000);
			CLCD_voidClrScr();
			CLCD_voidSendNumber(Alarm);


		}

		_delay_ms(500);

		CLCD_voidClrScr();

		while(Alarm == 0)
		{

			_delay_ms(500);
			DIO_u8SetPinValue(DIO_u8PORTC, DIO_u8PIN6, DIO_u8PIN_HIGH);
			CLCD_u8SendString("Wake Up!!!");
		}





	}

}
