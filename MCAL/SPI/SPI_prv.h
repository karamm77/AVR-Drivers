#ifndef SPI_PRV_H_
#define SPI_PRV_H_




#define SPCR			*((volatile uint8*)0x2D)

#define SPCR_SPR0			0u
#define SPCR_SPR1			1u
#define SPCR_CPHA			2u
#define SPCR_CPOL			3u
#define SPCR_MSTR			4u
#define SPCR_DORD			5u
#define SPCR_SPE			6u
#define SPCR_SPIE			7u





#define SPSR			*((volatile uint8*)0x2E)

#define SPSR_SPI2X			0u
#define SPSR_WCOL			6u
#define SPSR_SPIF			7u

#define SPDR			*((volatile uint8*)0x2F)

#define SPDR_LSB			0u
#define SPDR_MSB			1u


#define MASTER 				1u
#define SLAVE				2u






#endif
