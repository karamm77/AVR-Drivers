#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "Timer_interface.h"

#include "Timer_cfg.h"
#include "Timer_prv.h"

/** Create Global Pointer to Functions **/

static void (*FUNC_pvCallBackFuncArr[8])(void) = {NULL}; /** only used in this file **/




void TIMER0_voidInit(void)
{

#if MODE_USED == Normal_Mode
	CLR_BIT(TCCR0,TCCR0_WGM00);
	CLR_BIT(TCCR0,TCCR0_WGM01);
	/** Enabling overflow Interrupt flag **/
	SET_BIT(TIMSK,TIMSK_TOIE0);
#elif MODE_USED == CTC_Mode
	CLR_BIT(TCCR0,TCCR0_WGM00);
	SET_BIT(TCCR0,TCCR0_WGM01);
	/** Enabling CTC Interrupt Flag **/
	SET_BIT(TIMSK,TIMSK_OCIE0);
#elif MODE_USED == PWM_PhaseCorrect
	SET_BIT(TCCR0,TCCR0_WGM00);
	CLR_BIT(TCCR0,TCCR0_WGM01);
#elif MODE_USED == Fast_PWM
	SET_BIT(TCCR0,TCCR0_WGM00);
	SET_BIT(TCCR0,TCCR0_WGM01);
	/** Select the Non_inverted Mode SET on TOP CLEAR on Compare**/
	CLR_BIT(TCCR0,TCCR0_COM00);
	SET_BIT(TCCR0,TCCR0_COM01);
#else
#error "WRONG MODE INPUT"
#endif

	/** Prescaler **/
#if PRESCALER_USED == PRESCALER_8
	CLR_BIT(TCCR0,TCCR0_CS00);
	SET_BIT(TCCR0,TCCR0_CS01);
	CLR_BIT(TCCR0,TCCR0_CS02);
#elif PRESCALER_USED == NO_PRESCALER
	SET_BIT(TCCR0,TCCR0_CS00);
	CLR_BIT(TCCR0,TCCR0_CS01);
	CLR_BIT(TCCR0,TCCR0_CS02);
#elif PRESCALER_USED == PRESCALER_64
	SET_BIT(TCCR0,TCCR0_CS00);
	SET_BIT(TCCR0,TCCR0_CS01);
	CLR_BIT(TCCR0,TCCR0_CS02);
#elif PRESCALER_USED == PRESCALER_256
	CLR_BIT(TCCR0,TCCR0_CS00);
	CLR_BIT(TCCR0,TCCR0_CS01);
	SET_BIT(TCCR0,TCCR0_CS02);
#elif PRESCALER_USED == PRESCALER_1024
	SET_BIT(TCCR0,TCCR0_CS00);
	CLR_BIT(TCCR0,TCCR0_CS01);
	SET_BIT(TCCR0,TCCR0_CS02);
#else
#error "Wrong Prescaler Input"
#endif

}

void TIMER1_voidInit(void)
{
#if T1_ModeUsed == T1_NormalMode
	CLR_BIT(TCCR1A,TCCR1A_WGM10);
	CLR_BIT(TCCR1A,TCCR1A_WGM11);
	CLR_BIT(TCCR1B,TCCR1B_WGM12);
	CLR_BIT(TCCR1B,TCCR1B_WGM13);
#elif T1_ModeUsed == T1_FastPWM
	/** Selecting Fast PWM Mode **/
	CLR_BIT(TCCR1A,TCCR1A_WGM10);
	SET_BIT(TCCR1A,TCCR1A_WGM11);
	SET_BIT(TCCR1B,TCCR1B_WGM12);
	SET_BIT(TCCR1B,TCCR1B_WGM13);
#else
#error "Wrong Mode Input"
#endif

	/** SET Clear on compare up Counting, SET on compare down counting "Non-Inverted Mode" **/
	CLR_BIT(TCCR1A,TCCR1A_COM1A0);
	SET_BIT(TCCR1A,TCCR1A_COM1A1);

//	/** SET PRESCALER TO 8MHZ **/
//	CLR_BIT(TCCR1B,TCCR1B_CS10);
//	SET_BIT(TCCR1B,TCCR1B_CS11);
//	CLR_BIT(TCCR1B,TCCR1B_CS12);


	/** SET PRESCALER TO 64MHZ **/
	SET_BIT(TCCR1B,TCCR1B_CS10);
	SET_BIT(TCCR1B,TCCR1B_CS11);
	CLR_BIT(TCCR1B,TCCR1B_CS12);
}
void TIMER1_voidSetCompareValue(uint16 Copy_u16Val)
{

	OCR1AL = Copy_u16Val;

}

void Timer1_voidSetTimerVal(uint16 Copy_u16Val)
{
	TCNT1L = Copy_u16Val;

}
uint16 Timer1_voidGetTimerVal(void)
{
	return TCNT1L;

}

void TIMER0_voidSetCompareValue(uint8 Copy_u8Val)
{

	OCR0 = Copy_u8Val;
}


uint8 TIMER0_voidSetCallBack(TIMERS_INT_SRC Copy_u8TmrIntSRC, void (*Copy_PF)(void))
{
	uint8 Local_u8Error = OK;

	if(Copy_PF != NULL)
	{
		FUNC_pvCallBackFuncArr[Copy_u8TmrIntSRC]= Copy_PF;

	}
	else
	{Local_u8Error = NULL_PTR_ERR;}

	return Local_u8Error;
}

void __vector_10(void) __attribute__((signal));
void __vector_10(void)
{
	if(FUNC_pvCallBackFuncArr[TIMER0_CTC] != NULL)
	{
		FUNC_pvCallBackFuncArr[TIMER0_CTC]();
	}
	else
	{
		/*	Do Nothing */
	}
}

void __vector_11(void) __attribute__((signal));
void __vector_11 (void)
{

	if(FUNC_pvCallBackFuncArr[TIMER0_OVF] != NULL)
	{
		FUNC_pvCallBackFuncArr[TIMER0_OVF]();

	}
	else
	{/*	Do Nothing */}

}
