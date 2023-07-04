#ifndef UART_INTERFACE_H_
#define UART_INTERFACE_H_







void UART_voidInit(void);

void UART_voidTransmitData(uint8 Copy_u8Data);

uint8 UART_voidReceiveData(void);

uint8 UART_u8SendString(const char *Copy_pString);


void UART_voidReceiveString(uint8 * Copy_u8data , uint8 Copy_u8Size);









#endif
