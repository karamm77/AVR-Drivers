#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "DIO_interface.h"
#include "GIE_interface.h"
#include "EXTI_interface.h"
#include "CLCD_interface.h"

#include <util/delay.h>


#include "Timer_interface.h"
#include "Timer_prv.h"

static uint16 Reading_1 = 0, Reading_2 = 0;
void ICU_SW(void);


void main(void)
{
DIO_u8SetPinDirection(DIO_u8PORTB, DIO_u8PIN3, DIO_u8PIN_OUTPUT);
DIO_u8SetPinDirection(DIO_u8PORTD, DIO_u8PIN2, DIO_u8PIN_INPUT);
CLCD_voidInit();


	uint16 ON_Ticks = 0u;
	uint16 Period_Ticks;
	uint16 D_C = 0u;

TIMER0_voidInit();
/** Generating PWM with DC 25%, set CompVal to 63 **/
TIMER0_voidSetCompareValue(63);

TIMER1_voidInit();

EXTI_voidINT0Init();
EXTI_u8SetCallBack(EXTI_INT0, &ICU_SW);
EXTI_u8IntEnable(EXTI_INT0);

GIE_voidEnableGlobal();

while(1)
{
	/** Poll to ensure there are changes happened to Reading 1 and 2 **/

	while((Reading_1 == 0) || (Reading_2 == 0));

	Period_Ticks = Reading_1;
	ON_Ticks = Reading_2 - Reading_1;

	D_C = ((float)ON_Ticks / (float)Period_Ticks) * 100;

	CLCD_voidGoToXY(0, 0);
	CLCD_u8SendString("ON:");
	CLCD_voidSendNumber(ON_Ticks);

	CLCD_voidGoToXY(1, 0);
	CLCD_u8SendString("D_C:");
	CLCD_voidSendNumber(D_C);
	CLCD_u8SendString("%");

}



}


void ICU_SW(void)
{

static uint16 counter = 0u; /** we make it static to change stoage duration to be permanent **/
counter++;
if(counter == 1u)
{
	Timer1_voidSetTimerVal(0u);

}
else if(counter == 2u)
{
	Reading_1 = Timer1_voidGetTimerVal(); /* Reading of period Time */
	/** Changing the sense ctrl from rising to falling edge in the interrupt **/

	EXTI_u8SetSenseControl(EXTI_INT0, EXTI_u8FALLING_EDGE);


}
else if(counter == 3u)
{
	Reading_2 = Timer1_voidGetTimerVal();
	EXTI_u8DisableEnable(EXTI_INT0);

}

}
