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

void CLCD_voidGoToXY(uint8 Copy_u8XPos, uint8 Copy_u8YPos );

void CLCD_voidSendSpecialCharacter(uint8 *Copy_pu8Pattern,uint8 Copy_u8PatternNum,uint8 Copy_u8XPos, uint8 Copy_u8YPos);

void CLCD_voidMoveShape(uint8 Copy_u8XPos,uint8 Copy_u8YPos);
#endif
