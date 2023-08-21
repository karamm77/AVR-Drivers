#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "DIO_interface.h"
#include "SPI_interface.h"

#include "SPI_cfg.h"
#include "SPI_reg.h"
#include "SPI_prv.h"



void SPI_voidInit(void)
{


	/*		Define the state of the node		*/
#if NODE_STATE == MASTER
	SET_BIT(SPCR,SPCR_MSTR);
#elif NODE_STATE == SLAVE
	CLR_BIT(SPCR,SPCR_MSTR);
#endif

	/*		Define Clock phase and polarity		*/

#if (CPOL_STATE == CPOL_RISING) && (CPHA_STATE == CPHA_SETUP)
	CLR_BIT(SPCR,SPCR_CPOL);
	SET_BIT(SPCR,SPCR_CPHA);
#elif (CPOL_STATE == CPOL_FALLING) && (CPHA_STATE == CPHA_SETUP)
	SET_BIT(SPCR,SPCR_CPOL);
	SET_BIT(SPCR,SPCR_CPHA);
#elif (CPOL_STATE == CPOL_RISING) && (CPHA_STATE == CPHA_SAMPLE)
	CLR_BIT(SPCR,SPCR_CPOL);
	CLR_BIT(SPCR,SPCR_CPHA);
#elif (CPOL_STATE == CPOL_FALLING) && (CPHA_STATE == CPHA_SAMPLE)
	SET_BIT(SPCR,SPCR_CPOL);
	CLR_BIT(SPCR,SPCR_CPHA);
#endif

	/*		Define the prescaler				*/
#if PRESCALER_USED == PRESCALER_2
	CLR_BIT(SPCR,SPCR_SPCR0);
	CLR_BIT(SPCR,SPCR_SPCR1);
	SET_BIT(SPSR,SPSR_SPI2X);
#elif PRESCALER_USED == PRESCALER_128
	SET_BIT(SPCR,SPCR_SPCR0);
	SET_BIT(SPCR,SPCR_SPCR1);
	CLR_BIT(SPSR,SPSR_SPI2X);
#elif PRESCALER_USED == PRESCALER_4
	CLR_BIT(SPCR,SPCR_SPCR0);
	CLR_BIT(SPCR,SPCR_SPCR1);
	CLR_BIT(SPSR,SPSR_SPI2X);
#elif PRESCALER_USED == PRESCALER_64
	CLR_BIT(SPCR,SPCR_SPCR0);
	SET_BIT(SPCR,SPCR_SPCR1);
	CLR_BIT(SPSR,SPSR_SPI2X);
#endif

	/*		Define the sending order			*/
#if ORDER_USED == LSB_ORDER
	SET_BIT(SPCR,SPCR_DORD);
#elif ORDER_USED == MSB_ORDER
	CLR_BIT(SPCR,SPCR_DORD);
#endif



/**	ENABLE the peripheral				**/

	  SET_BIT(SPCR, SPCR_SPE);

}


uint8 SPI_u8Trancieve(uint8 Copy_u8Data)
{


	SPDR = Copy_u8Data;
	while((GET_BIT(SPSR,SPSR_SPIF)) == 0);
	return SPDR;

}

