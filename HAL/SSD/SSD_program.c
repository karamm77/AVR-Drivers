/**************************************************************************************************/
/**************************************************************************************************/
/**************************************************************************************************/
/*								 Author : Abdelrahman Elnahas 									  */									
/*								 SWC	: SSD													  */
/*								 Layer  : HAL													  */
/**************************************************************************************************/
/**************************************************************************************************/
/**************************************************************************************************/


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "SSD_interface.h"

#include "DIO_interface.h"


void SSD_vidInitSSD(SSD_t * Copy_SSDInfo)
{
	DIO_u8SetPortDirection(Copy_SSDInfo->SSD_u8Port , DIOI_OUTPUT);
	DIO_u8SetPinDirection(Copy_SSDInfo->SSD_u8EnablePort , Copy_SSDInfo->SSD_u8EnablePin ,DIOI_OUTPUT);
}



void SSD_vidDisplaySSD(SSD_t * Copy_SSDInfo , u8 Copy_u8Number)
{
	if ( Copy_SSDInfo->SSD_u8Common == SSD_COM_ANODE )
	{
		DIO_u8SetPortValue(Copy_SSDInfo->SSD_u8Port , ~Copy_u8Number);
		DIO_u8SetPinValue(Copy_SSDInfo->SSD_u8EnablePort , Copy_SSDInfo->SSD_u8EnablePin ,DIO_HIGH);
	}
	else if ( Copy_SSDInfo->SSD_u8Common == SSD_COM_CATHODE )
	{
		DIO_u8SetPortValue(Copy_SSDInfo->SSD_u8Port , Copy_u8Number);
		DIO_u8SetPinValue(Copy_SSDInfo->SSD_u8EnablePort , Copy_SSDInfo->SSD_u8EnablePin ,DIO_LOW);

	}
}

void SSD_vidDisableSSD(SSD_t * Copy_SSDInfo )
{
	if ( Copy_SSDInfo->SSD_u8Common == SSD_COM_ANODE )
	{
		DIO_u8SetPinValue(Copy_SSDInfo->SSD_u8EnablePort , Copy_SSDInfo->SSD_u8EnablePin ,DIO_LOW);
	}
	else if ( Copy_SSDInfo->SSD_u8Common == SSD_COM_CATHODE )
	{
		DIO_u8SetPinValue(Copy_SSDInfo->SSD_u8EnablePort , Copy_SSDInfo->SSD_u8EnablePin ,DIO_HIGH);

	}

}







void SSD_vidInitSSDDecoder(SSD_t_decoder * Copy_SSDInfo)
{

	for(u8 counter =0 ; counter<4 ; counter++)	
	{
			DIO_u8SetPinDirection(Copy_SSDInfo->SSD_u8Port , Copy_SSDInfo->SSD_u8Pins[counter] , DIOI_OUTPUT);
	}
	DIO_u8SetPinDirection(Copy_SSDInfo->SSD_u8EnablePort , Copy_SSDInfo->SSD_u8EnablePin , DIOI_OUTPUT);
}


