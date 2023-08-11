#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"

#include "Timer_interface.h"

#include "GIE_interface.h"

#include "Kernel_interface.h"


void Led1(void);
void Led2(void);
void Led3(void);

void main(void)
{
	DIO_u8SetPinDirection(DIO_u8PORTA, DIO_u8PIN0, DIO_u8PIN_OUTPUT);

	DIO_u8SetPinDirection(DIO_u8PORTA, DIO_u8PIN1, DIO_u8PIN_OUTPUT);

	DIO_u8SetPinDirection(DIO_u8PORTA, DIO_u8PIN2, DIO_u8PIN_OUTPUT);



	RTOS_u8CreateTask(0, 1000, 0, &Led1);
	RTOS_u8CreateTask(1, 1000, 500, &Led2);
	RTOS_voidSuspendTask(1);


	RTOS_voidStart();
	GIE_voidEnableGlobal();

	while(1)
	{

	}





}

void Led1(void)
{
	DIO_u8TogglePinValue(DIO_u8PORTA, DIO_u8PIN0);

	RTOS_u8CreateTask(2, 1000, 1000, &Led3);
 /* overwriting priority after deleting	*/


}

void Led2(void)
{
	DIO_u8TogglePinValue(DIO_u8PORTA, DIO_u8PIN1);

}

void Led3(void)
{
	RTOS_voidResumeTask(1);
	DIO_u8TogglePinValue(DIO_u8PORTA, DIO_u8PIN2);



}

