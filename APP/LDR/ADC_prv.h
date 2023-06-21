#ifndef ADC_PRV_H_
#define ADC_PRV_H_

#define ADMUX		*((volatile uint8*)0x27)
#define ADCSRA		*((volatile uint8*)0x26)
#define ADCH		*((volatile uint8*)0x25)
#define ADCL		*((volatile uint8*)0x24)
#define SFIOR		*((volatile uint8*)0x50)

#define ADC		*((volatile uint16*)0x24)/**reading the two regiters Low and high**/


#define ADC_MUX_0				0u
#define ADC_MUX_1				1u
#define ADC_MUX_2				2u
#define ADC_MUX_3				3u
#define ADC_MUX_4				4u
#define ADC_MUX_ADLAR			5u
#define ADC_MUX_REFS0			6u
#define ADC_MUX_REFS1			7u



#define ADCSRA_ADPS0			0u
#define ADCSRA_ADPS1			1u
#define ADCSRA_ADPS2			2u

#define ADCSRA_ADIE				3u
#define ADCSRA_ADIF				4u
#define ADCSRA_ADATE			5u
#define ADCSRA_ADSC				6u
#define ADCSRA_ADEN				7u

#define SFIOR_ADTS0				0u
#define SFIOR_ADTS1				1u
#define SFIOR_ADTS2				2u




#define ADC_CHANNEL_MSK			0b11100000




#endif
