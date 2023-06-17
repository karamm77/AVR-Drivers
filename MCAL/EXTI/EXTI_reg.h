#ifndef EXTI_REG_H_
#define EXTI_REG_H_


#define MCUCSR		*((volatile uint8*)0x54)



/** For INT2 Register MCUCSR **/
#define MCUCSR_INT2_ISC2		6u



/***********************************/

#define MCUCR		*((volatile uint8*) 0x55)
/** For INT0 Register MCUCR **/

#define MCUCR_INT0_ISC00		0u
#define MCUCR_INT0_ISC01		1u

/** For INT1 Register MCUCR **/

#define MCUCR_INT1_ISC10		2u
#define MCUCR_INT1_ISC11		3u


/**********************************/

#define GICR		*((volatile uint8*) 0x5B)
/** For INT0 Register GICR: Enabling specific Interrupt pin **/

#define GICR_INT0_EN		6u


/** For INT1 Register GICR: Enabling specific Interrupt pin **/

#define GICR_INT1_EN		7u

/** For INT0 Register GICR: Enabling specific Interrupt pin **/

#define GICR_INT2_EN		5u







#endif
