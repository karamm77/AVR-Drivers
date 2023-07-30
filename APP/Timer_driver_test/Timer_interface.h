#ifndef TIMER_INTERFACE_H_
#define TIMER_INTERFACE_H_



typedef enum
{
	TIMER0_OVF = 0,
	TIMER0_CTC
}TIMERS_INT_SRC;

/*Wave Form Generation Modes Available*/

#define Normal_Mode				1u
#define PWM_PhaseCorrect		2u
#define CTC_Mode				3u
#define Fast_PWM				4u


/*Choose The required prescaler*/
#define NO_PRESCALER			1u
#define PRESCALER_8				2u
#define PRESCALER_64			3u
#define PRESCALER_256			4u
#define PRESCALER_1024			5u


/* Timer1 Modes */

#define T1_NormalMode			1u
#define T1_FastPWM				2u



void TIMER0_voidInit(void);
void TIMER1_voidInit(void);

void TIMER0_voidSetCompareValue(uint8 Copy_u8Val);
void TIMER1_voidSetCompareValue(uint16 Copy_u16Val);

void Timer1_voidSetTimerVal(uint16 Copy_u16Val);

uint16 Timer1_voidGetTimerVal(void);


uint8 TIMER0_voidSetCallBack(TIMERS_INT_SRC Copy_u8TmrIntSRC, void (*Copy_PF)(void));



















#endif
