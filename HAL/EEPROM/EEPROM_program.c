#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include<util/delay.h>
#include "TWI_interface.h"
#include "EEPROM_interface.h"
#include "EEPROM_cfg.h"
#include "EEPROM_prv.h"


uint8 EEPROM_u8WriteDataByte(uint16 Copy_u16LocAddress, uint8 Copy_u8DataByte)
{

	uint8 Local_Error = OK;


	if(Copy_u16LocAddress <= MAX_EEPROM_ADD)
	{
		uint8 Local_u8AddressPacket = EEPROM_FIXED_ADD | (EEPROM_A2_CONNECTION << 2u) |(uint8)(Copy_u16LocAddress >> 8u);

		TWI_SendStartCondition();
		/*SEND the device address 1010 + A2 + l9+l8*/
		TWI_SendSlaveAddressWithWrite(Local_u8AddressPacket);

		/*Send first data byte with the Location address in the device that we put its address andwe cast it */

		TWI_MstrWriteDataByte((uint8)Copy_u16LocAddress);

		/* Send the useful data */
		TWI_MstrWriteDataByte(Copy_u8DataByte);

		TWI_SendStopCondition();

		/*wait for 10ms*/
		_delay_ms(10);
	}
	else
	{
		Local_Error = NOK;
	}






	return Local_Error;
}



uint8 EEPROM_u8ReadDataByte(uint16 Copy_u16LocAddress, uint8* Copy_u8DataByte)
{
	uint8 Local_Error = OK;

	if(Copy_u8DataByte != NULL)
	{
		if(Copy_u16LocAddress <= MAX_EEPROM_ADD)
		{
			uint8 Local_u8AddressPacket = EEPROM_FIXED_ADD | (EEPROM_A2_CONNECTION << 2u) |(uint8)(Copy_u16LocAddress >> 8u);

			TWI_SendStartCondition();
			/*SEND the device address 1010 + A2 + l9+l8*/
			TWI_SendSlaveAddressWithWrite(Local_u8AddressPacket);

			/*Send first data byte with the Location address in the device that we put its address andwe cast it */

			TWI_MstrWriteDataByte((uint8)Copy_u16LocAddress);

			/*	Send repeated start to change to read request */
			TWI_SendRepeatedStart();

			TWI_SendSlaveAddressWithRead(Local_u8AddressPacket);

			/* Send the useful data */
			TWI_MstrReadDataByte(Copy_u8DataByte);

			TWI_SendStopCondition();

			/*wait for 10ms*/

		}
		else
		{
			Local_Error = NOK;
		}
	}
	else
	{
		Local_Error = NullPtrErro;
	}
	return Local_Error;

}