void SSD_vidDisplaySSDDecoder(SSD_t_decoder * Copy_SSDInfo , u8 Copy_u8Number)
{
	//u8 Local_u8PortValue = 0b11101000 ;
	if ( Copy_SSDInfo->SSD_u8Common == SSD_COM_CATHODE )
	{
		switch(Copy_u8Number)
		{
			case SSD_ZERO_DECODER	 : DIO_u8SetPinValue(Copy_SSDInfo->SSD_u8Port , Copy_SSDInfo->SSD_u8Pins[0], DIO_LOW);
									   DIO_u8SetPinValue(Copy_SSDInfo->SSD_u8Port , Copy_SSDInfo->SSD_u8Pins[1], DIO_LOW);
									   DIO_u8SetPinValue(Copy_SSDInfo->SSD_u8Port , Copy_SSDInfo->SSD_u8Pins[2], DIO_LOW);
									   DIO_u8SetPinValue(Copy_SSDInfo->SSD_u8Port , Copy_SSDInfo->SSD_u8Pins[3], DIO_LOW);
									   DIO_u8SetPinValue(Copy_SSDInfo->SSD_u8EnablePort , Copy_SSDInfo->SSD_u8EnablePin ,DIO_LOW);
									   break ;
									   
			case SSD_ONE_DECODER	 : DIO_u8SetPinValue(Copy_SSDInfo->SSD_u8Port , Copy_SSDInfo->SSD_u8Pins[0], DIO_HIGH);
									   DIO_u8SetPinValue(Copy_SSDInfo->SSD_u8Port , Copy_SSDInfo->SSD_u8Pins[1], DIO_LOW);
									   DIO_u8SetPinValue(Copy_SSDInfo->SSD_u8Port , Copy_SSDInfo->SSD_u8Pins[2], DIO_LOW);
									   DIO_u8SetPinValue(Copy_SSDInfo->SSD_u8Port , Copy_SSDInfo->SSD_u8Pins[3], DIO_LOW);
									   DIO_u8SetPinValue(Copy_SSDInfo->SSD_u8EnablePort , Copy_SSDInfo->SSD_u8EnablePin ,DIO_LOW);
									   break ;
			
			
			case SSD_TWO_DECODER	 : DIO_u8SetPinValue(Copy_SSDInfo->SSD_u8Port , Copy_SSDInfo->SSD_u8Pins[0], DIO_LOW);
									   DIO_u8SetPinValue(Copy_SSDInfo->SSD_u8Port , Copy_SSDInfo->SSD_u8Pins[1], DIO_HIGH);
									   DIO_u8SetPinValue(Copy_SSDInfo->SSD_u8Port , Copy_SSDInfo->SSD_u8Pins[2], DIO_LOW);
									   DIO_u8SetPinValue(Copy_SSDInfo->SSD_u8Port , Copy_SSDInfo->SSD_u8Pins[3], DIO_LOW);
									   DIO_u8SetPinValue(Copy_SSDInfo->SSD_u8EnablePort , Copy_SSDInfo->SSD_u8EnablePin ,DIO_LOW);
									   break ;
			
			
			case SSD_THREE_DECODER	 : DIO_u8SetPinValue(Copy_SSDInfo->SSD_u8Port , Copy_SSDInfo->SSD_u8Pins[0], DIO_HIGH);
									   DIO_u8SetPinValue(Copy_SSDInfo->SSD_u8Port , Copy_SSDInfo->SSD_u8Pins[1], DIO_HIGH);
									   DIO_u8SetPinValue(Copy_SSDInfo->SSD_u8Port , Copy_SSDInfo->SSD_u8Pins[2], DIO_LOW);
									   DIO_u8SetPinValue(Copy_SSDInfo->SSD_u8Port , Copy_SSDInfo->SSD_u8Pins[3], DIO_LOW);
									   DIO_u8SetPinValue(Copy_SSDInfo->SSD_u8EnablePort , Copy_SSDInfo->SSD_u8EnablePin ,DIO_LOW);
									   break ;
			
			
			case SSD_FOUR_DECODER	 : DIO_u8SetPinValue(Copy_SSDInfo->SSD_u8Port , Copy_SSDInfo->SSD_u8Pins[0], DIO_LOW);
									   DIO_u8SetPinValue(Copy_SSDInfo->SSD_u8Port , Copy_SSDInfo->SSD_u8Pins[1], DIO_LOW);
									   DIO_u8SetPinValue(Copy_SSDInfo->SSD_u8Port , Copy_SSDInfo->SSD_u8Pins[2], DIO_HIGH);
									   DIO_u8SetPinValue(Copy_SSDInfo->SSD_u8Port , Copy_SSDInfo->SSD_u8Pins[3], DIO_LOW);
									   DIO_u8SetPinValue(Copy_SSDInfo->SSD_u8EnablePort , Copy_SSDInfo->SSD_u8EnablePin ,DIO_LOW);
									   break ;
			
			case SSD_FIVE_DECODER	 : DIO_u8SetPinValue(Copy_SSDInfo->SSD_u8Port , Copy_SSDInfo->SSD_u8Pins[0], DIO_HIGH);
									   DIO_u8SetPinValue(Copy_SSDInfo->SSD_u8Port , Copy_SSDInfo->SSD_u8Pins[1], DIO_LOW);
									   DIO_u8SetPinValue(Copy_SSDInfo->SSD_u8Port , Copy_SSDInfo->SSD_u8Pins[2], DIO_HIGH);
									   DIO_u8SetPinValue(Copy_SSDInfo->SSD_u8Port , Copy_SSDInfo->SSD_u8Pins[3], DIO_LOW);
									   DIO_u8SetPinValue(Copy_SSDInfo->SSD_u8EnablePort , Copy_SSDInfo->SSD_u8EnablePin ,DIO_LOW);
									   break ;
			
			case SSD_SIX_DECODER	 : DIO_u8SetPinValue(Copy_SSDInfo->SSD_u8Port , Copy_SSDInfo->SSD_u8Pins[0], DIO_LOW);
									   DIO_u8SetPinValue(Copy_SSDInfo->SSD_u8Port , Copy_SSDInfo->SSD_u8Pins[1], DIO_HIGH);
									   DIO_u8SetPinValue(Copy_SSDInfo->SSD_u8Port , Copy_SSDInfo->SSD_u8Pins[2], DIO_HIGH);
									   DIO_u8SetPinValue(Copy_SSDInfo->SSD_u8Port , Copy_SSDInfo->SSD_u8Pins[3], DIO_LOW);
									   DIO_u8SetPinValue(Copy_SSDInfo->SSD_u8EnablePort , Copy_SSDInfo->SSD_u8EnablePin ,DIO_LOW);
									   break ;
			
			case SSD_SEVEN_DECODER	 : DIO_u8SetPinValue(Copy_SSDInfo->SSD_u8Port , Copy_SSDInfo->SSD_u8Pins[0], DIO_HIGH);
									   DIO_u8SetPinValue(Copy_SSDInfo->SSD_u8Port , Copy_SSDInfo->SSD_u8Pins[1], DIO_HIGH);
									   DIO_u8SetPinValue(Copy_SSDInfo->SSD_u8Port , Copy_SSDInfo->SSD_u8Pins[2], DIO_HIGH);
									   DIO_u8SetPinValue(Copy_SSDInfo->SSD_u8Port , Copy_SSDInfo->SSD_u8Pins[3], DIO_LOW);
									   DIO_u8SetPinValue(Copy_SSDInfo->SSD_u8EnablePort , Copy_SSDInfo->SSD_u8EnablePin ,DIO_LOW);
									   break ;
			
			case SSD_EIGHT_DECODER	 : DIO_u8SetPinValue(Copy_SSDInfo->SSD_u8Port , Copy_SSDInfo->SSD_u8Pins[0], DIO_LOW);
									   DIO_u8SetPinValue(Copy_SSDInfo->SSD_u8Port , Copy_SSDInfo->SSD_u8Pins[1], DIO_LOW);
									   DIO_u8SetPinValue(Copy_SSDInfo->SSD_u8Port , Copy_SSDInfo->SSD_u8Pins[2], DIO_LOW);
									   DIO_u8SetPinValue(Copy_SSDInfo->SSD_u8Port , Copy_SSDInfo->SSD_u8Pins[3], DIO_HIGH);
									   DIO_u8SetPinValue(Copy_SSDInfo->SSD_u8EnablePort , Copy_SSDInfo->SSD_u8EnablePin ,DIO_LOW);
									   break ;
			
			case SSD_NINE_DECODER	 : DIO_u8SetPinValue(Copy_SSDInfo->SSD_u8Port , Copy_SSDInfo->SSD_u8Pins[0], DIO_HIGH);
									   DIO_u8SetPinValue(Copy_SSDInfo->SSD_u8Port , Copy_SSDInfo->SSD_u8Pins[1], DIO_LOW);
									   DIO_u8SetPinValue(Copy_SSDInfo->SSD_u8Port , Copy_SSDInfo->SSD_u8Pins[2], DIO_LOW);
									   DIO_u8SetPinValue(Copy_SSDInfo->SSD_u8Port , Copy_SSDInfo->SSD_u8Pins[3], DIO_HIGH);
									   DIO_u8SetPinValue(Copy_SSDInfo->SSD_u8EnablePort , Copy_SSDInfo->SSD_u8EnablePin ,DIO_LOW);
									   break ;
									
			default					:  break ;
		}

		
	}
	
	
	else if ( Copy_SSDInfo->SSD_u8Common == SSD_COM_ANODE )
	{
		switch(Copy_u8Number)
		{
			case SSD_ZERO_DECODER	 : DIO_u8SetPinValue(Copy_SSDInfo->SSD_u8Port , Copy_SSDInfo->SSD_u8Pins[0], !DIO_LOW);
									   DIO_u8SetPinValue(Copy_SSDInfo->SSD_u8Port , Copy_SSDInfo->SSD_u8Pins[1], !DIO_LOW);
									   DIO_u8SetPinValue(Copy_SSDInfo->SSD_u8Port , Copy_SSDInfo->SSD_u8Pins[2], !DIO_LOW);
									   DIO_u8SetPinValue(Copy_SSDInfo->SSD_u8Port , Copy_SSDInfo->SSD_u8Pins[3], !DIO_LOW);
									   DIO_u8SetPinValue(Copy_SSDInfo->SSD_u8EnablePort , Copy_SSDInfo->SSD_u8EnablePin ,!DIO_LOW);
									   break ;
			
			case SSD_ONE_DECODER	 : DIO_u8SetPinValue(Copy_SSDInfo->SSD_u8Port , Copy_SSDInfo->SSD_u8Pins[0], !DIO_HIGH);
									   DIO_u8SetPinValue(Copy_SSDInfo->SSD_u8Port , Copy_SSDInfo->SSD_u8Pins[1], !DIO_LOW);
									   DIO_u8SetPinValue(Copy_SSDInfo->SSD_u8Port , Copy_SSDInfo->SSD_u8Pins[2], !DIO_LOW);
									   DIO_u8SetPinValue(Copy_SSDInfo->SSD_u8Port , Copy_SSDInfo->SSD_u8Pins[3], !DIO_LOW);
									   DIO_u8SetPinValue(Copy_SSDInfo->SSD_u8EnablePort , Copy_SSDInfo->SSD_u8EnablePin ,!DIO_LOW);
									   break ;
			
			
			case SSD_TWO_DECODER	 : DIO_u8SetPinValue(Copy_SSDInfo->SSD_u8Port , Copy_SSDInfo->SSD_u8Pins[0], !DIO_LOW);
									   DIO_u8SetPinValue(Copy_SSDInfo->SSD_u8Port , Copy_SSDInfo->SSD_u8Pins[1], !DIO_HIGH);
									   DIO_u8SetPinValue(Copy_SSDInfo->SSD_u8Port , Copy_SSDInfo->SSD_u8Pins[2], !DIO_LOW);
									   DIO_u8SetPinValue(Copy_SSDInfo->SSD_u8Port , Copy_SSDInfo->SSD_u8Pins[3], !DIO_LOW);
									   DIO_u8SetPinValue(Copy_SSDInfo->SSD_u8EnablePort , Copy_SSDInfo->SSD_u8EnablePin ,!DIO_LOW);
									   break ;
			
			
			case SSD_THREE_DECODER	 : DIO_u8SetPinValue(Copy_SSDInfo->SSD_u8Port , Copy_SSDInfo->SSD_u8Pins[0],!DIO_HIGH);
									   DIO_u8SetPinValue(Copy_SSDInfo->SSD_u8Port , Copy_SSDInfo->SSD_u8Pins[1],!DIO_HIGH);
									   DIO_u8SetPinValue(Copy_SSDInfo->SSD_u8Port , Copy_SSDInfo->SSD_u8Pins[2],!DIO_LOW);
									   DIO_u8SetPinValue(Copy_SSDInfo->SSD_u8Port , Copy_SSDInfo->SSD_u8Pins[3],!DIO_LOW);
									   DIO_u8SetPinValue(Copy_SSDInfo->SSD_u8EnablePort , Copy_SSDInfo->SSD_u8EnablePin ,!DIO_LOW);
									   break ;
			
			
			case SSD_FOUR_DECODER	 : DIO_u8SetPinValue(Copy_SSDInfo->SSD_u8Port , Copy_SSDInfo->SSD_u8Pins[0], !DIO_LOW);
									   DIO_u8SetPinValue(Copy_SSDInfo->SSD_u8Port , Copy_SSDInfo->SSD_u8Pins[1], !DIO_LOW);
									   DIO_u8SetPinValue(Copy_SSDInfo->SSD_u8Port , Copy_SSDInfo->SSD_u8Pins[2], !DIO_HIGH);
									   DIO_u8SetPinValue(Copy_SSDInfo->SSD_u8Port , Copy_SSDInfo->SSD_u8Pins[3], !DIO_LOW);
									   DIO_u8SetPinValue(Copy_SSDInfo->SSD_u8EnablePort , Copy_SSDInfo->SSD_u8EnablePin ,!DIO_LOW);
									   break ;
			
			case SSD_FIVE_DECODER	 : DIO_u8SetPinValue(Copy_SSDInfo->SSD_u8Port , Copy_SSDInfo->SSD_u8Pins[0], !DIO_HIGH);
									   DIO_u8SetPinValue(Copy_SSDInfo->SSD_u8Port , Copy_SSDInfo->SSD_u8Pins[1], !DIO_LOW);
									   DIO_u8SetPinValue(Copy_SSDInfo->SSD_u8Port , Copy_SSDInfo->SSD_u8Pins[2], !DIO_HIGH);
									   DIO_u8SetPinValue(Copy_SSDInfo->SSD_u8Port , Copy_SSDInfo->SSD_u8Pins[3], !DIO_LOW);
									   DIO_u8SetPinValue(Copy_SSDInfo->SSD_u8EnablePort , Copy_SSDInfo->SSD_u8EnablePin ,!DIO_LOW);
									   break ;
			
			case SSD_SIX_DECODER	 : DIO_u8SetPinValue(Copy_SSDInfo->SSD_u8Port , Copy_SSDInfo->SSD_u8Pins[0], !DIO_LOW);
									   DIO_u8SetPinValue(Copy_SSDInfo->SSD_u8Port , Copy_SSDInfo->SSD_u8Pins[1], !DIO_HIGH);
									   DIO_u8SetPinValue(Copy_SSDInfo->SSD_u8Port , Copy_SSDInfo->SSD_u8Pins[2], !DIO_HIGH);
									   DIO_u8SetPinValue(Copy_SSDInfo->SSD_u8Port , Copy_SSDInfo->SSD_u8Pins[3], !DIO_LOW);
									   DIO_u8SetPinValue(Copy_SSDInfo->SSD_u8EnablePort , Copy_SSDInfo->SSD_u8EnablePin ,!DIO_LOW);
									   break ;
			
			case SSD_SEVEN_DECODER	 : DIO_u8SetPinValue(Copy_SSDInfo->SSD_u8Port , Copy_SSDInfo->SSD_u8Pins[0],!DIO_HIGH);
									   DIO_u8SetPinValue(Copy_SSDInfo->SSD_u8Port , Copy_SSDInfo->SSD_u8Pins[1],!DIO_HIGH);
									   DIO_u8SetPinValue(Copy_SSDInfo->SSD_u8Port , Copy_SSDInfo->SSD_u8Pins[2],!DIO_HIGH);
									   DIO_u8SetPinValue(Copy_SSDInfo->SSD_u8Port , Copy_SSDInfo->SSD_u8Pins[3],!DIO_LOW);
									   DIO_u8SetPinValue(Copy_SSDInfo->SSD_u8EnablePort , Copy_SSDInfo->SSD_u8EnablePin ,!DIO_LOW);
									   break ;
			
			case SSD_EIGHT_DECODER	 : DIO_u8SetPinValue(Copy_SSDInfo->SSD_u8Port , Copy_SSDInfo->SSD_u8Pins[0],!DIO_LOW);
									   DIO_u8SetPinValue(Copy_SSDInfo->SSD_u8Port , Copy_SSDInfo->SSD_u8Pins[1],!DIO_LOW);
									   DIO_u8SetPinValue(Copy_SSDInfo->SSD_u8Port , Copy_SSDInfo->SSD_u8Pins[2],!DIO_LOW);
									   DIO_u8SetPinValue(Copy_SSDInfo->SSD_u8Port , Copy_SSDInfo->SSD_u8Pins[3],!DIO_HIGH);
									   DIO_u8SetPinValue(Copy_SSDInfo->SSD_u8EnablePort , Copy_SSDInfo->SSD_u8EnablePin ,!DIO_LOW);
									   break ;
			
			case SSD_NINE_DECODER	 : DIO_u8SetPinValue(Copy_SSDInfo->SSD_u8Port , Copy_SSDInfo->SSD_u8Pins[0], !DIO_HIGH);
									   DIO_u8SetPinValue(Copy_SSDInfo->SSD_u8Port , Copy_SSDInfo->SSD_u8Pins[1], !DIO_LOW);
									   DIO_u8SetPinValue(Copy_SSDInfo->SSD_u8Port , Copy_SSDInfo->SSD_u8Pins[2], !DIO_LOW);
									   DIO_u8SetPinValue(Copy_SSDInfo->SSD_u8Port , Copy_SSDInfo->SSD_u8Pins[3], !DIO_HIGH);
									   DIO_u8SetPinValue(Copy_SSDInfo->SSD_u8EnablePort , Copy_SSDInfo->SSD_u8EnablePin ,!DIO_LOW);
									   break ;
			
			default					:  break ;		
		}
	}
}



void SSD_vidDisableSSDDecoder(SSD_t_decoder * Copy_SSDInfo) 
{
	
	if ( Copy_SSDInfo->SSD_u8Common == SSD_COM_CATHODE )
	{
		DIO_u8SetPinValue(Copy_SSDInfo->SSD_u8EnablePort , Copy_SSDInfo->SSD_u8EnablePin ,DIO_HIGH);
	}
	else if  ( Copy_SSDInfo->SSD_u8Common == SSD_COM_ANODE )
	{
		DIO_u8SetPinValue(Copy_SSDInfo->SSD_u8EnablePort , Copy_SSDInfo->SSD_u8EnablePin ,DIO_LOW);
	}
}
