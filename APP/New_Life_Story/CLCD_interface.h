#ifndef CLCD_INTERFACE_H_
#define CLCD_INTERFACE_H_

void CLCD_voidSendCmd(uint8 Copy_u8Cmd);

void CLCD_voidSendData(uint8 Copy_u8Data);

uint8 CLCD_u8SendString(const char* Copy_chString);

void CLCD_voidInit(void);

void CLCD_voidSendNumber(sint32 Copy_s32Number);
void CLCD_voidCursorON(void);
void CLCD_voidCursorOFF(void);

void CLCD_voidClrScr(void);

void CLCD_voidGetBinary(sint32 Copy_s32Decimal);

void CLCD_voidGotoXY(uint8 Copy_u8XPos, uint8 Copy_u8YPos );




void LCD_voidWriteSpecialChar(const uint8 *Copy_u8Pattern, uint8 Copy_u8PatternNumber ,uint8 Copy_u8Row, uint8 Copy_u8Column);

#endif
