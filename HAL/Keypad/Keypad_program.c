#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include <util/delay.h>

#include "Keypad_cfg.h"
#include "Keypad_interface.h"
#include "Keypad_prv.h"



void KEYPAD_voidInit(void)
{
	DIO_u8SetPortDirection(KPD_u8Row_PORT, 0b00000000); //Set as Input
	DIO_u8SetPortValue(KPD_u8Row_PORT, 0b00111100);//Set as High to get pull up on Rows

	DIO_u8SetPortDirection(KPD_u8Col_PORT, 0b11101000);
	DIO_u8SetPortValue(KPD_u8Col_PORT, 0b11101000);
}

uint8 KEYPAD_GetPressedKey(void)
{
	/** No pressed key**/
	uint8 Local_u8PressedKey = KEY_PRESSED_VAL; //All High Not Pressed

	uint8 Local_u8RowCounter, Local_u8ColCounter, Local_u8KeyState;

	static uint8 Local_u8ColArr[COL_NUM] = {KPD_u8Col1_PIN,KPD_u8Col2_PIN,KPD_u8Col3_PIN,KPD_u8Col4_PIN};
	static uint8 Local_u8CRowArr[ROW_NUM] = {KPD_u8Row1_PIN,KPD_u8Row2_PIN,KPD_u8Row3_PIN,KPD_u8Row4_PIN};
	static uint8 Local_u8KPDArr[ROW_NUM][COL_NUM] = KPD_u8BUTTON_ARR;



	/** To send the sequence **/
	/** Activate The columns **/
	for(Local_u8ColCounter = 0; Local_u8ColCounter < COL_NUM; Local_u8ColCounter++)
	{

		DIO_u8SetPinValue(KPD_u8Col_PORT, Local_u8ColArr[Local_u8ColCounter], DIO_u8PIN_LOW);

		for(Local_u8RowCounter = 0; Local_u8RowCounter < ROW_NUM; Local_u8RowCounter++)
		{
			/** Read the state of bush button of each row**/
			DIO_u8GetPinValue(KPD_u8Row_PORT, Local_u8CRowArr[Local_u8RowCounter], &Local_u8KeyState);

			/** If low so it is pressed **/
			if(Local_u8KeyState == DIO_u8PIN_LOW)
			{
				//_delay_ms(10); /** debouncing **/
				Local_u8PressedKey = Local_u8KPDArr[Local_u8RowCounter][Local_u8ColCounter];
				DIO_u8GetPinValue(KPD_u8Row_PORT, Local_u8CRowArr[Local_u8RowCounter], &Local_u8KeyState);
				while(Local_u8KeyState == DIO_u8PIN_LOW)
				{
					DIO_u8GetPinValue(KPD_u8Row_PORT, Local_u8CRowArr[Local_u8RowCounter], &Local_u8KeyState);
				}
				return Local_u8PressedKey;
			}
		}
		DIO_u8SetPinValue(KPD_u8Col_PORT, Local_u8ColArr[Local_u8ColCounter], DIO_u8PIN_HIGH);

	}





	return Local_u8PressedKey;

}
