#include "STD_TYPES.h"
#include "BIT_MATH.h"


#include <util/delay.h>

#include "DIO_interface.h"
#include "BB_interface.h"
#include "BB_cfg.h"
#include "BB_prv.h"

void Button_voidInit(void)
{
    // Initialize the button pin as input with pull-up resistor
    DIO_u8SetPinDirection(BB_CTRL_PORT, BB_CTRL_PIN1, DIO_u8PIN_INPUT);


    //DIO_u8SetPinDirection(BB_CTRL_PORT, BB_CTRL_PIN2, DIO_u8PIN_INPUT);



}

uint8 Button_u8IsPressed(void)
{

    uint8 Local_Erro = OK;
	uint8 button_released = 1;
    uint8 x;
    uint8* Copy_pu8Value = &x;

    DIO_u8GetPinValue(BB_CTRL_PORT, BB_CTRL_PIN1, Copy_pu8Value);

    if(x == 0 && button_released == 1)
    {
    	_delay_ms(500);
    	DIO_u8GetPinValue(BB_CTRL_PORT, BB_CTRL_PIN1, Copy_pu8Value);
    	if(x == 0 && button_released == 1)
    	{
    		button_released = 0;
    		return x;
    	}
    	else
    	{
    		Local_Erro = NOK;
    	}

    }
    else if(x == 1)
    {
    	button_released = 1;
    }
    return Local_Erro;

}
