#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "Timer_interface.h"
#include "Kernel_cfg.h"
#include "Kernel_interface.h"
#include "Kernel_prv.h"

static Task_t SystemTasks[Task_Num] = {{0}};  /*	Array of struct *creating variable of the new type*	*/


void RTOS_voidStart(void)
{
	TIMER0_voidInit();
	TIMER0_voidSetCompareValue(250);
	TIMER0_voidSetCallBack(TIMER0_CTC, &Scheduler);

}

uint8 RTOS_u8CreateTask(uint8 Copy_u8Priority,uint16 Copy_u16Periodicity, void(*Copy_pvTaskFunc)(void))
{

	uint8 Local_u8ErrorState = OK;

	if(Copy_pvTaskFunc != NULL)
	{
		if(SystemTasks[Copy_u8Priority].TaskFunc == NULL)
		{
		SystemTasks[Copy_u8Priority].periodicity = Copy_u16Periodicity;
		SystemTasks[Copy_u8Priority].TaskFunc = Copy_pvTaskFunc;
		}
		else
		{
			/*	Task is not available priority isused before cannot overwrite	*/
			Local_u8ErrorState = NOK;
		}
	}
	else
	{
		Local_u8ErrorState = NULL_PTR_ERR;
	}


	return Local_u8ErrorState;

}



static void Scheduler(void)
{
	uint8 Local_u8TaskCounter;

	static uint16 Local_u8TickCounter = 0;
	Local_u8TickCounter++;

	for(Local_u8TaskCounter = 0; Local_u8TaskCounter <Task_Num; Local_u8TaskCounter++)
	{
		if(SystemTasks[Local_u8TaskCounter].TaskFunc != NULL)
		{
			if((Local_u8TickCounter % SystemTasks[Local_u8TaskCounter].periodicity == 0) && (SystemTasks[Local_u8TaskCounter].Suspendded==0u))
			{
				/** Invoke the task function **/
				SystemTasks[Local_u8TaskCounter].TaskFunc();
			}
			else
			{
				/*	Do Nothing, Suspended or condition didn't meet	*/
			}
		}
		else
		{
			/*	Task Deleted	*/
		}
	}

}

void RTOS_voidSuspendTask(uint8 Copy_u8priority)
{

	SystemTasks[Copy_u8priority].Suspendded = 1u;

}
void RTOS_voidResumeTask(uint8 Copy_u8priority)
{
	SystemTasks[Copy_u8priority].Suspendded = 0u;
}

void RTOS_voidDeleteTask(uint8 Copy_u8priority)
{
	SystemTasks[Copy_u8priority].TaskFunc=NULL;
}
