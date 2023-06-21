#include "STD_TYPES.h"
#include "BIT_MATH.h"


#include "DIO_interface.h"
#include "CLCD_interface.h"
#include "ADC_interface.h"
#include "ADC_prv.h"
#include "GIE_interface.h"
#include "EXTI_interface.h"

uint16 Local_u16ADCDigitalValue = 0;
uint16 Local_u16ADCAnaloglValueMV = 0;
uint16 Local_Brightness = 0;
uint16 Local_u61Temp = 0;

void Print_Value(void);

int main(void)
{




	DIO_u8SetPinDirection(DIO_u8PORTA, DIO_u8PIN0, DIO_u8PIN_INPUT);



	/** LCD **/
	CLCD_voidInit();

	CLCD_u8SendString("Brightness is: ");

	ADC_voidInit();
	ADC_voidEnable();


while(1)
{


	/** using polling and source trigger**/

	Local_u16ADCDigitalValue = ADC_uint16GetDigitalValue(ADC_uint8_CHANNEL_0);

	Local_u16ADCAnaloglValueMV = (Local_u16ADCDigitalValue * 5000UL)/1024;

	Local_Brightness = Local_u16ADCAnaloglValueMV/50;

	//* For LM35 *
	//Local_u61Temp = Local_u16ADCAnaloglValueMV /10; //* in celisus*

	//* LDR *

	voidGotoXandY(1, 0);
	CLCD_voidSendNumber(Local_Brightness);



 }
return 0;
}





