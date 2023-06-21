#ifndef EXTI_INTERFACE_H_

#define EXTI_INTERFACE_H_


#define EXTI_INT0		0u
#define EXTI_INT1		1u
#define EXTI_INT2		2u




#define EXTI_u8LOW_LEVEL		1u
#define EXTI_u8_LOGICAL_CHANGE	2u
#define EXTI_u8FALLING_EDGE		3u
#define EXTI_u8RISING_EDGE		4u






uint8 EXTI_u8IntEnable(uint8 Copy_u8Innterrupt);
uint8 EXTI_u8DisableEnable(uint8 Copy_u8Innterrupt);
void EXTI_voidINT0Init(void);
void EXTI_voidINT1Init(void);
void EXTI_voidINT2Init(void);

uint8 EXTI_u8SetSenseControl(uint8 Copy_u8Interrupt,uint8 Copy_u8Sense_Ctrl); /**During Runtime**/

uint8 EXTI_u8SetCallBack(uint8 Copy_u8Interrupt, void (*Copy_pfFuncPtr)(void));

#endif
