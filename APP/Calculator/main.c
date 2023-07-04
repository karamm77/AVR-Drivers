#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "Keypad_interface.h"
#include "DIO_interface.h"
#include "CLCD_interface.h"

#define Max				1000

#include <util/delay.h>

void main(void)
{
    CLCD_voidInit();
    KEYPAD_voidInit();

    uint32 Num1 = 0;
    uint32 Num2 = 0;
    uint32 result = 0;
    uint8 operation = 0;

    while (1) {
        uint8 key = KEYPAD_GetPressedKey();


        switch (key) {
            case '0':
            case'1':
            case'2':
            case'3':
            case'4':
            case'5':
            case'6':
            case'7':
            case'8':
            case'9':
               if(operation == 0) {

                   Num1 = ((Num1 * 10 )+ (key - '0'));


                   if(Num1 <= Max)
                   {
                	   CLCD_voidSendNumber(key-'0');
                   }

                } else {
                    Num2 = Num2 * 10 + (key - '0');
                    if(Num2 <= Max)
                     {
                  	   CLCD_voidSendNumber(key-'0');
                     }

                }
                break;
            case '+':
                operation = '+';
                CLCD_voidSendData('+');
                break;
            case '-':
                operation = '-';
                CLCD_voidSendData('-');
                break;
            case '*':
                operation = '*';
                CLCD_voidSendData('*');
                break;
            case '/':
                operation = '/';
                CLCD_voidSendData('/');
                break;
            case '=':
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
