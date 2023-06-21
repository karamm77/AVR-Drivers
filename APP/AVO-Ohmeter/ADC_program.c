#include "BIT_MATH.h"
#include "STD_TYPES.h"

//#include "EXTI_interface.h"
#include "ADC_interface.h"
#include "ADC_prv.h"
#include "ADC_cfg.h"

void (*Funcptr)(void);





void  ADC_voidInit(void)
{

	/**Voltage Reference **/
#if AVREF_USED == AVREF_AVCC_5V
	SET_BIT(ADMUX,ADC_MUX_REFS0);
	CLR_BIT(ADMUX,ADC_MUX_REFS1);
#elif AVREF_USED ==  AVREF_Custom
	CLR_BIT(ADMUX,ADC_MUX_REFS0);
	CLR_BIT(ADMUX,ADC_MUX_REFS1);
#elif AVREF_USED ==  AVREF_INTERNAL
	SET_BIT(ADMUX,ADC_MUX_REFS0);
	SET_BIT(ADMUX,ADC_MUX_REFS1);
#else
#error Wrong Input
#endif

	/** Select Adjustment RIGHT **/

#if Adjustment_used == RIGHT_Adjustment
	CLR_BIT(ADMUX,ADC_MUX_ADLAR);
#elif Adjustment_used == LEFT_Adjustment
	SET_BIT(ADMUX,ADC_MUX_ADLAR);
#else
#error Wrong Agjustment
#endif

	/** Choosing prescaler as 64**/
	CLR_BIT(ADCSRA,ADCSRA_ADPS0);
	SET_BIT(ADCSRA,ADCSRA_ADPS1);
	SET_BIT(ADCSRA,ADCSRA_ADPS2);

}

/************Using Trigger Source *******************/
void  ADC_voidInitTriggerSource(void)
{

	/**Voltage Reference **/
#if AVREF_USED == AVREF_AVCC_5V
	SET_BIT(ADMUX,ADC_MUX_REFS0);
	CLR_BIT(ADMUX,ADC_MUX_REFS1);
#elif AVREF_USED ==  AVREF_Custom
	CLR_BIT(ADMUX,ADC_MUX_REFS0);
	CLR_BIT(ADMUX,ADC_MUX_REFS1);
#elif AVREF_USED ==  AVREF_INTERNAL
	SET_BIT(ADMUX,ADC_MUX_REFS0);
	SET_BIT(ADMUX,ADC_MUX_REFS1);
#else
#error Wrong Input
#endif

	/** Select Adjustment RIGHT **/

#if Adjustment_used == RIGHT_Adjustment
	CLR_BIT(ADMUX,ADC_MUX_ADLAR);
#elif Adjustment_used == LEFT_Adjustment
	SET_BIT(ADMUX,ADC_MUX_ADLAR);
#else
#error Wrong Agjustment
#endif

	/** Choosing prescaler as 64**/
	CLR_BIT(ADCSRA,ADCSRA_ADPS0);
	SET_BIT(ADCSRA,ADCSRA_ADPS1);
	SET_BIT(ADCSRA,ADCSRA_ADPS2);


	/***** Using External Interrupt ****/

	CLR_BIT(SFIOR,SFIOR_ADTS0);
	SET_BIT(SFIOR,SFIOR_ADTS1);
	CLR_BIT(SFIOR,SFIOR_ADTS2);

	/***** Setting BIT 5 in ADCSRA ***/
	SET_BIT(ADCSRA,ADCSRA_ADATE);

}

void ADC_voidEnable(void)
{
	/** Enabling ADC peripheral**/

	SET_BIT(ADCSRA,ADCSRA_ADEN);
}
void ADC_voidDisable(void)
{
	/**Disabling ADC peripheral **/
	CLR_BIT(ADCSRA,ADCSRA_ADEN);
}

void ADC_voidInterruptEnable(void)
{
	/**Enabling PIE **/
	SET_BIT(ADCSRA,ADCSRA_ADIE);

}
void ADC_voidInterruptDisable(void)
{
	/** Disbling Interrupt **/
	CLR_BIT(ADCSRA,ADCSRA_ADIE);
	/** Clear Flag **/
	SET_BIT(ADCSRA,ADCSRA_ADIF);

}

/** Function for one sample **/

/** For Polling **/
uint16 ADC_uint16GetDigitalValue(uint8 Copy_uint8ChannelNum)
{
	/**Clear channel number bits **/

	ADMUX &= ADC_CHANNEL_MSK;

	/** Select channel Number **/

	ADMUX |= Copy_uint8ChannelNum;

	/** After choosing the channel i start conversion**/

	SET_BIT(ADCSRA,ADCSRA_ADSC);
	/*polling technique*/

	while(GET_BIT(ADCSRA,ADCSRA_ADIF) == 0);
	/** Clearing the flag **/
	SET_BIT(ADCSRA,ADCSRA_ADIF);

	/** Read the ADC Value **/
	return ADC;
}
/*********************************/
/** For Interrupt **/

void ADC_u16StartConversion(uint8 Copy_uint8ChannelNum)
{
	ADMUX &= ADC_CHANNEL_MSK;
	ADMUX |= Copy_uint8ChannelNum;

	/*Start Conversion*/
	SET_BIT(ADCSRA,ADCSRA_ADSC);

}


void ADC_CallBck(void (*Copy_ptr)(void))
{
	Funcptr = Copy_ptr;
}





/** ISR of ADC**/
void __vector_16 (void) __attribute((signal));
void __vector_16 (void)
{
	if(Funcptr != NULL)
	{
		Funcptr();
	}
}





