#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "CLCD_interface.h"
#include "ADC_interface.h"
#include "ADC_prv.h"
#include "GIE_interface.h"
#include "EXTI_interface.h"

int main(void)
{
    uint16 Local_u16ADCDigitalValue = 0;
    uint16 Local_u16ADCAnalogValueMV = 0;
    uint16 Local_u16Temp = 0;

    DIO_u8SetPinDirection(DIO_u8PORTA, DIO_u8PIN1, DIO_u8PIN_INPUT);

    /** LCD **/
    CLCD_voidInit();

    CLCD_u8SendString("Temperature is: ");

    ADC_voidInit();
    ADC_voidEnable();

    /** using polling and source trigger **/

    Local_u16ADCDigitalValue = ADC_uint16GetDigitalValue(ADC_uint8_CHANNEL_0);

    Local_u16ADCAnalogValueMV = (Local_u16ADCDigitalValue * 5000UL) / 1024;

    Local_u16Temp = Local_u16ADCAnalogValueMV / 10; // in Celsius

    CLCD_voidGotoXY(1, 0);
    CLCD_voidSendNumber(Local_u16Temp);

    while (1)
    {
        // Do nothing, program ends here
    }

    return 0;
}
