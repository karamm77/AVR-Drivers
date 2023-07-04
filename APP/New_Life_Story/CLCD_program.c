#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include <util/delay.h>

#include "DIO_interface.h"

#include "CLCD_interface.h"
#include "CLCD_prv.h"
#include "CLCD_cfg.h"


static void voidSendEnablePulse(void)
{
	/*Send enable pulse*/
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN,DIO_u8PIN_HIGH);
	_delay_ms(2);
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN,DIO_u8PIN_LOW);
}


static void voidSetLCDHalfDataPort(uint8 Copy_u8Nipple)
{
	DIO_u8SetPinValue(CLCD_DATA_PORT,CLCD_D4_PIN,GET_BIT(Copy_u8Nipple,0));
	DIO_u8SetPinValue(CLCD_DATA_PORT,CLCD_D5_PIN,GET_BIT(Copy_u8Nipple,1));
	DIO_u8SetPinValue(CLCD_DATA_PORT,CLCD_D6_PIN,GET_BIT(Copy_u8Nipple,2));
	DIO_u8SetPinValue(CLCD_DATA_PORT,CLCD_D7_PIN,GET_BIT(Copy_u8Nipple,3));
}


void CLCD_voidSendCmd(uint8 Copy_u8Cmd)
{
	/*Set RS pin to low for command*/
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_RS_PIN,DIO_u8PIN_LOW);

#if CLCD_RW_CTRL_EN	== ENABLED
	/*Set RW pin to low for write operation*/
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_RW_PIN,DIO_u8PIN_Low);
#endif

#if CLCD_OP_MODE == EIGHT_BIT_MODE
	/*Send the command on data pins*/
	DIO_u8SetPortValue(CLCD_DATA_PORT,Copy_u8Cmd);

	voidSendEnablePulse();

#elif CLCD_OP_MODE == FOUR_BIT_MODE

	voidSetLCDHalfDataPort(Copy_u8Cmd>>4);	/*send the most 4 bits to the LCD*/
	voidSendEnablePulse();

	voidSetLCDHalfDataPort(Copy_u8Cmd);		/*send the least 4 bits to the LCD*/
	voidSendEnablePulse();
#endif
}

void CLCD_voidSendData(uint8 Copy_u8Data)
{

	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_RS_PIN,DIO_u8PIN_HIGH);

#if CLCD_RW_CTRL_EN	== ENABLED
	/*Set RW pin to low for write operation*/
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_RW_PIN,DIO_u8PIN_Low);
#endif

#if CLCD_OP_MODE == EIGHT_BIT_MODE
	/*Send the command on data pins*/
	DIO_u8SetPortValue(CLCD_DATA_PORT,Copy_u8Data);

	voidSendEnablePulse();

#elif CLCD_OP_MODE == FOUR_BIT_MODE

	voidSetLCDHalfDataPort(Copy_u8Data>>4);	/*send the most 4 bits to the LCD*/
	voidSendEnablePulse();

	voidSetLCDHalfDataPort(Copy_u8Data);	/*send the least 4 bits to the LCD*/
	voidSendEnablePulse();
#endif

}

void CLCD_voidInit(void)
{

	DIO_u8SetPinDirection(DIO_u8PORTA, DIO_u8PIN3, DIO_u8PIN_OUTPUT); //RS
	DIO_u8SetPinDirection(DIO_u8PORTA, DIO_u8PIN2, DIO_u8PIN_OUTPUT);//E

	DIO_u8SetPinDirection(DIO_u8PORTB, DIO_u8PIN0, DIO_u8PIN_OUTPUT);//D4
	DIO_u8SetPinDirection(DIO_u8PORTB, DIO_u8PIN1, DIO_u8PIN_OUTPUT);//D4
	DIO_u8SetPinDirection(DIO_u8PORTB, DIO_u8PIN2, DIO_u8PIN_OUTPUT);//D4
	DIO_u8SetPinDirection(DIO_u8PORTB, DIO_u8PIN4, DIO_u8PIN_OUTPUT);//D4

	/*wait for more than 30ms after power on*/
	_delay_ms(40);

	/*Function set command: 2 lines, 5*7 font size*/
#if CLCD_OP_MODE == EIGHT_BIT_MODE
	CLCD_voidSendCmd(0b00111000);

#elif CLCD_OP_MODE == FOUR_BIT_MODE
	voidSetLCDHalfDataPort(0b0010);
	voidSendEnablePulse();
	voidSetLCDHalfDataPort(0b0010);
	voidSendEnablePulse();
	voidSetLCDHalfDataPort(0b1000);
	voidSendEnablePulse();
#endif

	/*Display on/off control: display enable, cursor and blink disable*/
	CLCD_voidSendCmd(0b00001100);

	/*Display clear*/
	CLCD_voidSendCmd(1);
}


