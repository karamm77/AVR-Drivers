#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "UART_prv.h"
#include "UART_interface.h"
#include <util/delay.h>





void UART_voidInit(void)
{
	DIO_u8SetPinDirection(DIO_u8PORTD, DIO_u8PIN0, DIO_u8PIN_INPUT);/** RX **/
	DIO_u8SetPinDirection(DIO_u8PORTD, DIO_u8PIN1, DIO_u8PIN_OUTPUT);/** TX **/


	uint8 Local_u8UCSRCVal = 0;
	/** Transmitter and Receiver Enable **/
	SET_BIT(UCSRB,UCSRB_TXEN);
	SET_BIT(UCSRB,UCSRB_RXEN);


	/** Asy Mode **/
	CLR_BIT(Local_u8UCSRCVal,UCSRC_UMSEL);

	/** 8-Bit Data **/
	SET_BIT(Local_u8UCSRCVal,UCSRC_UCSZ0);
	SET_BIT(Local_u8UCSRCVal,UCSRC_UCSZ1);
	CLR_BIT(UCSRB,UCSRB_UCSZ2);

	/** No parity **/
	CLR_BIT(Local_u8UCSRCVal,UCSRC_UPM0);
	CLR_BIT(Local_u8UCSRCVal,UCSRC_UPM1);

	/** Selecting UCSRC Register **/
	SET_BIT(Local_u8UCSRCVal,UCSRC_URSLE);

	/** One stop Bit **/
	CLR_BIT(Local_u8UCSRCVal,UCSRC_USBS);

	 UCSRC = Local_u8UCSRCVal;

	UBRRL = 103u;
}

void UART_voidTransmitData(uint8 Copy_u8Data)
{
	/** wail until transmit buffer is ready **/

	while(GET_BIT(UCSRA,UCSRA_UDRE) == 0);

	UDR = Copy_u8Data;



}

uint8 UART_voidReceiveData(void)
{
	/** wait until there is data received**/
	while(GET_BIT(UCSRA,UCSRA_RXC) == 0);

	return UDR;

}


uint8 UART_u8SendString(const char *Copy_pString)
{
	uint8 Local_u8ErrorState=OK;
	uint8 Local_u8Counter=0;
	if(Copy_pString != NULL)
	{
		while(Copy_pString[Local_u8Counter] != '\0')
		{
			UART_voidTransmitData(Copy_pString[Local_u8Counter]);
			Local_u8Counter++;
		}
	}
	else
	{
		Local_u8ErrorState=NULL_PTR_ERR;
	}
	return Local_u8ErrorState;
}






void UART_voidReceiveString(uint8 * Copy_u8data , uint8 Copy_u8Size)
{
	uint8 Local_u8Counter = 0;
	uint8 Local_u8Index = 0;
	for ( Local_u8Counter =0 ; Local_u8Counter<Copy_u8Size ; Local_u8Counter++)
	{
		while((UCSRA & 0x80) == 0);
		Copy_u8data[Local_u8Index] = UART_voidReceiveData();
		Local_u8Index++;
	}
}
