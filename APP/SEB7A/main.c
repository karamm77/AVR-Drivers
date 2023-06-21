#include "STD_TYPES.h"
#include "BIT_MATH.h"


#include "GIE_interface.h"
#include "EXTI_interface.h"
#include "DIO_interface.h"
#include "DIO_reg.h"
#include "SSegmant_interface.h"

#include "util/delay.h"

void SSD_func(void);



uint8 i = 0;



void main(void)
{
	/**
	 * Initialisaion of SSD
	 *
	 */

  SSD_voidInit(DIO_u8PORTA, DIO_u8PIN3);
  SSD_voidDecoderInit();





    /*************************Intialising the bush button*********************/

	DIO_u8SetPinDirection(DIO_u8PORTD,DIO_u8PIN3,DIO_u8PIN_INPUT);
	DIO_u8SetPinValue(DIO_u8PORTD,DIO_u8PIN3,DIO_u8PIN_HIGH);




	DIO_u8SetPinDirection(DIO_u8PORTA,DIO_u8PIN4,DIO_u8PIN_OUTPUT);
	/*************************************************************/


		EXTI_voidINT1Init();

		EXTI_u8SetCallBack(EXTI_INT1, &SSD_func);
		GIE_voidEnableGlobal();


	while(1)
	{

	}
}



void SSD_func(void)
{
    SSD_u8SSDisplay(i); // Display the current value of i

    if (i == 9) {
        i = 0; // Reset i to 0 when it reaches 9
    } else {
        i++;
    }
}



