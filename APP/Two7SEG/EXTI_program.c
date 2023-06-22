#include "STD_TYPES.h"
#include "BIT_MATH.h"


#include "DIO_interface.h"
#include "EXTI_interface.h"

#include "EXTI_cfg.h"
#include "EXTI_reg.h"
#include "EXTI_prv.h"



static void (*EXTI_pfINTFuncPrt[3]) (void) = {NULL}; /**array of pointer to functions to hold ISR callback**/



/** Enabling**/
uint8 EXTI_u8IntEnable(uint8 Copy_u8Innterrupt)
{
	uint8 LocalErrorState = OK;


	if(Copy_u8Innterrupt == EXTI_INT0)
	{
		LocalErrorState = OK;
		SET_BIT(GICR,GICR_INT0_EN);
	}
	else if(Copy_u8Innterrupt == EXTI_INT1)
	{
		LocalErrorState = OK;
		SET_BIT(GICR,GICR_INT1_EN);
	}
	else if(Copy_u8Innterrupt == EXTI_INT2)
	{
		LocalErrorState = OK;
		SET_BIT(GICR,GICR_INT2_EN);
	}
	else
	{
		LocalErrorState = NOK;
	}
	return LocalErrorState;
}

/** Disabling **/

uint8 EXTI_u8DisableEnable(uint8 Copy_u8Innterrupt)
{
	uint8 LocalErrorState = OK;


	if(Copy_u8Innterrupt == EXTI_INT0)
	{
		LocalErrorState = OK;
		CLR_BIT(GICR,GICR_INT0_EN);
	}
	else if(Copy_u8Innterrupt == EXTI_INT1)
	{
		LocalErrorState = OK;
		CLR_BIT(GICR,GICR_INT1_EN);
	}
	else if(Copy_u8Innterrupt == EXTI_INT2)
	{
		LocalErrorState = OK;
		CLR_BIT(GICR,GICR_INT2_EN);
	}
	else
	{
		LocalErrorState = NOK;
	}
	return LocalErrorState;
}


/** Intializing INT0 **/
void EXTI_voidINT0Init(void)
{

	/*Checking the control State */
#if EXTI_INT0_CTRL_SENSE == EXTI_u8LOW_LEVEL
	CLR_BITT(MCUCR,MCUCR_INT0_ISC00);
	CLR_BIT(MCUCR,MCUCR_INT0_ISC01);

#elif EXTI_INT0_CTRL_SENSE == EXTI_u8_LOGICAL_CHANGE
		SET_BIT(MCUCR,MCUCR_INT0_ISC00);
		CLR_BIT(MCUCR,MCUCR_INT0_ISC01);

#elif EXTI_INT0_CTRL_SENSE == EXTI_u8FALLING_EDGE
		CLR_BIT(MCUCR,MCUCR_INT0_ISC00);
		SET_BIT(MCUCR,MCUCR_INT0_ISC01);

#elif EXTI_INT0_CTRL_SENSE == EXTI_u8RISING_EDGE
		SET_BIT(MCUCR,MCUCR_INT0_ISC00);
		SET_BIT(MCUCR,MCUCR_INT0_ISC01);
#else
#error  Wrong INT0_Ctrl_Sense configuration options
#endif

		/*Checking Enabled or Disabled*/
#if EXTI_INT0_STATE == ENABLED
		SET_BIT(GICR,GICR_INT0_EN);
#elif EXTI_INT0_STATE == DISABLED
		CLR_BIT(GICR,GICR_INT0_EN);

#else
#error Wrong INT0_Initial_STATE configuration options
#endif
}

/** Intializing INT1 **/

void EXTI_voidINT1Init(void)
{
/*Checking the control State */
#if EXTI_INT0_CTRL_SENSE == EXTI_u8LOW_LEVEL
CLR_BITT(MCUCR,MCUCR_INT1_ISC10);
CLR_BIT(MCUCR,MCUCR_INT1_ISC11);

#elif EXTI_INT0_CTRL_SENSE == EXTI_u8_LOGICAL_CHANGE
	SET_BIT(MCUCR,MCUCR_INT1_ISC10);
	CLR_BIT(MCUCR,MCUCR_INT1_ISC11);

#elif EXTI_INT0_CTRL_SENSE == EXTI_u8FALLING_EDGE
	CLR_BIT(MCUCR,MCUCR_INT1_ISC10);
	SET_BIT(MCUCR,MCUCR_INT1_ISC11);

#elif EXTI_INT0_CTRL_SENSE == EXTI_u8RISING_EDGE
	SET_BIT(MCUCR,MCUCR_INT1_ISC10);
	SET_BIT(MCUCR,MCUCR_INT1_ISC11);
#else
#error  Wrong INT1_Ctrl_Sense configuration options
#endif

	/*Checking Enabled or Disabled*/
#if EXTI_INT1_STATE == ENABLED
	SET_BIT(GICR,GICR_INT1_EN);
#elif EXTI_INT1_STATE == DISABLED
	CLR_BIT(GICR,GICR_INT1_EN);

#else
##error Wrong INT1_Initial_STATE configuration options
#endif
}

