#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "Keypad_interface.h"



#include "DIO_interface.h"/*Mcal*/
#include "CLCD_interface.h"/*HaL*/


#include <util/delay.h>


void main(void)
{





	CLCD_voidInit();
	KEYPAD_voidInit();


	sint16 Num1 = 0;
	sint16 Num2 = 0;
	sint16 result = 0;
	sint16 operation = 0;


	while (1) {
	    sint16 key = KEYPAD_GetPressedKey();

	    switch (key) {
	        case 1:
	        case 2:
	        case 3:
	        case 4:
	        case 5:
	        case 6:
	        case 7:
	        case 8:
	        case 9:
	            if (operation == 0) {
	                Num1 =  + key;
	                CLCD_voidSendNumber(Num1);
	            } else {
	                Num2 =  key;
	                CLCD_voidSendNumber(Num2);
	            }
	            break;
	        case 10:
	            operation = '+';
	            CLCD_voidSendData(operation);
	            break;
	        case 11:
	            operation = '-';
	            CLCD_voidSendData(operation);
	            break;
	        case 12:
	            operation = '*';
	            CLCD_voidSendData(operation);
	            break;
	        case 13:
	            operation = '/';
	            CLCD_voidSendData(operation);
	            break;
	        case 14:
	            if (operation == '+') {
	                result = Num1 + Num2;
	            } else if (operation == '-') {
	                result = Num1 - Num2;
	            } else if (operation == '*') {
	                result = Num1 * Num2;
	            } else if (operation == '/') {
	                if (Num2 != 0) {
	                    result = Num1 / Num2;
	                }
	            }

	            CLCD_voidSendData('=');
	            CLCD_voidSendNumber(result);
	            operation = 0;
	            Num1 = 0;
	            Num2 = 0;
	            break;
	        default:
	            break;
	    }
	}









}
