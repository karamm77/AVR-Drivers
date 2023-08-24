#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "TWI_interface.h"
#include "TWI_program.h"
#include "TWI_private.h"
#include "TWI_reg.h"


/** We write operations first and then we resume the communication **/

void TWI_voidMasterInit(uint8 Copy_u8Address)
{
	/** SET the Address for the master itself, Do not allow general call, system clock 16MHZ	**/

	if(Copy_u8Address != 0u)
	{
		TWAR = Copy_u8Address << 1u;
	}

	SET_BIT(TWAR,TWAR_TWGCE);

	CLR_BIT(TWSR,TWSR_TWPS0);
	CLR_BIT(TWSR,TWSR_TWPS1);

	/** FOR SCL Speed 400 kbps, TWSR two BITS are set to zero and TWBR is set to 12 **/
	TWBR = 12u;

	/** Enable Acknowledge **/
	SET_BIT(TWCR,TWCR_TWEA);

	/** Enable peripheral **/
	SET_BIT(TWCR,TWCR_TWEN);
}
void TWI_voidSlaveInit(uint8 Copy_u8Address)
{
	TWAR = Copy_u8Address << 1u;

	TWBR = 12;


	SET_BIT(TWCR,TWCR_TWEN);
}

TWI_ERROR_t TWI_SendStartCondition(void)
{

	TWI_ERROR_t LOCAL_ERROR = NoError;

	/** Send Start condition **/
	SET_BIT(TWCR,TWCR_TWSTA);

	/** Enable interrupt flag: when interrupt flag is one it means communication is stopped and scl bus is low and when we clear it it allows communication to resume **/
	SET_BIT(TWCR,TWCR_TWINT);

	while(GET_BIT(TWCR,TWCR_TWINT) == 0);

	if((TWSR & STATUS_BITS_MASK) != START_ACK)
	{
		LOCAL_ERROR = StartConErr;
	}
	else
	{/*		DO Nothing		*/}



	return LOCAL_ERROR;
}
TWI_ERROR_t TWI_SendRepeatedStart(void)
{

	TWI_ERROR_t LOCAL_ERROR = NoError;

	/** Send Start condition **/
	SET_BIT(TWCR,TWCR_TWSTA);

	/** Enable interrupt flag: when interrupt flag is one it means communication is stopped and scl bus is low and when we clear it it allows communication to resume **/
	SET_BIT(TWCR,TWCR_TWINT);

	while(GET_BIT(TWCR,TWCR_TWINT) == 0);

	if((TWSR & STATUS_BITS_MASK) != REP_START_ACK)
	{
		LOCAL_ERROR = RepStarErr;
	}
	else
	{/*		DO Nothing		*/}



	return LOCAL_ERROR;


}

TWI_ERROR_t TWI_SendSlaveAddressWithWrite(uint8 Copy_u8SlaveAddress)
{
	/** when we enter here the communication is stopped so we prepare the instructions **/

	TWI_ERROR_t LOCAL_ERROR = NoError;


	TWDR = Copy_u8SlaveAddress << 1u;

	/** when write we clear the bit zero in TWDR **/
	CLR_BIT(TWDR,TWDR_BIT0);

	/** Clear the start condition bit **/
	CLR_BIT(TWCR,TWCR_TWSTA);

	/** CLEAR theflag by set logical one so the scl be high and communication resumes**/
	SET_BIT(TWCR,TWCR_TWINT);

	/** wait on flag to check if data sent **/

	while(GET_BIT(TWCR,TWCR_TWINT) == 0);


	if((TWSR & STATUS_BITS_MASK) != SLAVE_ADD_AND_WR_ACK)
	{
		LOCAL_ERROR = SlaveAddWithWriteErr;
	}
	else
	{/*		DO Nothing		*/}



	return LOCAL_ERROR;

}

TWI_ERROR_t TWI_SendSlaveAddressWithRead(uint8 Copy_u8SlaveAddress)
{

	/** when we enter here the communication is stopped so we prepare the instructions **/

	TWI_ERROR_t LOCAL_ERROR = NoError;


	TWDR = Copy_u8SlaveAddress << 1u;

	/** when write we clear the bit zero in TWDR **/
	SET_BIT(TWDR,TWDR_BIT0);

	/** Clear the start condition bit **/
	CLR_BIT(TWCR,TWCR_TWSTA);

	/** CLEAR the flag by set logical one so the scl be high and communication resumes**/
	SET_BIT(TWCR,TWCR_TWINT);

	/** wait on flag to check if data sent **/

	while(GET_BIT(TWCR,TWCR_TWINT) == 0);


	if((TWSR & STATUS_BITS_MASK) != SLAVE_ADD_AND_RD_ACK)
	{
		LOCAL_ERROR = SlaveAddWithReadErr;
	}
	else
	{/*		DO Nothing		*/}



	return LOCAL_ERROR;

}


TWI_ERROR_t TWI_MstrWriteDataByte(uint8 Copy_u8DataByte)
{
	TWI_ERROR_t LOCAL_ERROR = NoError;

	TWDR = Copy_u8DataByte;


	SET_BIT(TWCR,TWCR_TWINT);
	/** wait on flag to check if data sent **/

	while(GET_BIT(TWCR,TWCR_TWINT) == 0);


	if((TWSR & STATUS_BITS_MASK) != MSTR_WR_BYTE_ACK)
	{
		LOCAL_ERROR = MSTRWriteByteWithAckErr;
	}
	else
	{/*		DO Nothing		*/}



	return LOCAL_ERROR;




}

TWI_ERROR_t TWI_MstrReadDataByte(uint8* Copy_u8DataByte)
{
	TWI_ERROR_t LOCAL_ERROR = NoError;

	if(Copy_u8DataByte != NULL)
	{

		SET_BIT(TWCR,TWCR_TWINT);
		/** wait on flag to check if data sent **/

		while(GET_BIT(TWCR,TWCR_TWINT) == 0);


		if((TWSR & STATUS_BITS_MASK) != MSTR_RD_BYTE_WITH_ACK)
		{
			LOCAL_ERROR = MSTRReadByteWithAckErr;
		}
		else
		{
			*Copy_u8DataByte = TWDR; /* Reading the data from the data register */
		}



	}
	else
	{
		LOCAL_ERROR = NullPtrErro;
	}



	return LOCAL_ERROR;
}

void TWI_SendStopCondition(void)
{
	SET_BIT(TWCR,TWCR_TWSTO);
	SET_BIT(TWCR,TWCR_TWINT);
}
