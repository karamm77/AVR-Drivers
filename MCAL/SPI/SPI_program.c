#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"

#include "SPI_interface.h"
#include "SPI_cfg.h"
#include "SPI_prv.h"

void SPI_voidInit(void)
{
#if SPI_NODE == MASTER
    SET_BIT(SPCR, SPCR_MSTR);
#elif SPI_NODE == SLAVE
    CLR_BIT(SPCR, SPCR_MSTR);
#else
#error Wrong SPI_NODE configuration
#endif

    /** Master Mode and dividing by 128 **/
#if SPI_NODE == MASTER
    SET_BIT(SPCR, SPCR_SPR0);
    SET_BIT(SPCR, SPCR_SPR1);
    CLR_BIT(SPSR, SPSR_SPI2X);
#endif

    /** Enable SPI **/
    SET_BIT(SPCR, SPCR_SPE);
}


uint8 SPI_u8Tranceive(uint8 Copy_u8Data)
{

	SPDR = Copy_u8Data;
	while(GET_BIT(SPSR,SPSR_SPIF) == 0);
	return SPDR;


}
