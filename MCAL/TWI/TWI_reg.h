#ifndef TWI_REG_H_
#define TWI_REG_H_


#define TWBR				*((volatile uint8*)0x20)			//TWI BIT RATE REGISTER




#define TWCR				*((volatile uint8*)0x56)			//CONTROL REGISTER

#define TWCR_TWIE					0u	/*	Interrupt Enable	*/
#define TWCR_TWEN					2u	/*	Enable Bit			*/
#define TWCR_TWSTO					4u	/*	Stop Condition Bit	*/
#define TWCR_TWSTA					5u	/*	Start Condition Bit	*/
#define TWCR_TWEA					6u	/*	ACKNOWLEDEGE BIT	*/
#define TWCR_TWINT					7u	/*	Interrupt flag bit	*/


#define TWSR				*((volatile uint8*)0x21)		/*	Status Register	*/
#define TWSR_TWPS0			0u
#define TWSR_TWPS1			1u



#define TWDR				*((volatile uint8*)0x23)	/*	DATA Register	*/

#define TWDR_BIT0					0u



#define TWAR				*((volatile uint8*)0x22)/*	Slave Address register*/
#define TWAR_TWGCE				0u /*General Call Bit*/

#define Approave_General_Call			1u
#define DONt_Approave					2u






















#endif
