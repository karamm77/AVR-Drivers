#ifndef UART_PRV_H_
#define UART_PRV_H



#define UDR				*((volatile uint8*)0x2C)







#define UCSRA			*((volatile uint8*)0x2B)

#define UCSRA_MPCM			0u
#define UCSRA_U2X			1u
#define UCSRA_PE			2u
#define UCSRA_DOR			3u
#define UCSRA_FE			4u
#define UCSRA_UDRE			5u
#define UCSRA_TXC			6u /*UART Transmit Complete*/
#define UCSRA_RXC			7u /*UART Receive complete*/




#define UCSRB			*((volatile uint8*)0x2A)

#define UCSRB_TXB8			0u
#define UCSRB_RXB8			1u
#define UCSRB_UCSZ2			2u
#define UCSRB_TXEN			3u
#define UCSRB_RXEN			4u
#define UCSRB_UDRIE			5u
#define UCSRB_TXCIE			6u
#define UCSRB_RXIE			7u



#define UCSRC			*((volatile uint8*)0x40)/*Control and status register*/

#define UCSRC_UCPOL			0u
#define UCSRC_UCSZ0			1u
#define UCSRC_UCSZ1			2u
#define UCSRC_USBS			3u
#define UCSRC_UPM0			4u
#define UCSRC_UPM1			5u
#define UCSRC_UMSEL			6u
#define UCSRC_URSLE			7u /*Register Selection*/

#define UBRRH			*((volatile uint8*)0x40)
#define UBRRL			*((volatile uint8*)0x29)








#endif
