#ifndef TIMER_PRV_H_
#define TIMER_PRV_H_



#define TCNT0				*((volatile uint8*)0x52)

#define TCCR0				*((volatile uint8*)0x53)
#define TCCR0_CS00					0u
#define TCCR0_CS01					1u
#define TCCR0_CS02					2u
#define TCCR0_WGM01					3u
#define TCCR0_COM00					4u
#define TCCR0_COM01					5u
#define TCCR0_WGM00					6u
#define TCCR0_FOC0					7u


#define TIMSK				*((volatile uint8*)0x59)
#define TIMSK_TOIE0				0u // Overflow Interrupt Enable
#define TIMSK_OCIE0				1u


#define OCR0				*((volatile uint8*)0x5C)


/* using Mask option */

#define Prescaler_MSK			(0b1111000)
/** define your prescalers **/



/** Timer1 Register **/
#define TCCR1A								*((volatile uint8*)0x4F)
#define TCCR1A_WGM10							0u
#define TCCR1A_WGM11                            1u
#define TCCR1A_FOC1B                            2u
#define TCCR1A_FOC1A                            3u
#define TCCR1A_COM1B0                           4u
#define TCCR1A_COM1B1                           5u
#define TCCR1A_COM1A0                           6u
#define TCCR1A_COM1A1                           7u

#define TCCR1B								*((volatile uint8*)0x4E)
#define TCCR1B_CS10								0u
#define TCCR1B_CS11                             1u
#define TCCR1B_CS12                             2u
#define TCCR1B_WGM12                            3u
#define TCCR1B_WGM13                            4u
#define TCCR1B_RESRVED                          5u
#define TCCR1B_ICES1                            6u
#define TCCR1B_ICNC1                            7u

#define TCNT1L								*((volatile uint16*)0x4C)

#define OCR1AL								*((volatile uint16*)0x4A)

#define OCR1BL								*((volatile uint16*)0x48)

#define ICR1L								*((volatile uint16*)0x46)










#endif
