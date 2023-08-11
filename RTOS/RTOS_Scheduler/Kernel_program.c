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

uint8 RTOS_u8CreateTask(uint8 Copy_u8Priority,uint16 Copy_u16Periodicity,uint16 Copy_u16FirstDelay, void(*Copy_pvTaskFunc)(void))
{

	uint8 Local_u8ErrorState = OK;

	if(Copy_pvTaskFunc != NULL)
	{
		if(SystemTasks[Copy_u8Priority].TaskFunc == NULL)
		{
		SystemTasks[Copy_u8Priority].periodicity = Copy_u16Periodicity;
		SystemTasks[Copy_u8Priority].TaskFunc = Copy_pvTaskFunc;
		SystemTasks[Copy_u8Priority].Suspendded = 0u;
		SystemTasks[Copy_u8Priority].FirstDelay = Copy_u16FirstDelay;
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



	for(Local_u8TaskCounter = 0; Local_u8TaskCounter <Task_Num; Local_u8TaskCounter++)
	{
		if(SystemTasks[Local_u8TaskCounter].TaskFunc != NULL)
		{
			if(SystemTasks[Local_u8TaskCounter].FirstDelay == 0)
			{
				/** Invoke the task function **/
				SystemTasks[Local_u8TaskCounter].TaskFunc();
				SystemTasks[Local_u8TaskCounter].FirstDelay = SystemTasks[Local_u8TaskCounter].periodicity-1 ;

			}
			else
			{
				/** Assign First Delay to periodicity **/
				SystemTasks[Local_u8TaskCounter].FirstDelay--;
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
