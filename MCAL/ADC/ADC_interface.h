#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_


#define ADC_uint8_CHANNEL_0		0u
#define ADC_uint8_CHANNEL_1		1u
#define ADC_uint8_CHANNEL_2		2u
#define ADC_uint8_CHANNEL_3		3u
#define ADC_uint8_CHANNEL_4		4u
#define ADC_uint8_CHANNEL_5		5u
#define ADC_uint8_CHANNEL_6		6u
#define ADC_uint8_CHANNEL_7		7u

/**
 * Choose which voltage Reference you Want
 */

#define AVREF_AVCC_5V			1u
#define AVREF_Custom			2u
#define AVREF_INTERNAL			3u





/** Select the adjustment you want **/

#define RIGHT_Adjustment		1u
#define LEFT_Adjustment			2u




void  ADC_voidInit(void);
void ADC_voidEnable(void);
void ADC_voidDisable(void);

void ADC_voidInterruptEnable(void);
void ADC_voidInterruptDisable(void);

uint16 ADC_uint16GetDigitalValue(uint8 Copy_uint8ChannelNum);

void ADC_CallBck(void (*Copy_ptr)(void));
void ADC_u16StartConversion(uint8 Copy_uint8ChannelNum);

void  ADC_voidInitTriggerSource(void);
uint8 EXTI_u8SetCallBack(uint8 Copy_u8Interrupt, void (*Copy_pfFuncPtr)(void));











#endif