/**Intialising INT2 **/
void EXTI_voidINT2Init(void)
{
/*Checking the control State */
#if EXTI_INT2_CTRL_SENSE == EXTI_u8FALLING_EDGE
CLR_BIT(MCUCSR,MCUCSR_INT2_ISC2);



#elif EXTI_INT2_CTRL_SENSE == EXTI_u8RISING_EDGE
	SET_BIT(MCUCSR,MCUCSR_INT2_ISC2);
#else
#error  Wrong INT2_Ctrl_Sense configuration options
#endif

	/*Checking Enabled or Disabled*/
#if EXTI_INT2_STATE == ENABLED
	SET_BIT(GICR,GICR_INT2_EN);
#elif EXTI_INT1_STATE == DISABLED
	CLR_BIT(GICR,GICR_INT2_EN);

#else
##error Wrong INT2_Initial_STATE configuration options
#endif
}



/** Sensing Control **/

uint8 EXTI_u8SetSenseControl(uint8 Copy_u8Interrupt,uint8 Copy_u8Sense_Ctrl)
{

	uint8 LocalErrorState = OK;
	if(Copy_u8Interrupt == EXTI_INT0)
	{
		switch(Copy_u8Sense_Ctrl)
		{
		case EXTI_u8LOW_LEVEL: CLR_BIT(MCUCR,MCUCR_INT0_ISC00); CLR_BIT(MCUCR,MCUCR_INT0_ISC01); break;
		case EXTI_u8_LOGICAL_CHANGE: SET_BIT(MCUCR,MCUCR_INT0_ISC00); CLR_BIT(MCUCR,MCUCR_INT0_ISC01); break;
		case EXTI_u8FALLING_EDGE: CLR_BIT(MCUCR,MCUCR_INT0_ISC00); SET_BIT(MCUCR,MCUCR_INT0_ISC01); break;
		case EXTI_u8RISING_EDGE: SET_BIT(MCUCR,MCUCR_INT0_ISC00); SET_BIT(MCUCR,MCUCR_INT0_ISC01);break;
		default: LocalErrorState = NOK; break;
		}
	}

	else if(Copy_u8Interrupt == EXTI_INT1)
	{
		switch(Copy_u8Sense_Ctrl)
		{
		case EXTI_u8LOW_LEVEL: CLR_BIT(MCUCR,MCUCR_INT1_ISC10); CLR_BIT(MCUCR,MCUCR_INT1_ISC11); break;
		case EXTI_u8_LOGICAL_CHANGE: SET_BIT(MCUCR,MCUCR_INT1_ISC10); CLR_BIT(MCUCR,MCUCR_INT1_ISC11); break;
		case EXTI_u8FALLING_EDGE: CLR_BIT(MCUCR,MCUCR_INT1_ISC10); SET_BIT(MCUCR,MCUCR_INT1_ISC11); break;
		case EXTI_u8RISING_EDGE: SET_BIT(MCUCR,MCUCR_INT1_ISC10); SET_BIT(MCUCR,MCUCR_INT1_ISC11);break;
		default: LocalErrorState = NOK; break;
		}
	}

	else if(Copy_u8Interrupt == EXTI_INT2)
	{
		switch(Copy_u8Sense_Ctrl)
		{
		case EXTI_u8FALLING_EDGE: CLR_BIT(MCUCSR,MCUCSR_INT2_ISC2);	break;
		case EXTI_u8RISING_EDGE: SET_BIT(MCUCSR,MCUCSR_INT2_ISC2);    break;
		default: LocalErrorState = NOK; break;
		}
	}
	else
	{
		LocalErrorState = NOK;
	}
	return LocalErrorState;


}






uint8 EXTI_u8SetCallBack(uint8 Copy_u8Interrupt, void (*Copy_pfFuncPtr)(void))
{

	uint8 LocalErrorState = OK;

	if(Copy_pfFuncPtr != NULL)
	{
		EXTI_pfINTFuncPrt[Copy_u8Interrupt] = Copy_pfFuncPtr;
	}
	else
	{
		LocalErrorState = NULL_PTR_ERR;
	}


	return LocalErrorState;

}


/** ISR of INT0**/


void __vector_1 (void) __attribute((signal)); /** For linker to cancel linker optimization**/
void __vector_1 (void)
{
	if(EXTI_pfINTFuncPrt[EXTI_INT0] != NULL)
	{
		EXTI_pfINTFuncPrt[EXTI_INT0]();
	}
}



/** ISR of INT1**/
void __vector_2 (void) __attribute((signal));
void __vector_2 (void)
{
	if(EXTI_pfINTFuncPrt[EXTI_INT1] != NULL)
	{
		EXTI_pfINTFuncPrt[EXTI_INT1]();
	}
}


/** ISR of INT2**/

void __vector_3 (void) __attribute((signal));
void __vector_3 (void)
{
	if(EXTI_pfINTFuncPrt[EXTI_INT2] != NULL)
	{
		EXTI_pfINTFuncPrt[EXTI_INT2]();
	}
}
