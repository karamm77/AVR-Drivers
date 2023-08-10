#ifndef GIE_REG_H_
#define GIE_REG_H_

#define GIE_SREG		*((volatile uint8*) 0x5F) /**Status Register**/
#define SREG_I				7u /** opening and closing global interrupt*/

#endif