uint8 CLCD_u8SendString(const char* Copy_chString)
{
	uint8 Local_u8ErrorState= OK;
	if(Copy_chString != NULL)
	{
		uint8 Local_u8Counter=0u;
		while(Copy_chString[Local_u8Counter] != '\0')
		{
			CLCD_voidSendData(Copy_chString[Local_u8Counter]);
			Local_u8Counter++;
		}
	}
	else
	{
		Local_u8ErrorState= NULL_PTR_ERR;
	}
	return Local_u8ErrorState;
}

void CLCD_voidSendNumber(sint32 Copy_s32Number)
{
	char Local_u8ChArr[10];
	uint8 Local_RightDigit;
	uint8 Local_u32Counter1 = 0;
	sint8 Local_u32Counter2 = 0;

	if (Copy_s32Number == 0)
	{
		CLCD_voidSendData('0');
		return;
	}
	else if (Copy_s32Number < 0)
	{
		CLCD_voidSendData('-');
		Copy_s32Number *= -1;
	}

	while (Copy_s32Number != 0)
	{
		Local_RightDigit = Copy_s32Number % 10;
		Copy_s32Number /= 10;
		Local_u8ChArr[Local_u32Counter1] = Local_RightDigit + '0';
		Local_u32Counter1++;
	}

	for (Local_u32Counter2 = Local_u32Counter1 - 1; Local_u32Counter2 >= 0; Local_u32Counter2--)
	{
		CLCD_voidSendData(Local_u8ChArr[Local_u32Counter2]);
	}
}






/************************ Go to x and y Simple *****************/

void CLCD_voidGotoXY(uint8 Copy_u8Row,uint8 Copy_u8Col)
{

	uint8 Local_Address;

	switch(Copy_u8Row)
	{
	case 0: Local_Address = 0x00+Copy_u8Col;	break;
	case 1: Local_Address = 0x40+Copy_u8Col;	break;
	case 2: Local_Address = 0x14+Copy_u8Col;	break;
	case 3: Local_Address = 0x54+Copy_u8Col;	break;

	}

	CLCD_voidSendCmd(Local_Address+DDRAM_ADDRESS);


}



void CLCD_voidClrScr(void)
{
	CLCD_voidSendCmd(0x01);
}
void CLCD_voidCursorON(void)
{
	CLCD_voidSendCmd(0x0D);
}
void CLCD_voidCursorOFF(void)
{

	CLCD_voidSendCmd(0x0C);

}
void LCD_voidWriteSpecialChar(const uint8 *Copy_u8Pattern, uint8 Copy_u8PatternNumber ,uint8 Copy_u8Row, uint8 Copy_u8Column)
{

	uint8 Local_u8Adress=(Copy_u8PatternNumber*8);
	CLCD_voidSendCmd(Local_u8Adress+64);

	for (uint8 i=0 ;i<8 ;i++)
	{
		CLCD_voidSendData(Copy_u8Pattern[i+(Copy_u8PatternNumber*8)]);
	}


	CLCD_voidGotoXY(Copy_u8Row ,Copy_u8Column );


	CLCD_voidSendData(Copy_u8PatternNumber);
}


