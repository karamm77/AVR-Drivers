/**************************************************************************************************/
/**************************************************************************************************/
/**************************************************************************************************/
/*								 Author : KARAM ALBENDARY 										  */
/*								 SWC	: 7SEGMANT												 */
/*								 Layer  : HAL
 * 									INTERACE													  */
/**************************************************************************************************/
/**************************************************************************************************/
/**************************************************************************************************/


#ifndef SSEGMANT_INTERFACE_H_
#define SSEGMANT_INTERFACE_H_


/******** This function has enabling the Common Port and based on being Common Anode or Cathode**/
void SSD_voidInit(uint8 Copy_u8Port, uint8 Copy_u8Pin);



void SSD_voidDecoderInit(uint8 Copy_u8Port,uint8 Copy_u8Pin);

uint8 SSD_u8SSDisplay(uint8 Copy_u8Port, uint8 Copy_u8Pin, uint8 Copy_u8Value);


void SSD_voidDecoderDisable(uint8 Copy_u8Port,uint8 Copy_u8Pin);









#endif
