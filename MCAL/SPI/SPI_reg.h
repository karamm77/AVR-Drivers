#ifndef SPI_REG_H
#define SPI_REG_H





#define SPCR							*((volatile uint8*)0x2D)								/*	Control Register	*/
#define SPCR_SPCR0						0u								/*						*/
#define SPCR_SPCR1                      1u
#define SPCR_CPHA                       2u
#define SPCR_CPOL                       3u
#define SPCR_MSTR                       4u
#define SPCR_DORD                       5u
#define SPCR_SPE                        6u
#define SPCR_SPIE                       7u								/*SPI Enable interrupt flag*/



#define SPSR							*((volatile uint8*)0x2E)							/* status register 		*/
#define SPSR_SPI2X						 0u
#define SPSR_WCOL						 6u
#define SPSR_SPIF					     7u


#define SPDR							*((volatile uint8*)0x2F)							/*	Data Register		*/










#endif
