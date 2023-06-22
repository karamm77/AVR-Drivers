#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "DIO_interface.h"
#include "EXTI_interface.h"
#include "GIE_interface.h"
#include "SSegmant_interface.h"
#include "util/delay.h"

uint8 ones = 0;
uint8 tens = 0;

void EXTI0_voidISR(void);
void EXTI1_voidISR(void);

void main(void)
{

	SSD_voidInit(DIO_u8PORTA, DIO_u8PIN3);/**First 7Seg**/
	SSD_voidInit(DIO_u8PORTA, DIO_u8PIN2);/** Second 7Seg**/

	SSD_voidDecoderInit(DIO_u8PORTA, DIO_u8PIN3);
	SSD_voidDecoderInit(DIO_u8PORTA, DIO_u8PIN2);


	EXTI_voidINT0Init();
	EXTI_voidINT1Init();

	EXTI_u8SetCallBack(EXTI_INT0, &EXTI0_voidISR);
	EXTI_u8SetCallBack(EXTI_INT1, &EXTI1_voidISR);
	GIE_voidEnableGlobal();


	while(1)
	{
		SSD_u8SSDisplay(DIO_u8PORTA, DIO_u8PIN3, ones);
		SSD_voidDecoderDisable(DIO_u8PORTA, DIO_u8PIN2);
		_delay_ms(200);
		SSD_voidDecoderDisable(DIO_u8PORTA, DIO_u8PIN3);
		SSD_u8SSDisplay(DIO_u8PORTA, DIO_u8PIN2, tens);
		_delay_ms(200);


	}



}


void EXTI0_voidISR(void)
{
	ones = 0;
	tens = 0;
}
void EXTI1_voidISR(void)
{

	if(tens < 9)
	{
		ones++;
	}
	else if(ones == 9)
	{
		ones = 0 ;
		tens++;
	}
	if(tens > 9)
	{
		ones = 0;
		tens = 0;
	}

}


