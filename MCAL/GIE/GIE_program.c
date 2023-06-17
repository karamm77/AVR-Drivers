#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "GIE_interface.h"
#include "GIE_reg.h"
#include "GIE_cfg.h"



/** using inline assembly is useful to be more faster in some critical cases**/
void GIE_voidEnableGlobal(void)
{
	//SET_BIT(GIE_SREG,SREG_I);
	 __asm __volatile("SEI");  /** To enable the Global Interrupt**/
}

void GIE_voidDisableGlobal(void)
{
	//CLR_BIT(GIE_SREG,SREG_I);
	__asm __volatile("CLI");/**To Disable the global interrupt**/
}
