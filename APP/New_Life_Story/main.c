#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "CLCD_interface.h"
#include <util/delay.h>

 const uint8 Copy_u8Pattern[]={  0x0E,
		  0x0A,
		  0x0E,
		  0x04,
		  0x0E,
		  0x04,
		  0x0A,
		  0x0A,
		  0x0E,
		   0x0A,
		   0x0E,
		   0x05,
		   0x0E,
		   0x04,
		   0x0A,
		   0x0A,
		   0x0E,
		   0x0A,
		   0x0E,
		   0x04,
		   0x0E,
		   0x05,
		   0x0A,
		   0x0A,
		   0x1E,
		   0x02,
		   0x0C,
		   0x10,
		   0x1E,
		   0x00,
		   0x00,
		   0x00

};

void main(void)
{
CLCD_voidInit();
LCD_voidWriteSpecialChar(Copy_u8Pattern,0,0,0);
_delay_ms(1000);
CLCD_voidClrScr();
LCD_voidWriteSpecialChar(Copy_u8Pattern,0,0,1);
_delay_ms(1000);
CLCD_voidClrScr();
LCD_voidWriteSpecialChar(Copy_u8Pattern,0,0,2);
_delay_ms(1000);
CLCD_voidClrScr();
LCD_voidWriteSpecialChar(Copy_u8Pattern,0,0,3);
_delay_ms(1000);
CLCD_voidClrScr();
LCD_voidWriteSpecialChar(Copy_u8Pattern,0,0,4);
_delay_ms(1000);
CLCD_voidClrScr();

	CLCD_voidGotoXY(1,1);
	CLCD_u8SendString("HAMOKSHA WOKE!");
	_delay_ms(2000);
	CLCD_voidClrScr();

	CLCD_voidGotoXY(1,1);
	CLCD_u8SendString("HAMOKSHA WAVE");



	LCD_voidWriteSpecialChar(Copy_u8Pattern,1,2,0);
	_delay_ms(2000);
	CLCD_voidClrScr();
	LCD_voidWriteSpecialChar(Copy_u8Pattern,2,2,1);
	_delay_ms(1000);
	CLCD_voidClrScr();
	LCD_voidWriteSpecialChar(Copy_u8Pattern,1,2,2);
	_delay_ms(1000);
	CLCD_voidClrScr();
	LCD_voidWriteSpecialChar(Copy_u8Pattern,2,2,3);
	_delay_ms(1000);
	CLCD_voidClrScr();
	LCD_voidWriteSpecialChar(Copy_u8Pattern,1,2,4);
	_delay_ms(1000);
	CLCD_voidClrScr();
	LCD_voidWriteSpecialChar(Copy_u8Pattern,2,2,5);
	_delay_ms(1000);
	CLCD_voidClrScr();

	CLCD_voidGotoXY(1,1);
	CLCD_u8SendString("HAMOKSHA SLEEP");
	_delay_ms(1000);
	CLCD_voidClrScr();

	LCD_voidWriteSpecialChar(Copy_u8Pattern,0,2,5);
	LCD_voidWriteSpecialChar(Copy_u8Pattern,3,1,5);
	_delay_ms(1000);
	CLCD_voidClrScr();
	LCD_voidWriteSpecialChar(Copy_u8Pattern,0,2,5);

	LCD_voidWriteSpecialChar(Copy_u8Pattern,3,0,6);
	_delay_ms(1000);
	CLCD_voidClrScr();
	LCD_voidWriteSpecialChar(Copy_u8Pattern,0,2,5);

	LCD_voidWriteSpecialChar(Copy_u8Pattern,3,1,5);
	_delay_ms(1000);
	CLCD_voidClrScr();
	LCD_voidWriteSpecialChar(Copy_u8Pattern,0,2,5);

	LCD_voidWriteSpecialChar(Copy_u8Pattern,3,0,6);
	_delay_ms(1000);
	CLCD_voidClrScr();
	CLCD_voidGotoXY(1,1);
	CLCD_u8SendString("BYEEEEE");













    while (1)
    {

    }






}
