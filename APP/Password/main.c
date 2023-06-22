#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "DIO_interface.h"
#include "CLCD_interface.h"
#include "Keypad_interface.h"
#include "util/delay.h"

void main(void)
{
    CLCD_voidInit();
    KEYPAD_voidInit();

    CLCD_u8SendString("Pass:");
    _delay_ms(2000);

    CLCD_voidGoToXY(1, 0);

    uint8 x[3] = {1, 1, 2};
    uint8 pass[3];
    uint8 i = 0;
    uint8 flag = 0;

    while (1)
    {
        if (flag == 0)
        {
            for (i = 0; i < 3; i++)
            {
                do
                {
                    pass[i] = KEYPAD_GetPressedKey();
                } while (pass[i] == 0xFF);
                CLCD_voidSendData('*');
            }

            if ((pass[0] == x[0]) && (pass[1] == x[1]) && (pass[2] == x[2]))
            {
                flag = 1;
                CLCD_voidClrScr();
                CLCD_u8SendString("Welcome");
                _delay_ms(2000);

                CLCD_voidClrScr();
                CLCD_u8SendString("Pass:");
                CLCD_voidGoToXY(1, 0);
            }
            else
            {
                CLCD_voidClrScr();
                CLCD_u8SendString("Fail");
                _delay_ms(1000);

                CLCD_voidClrScr();
                CLCD_u8SendString("Pass:");
                CLCD_voidGoToXY(1, 0);
            }
        }
        else
        {
            CLCD_voidClrScr();
            CLCD_u8SendString("LOCKED!");
            _delay_ms(3000);
            flag = 0;
        }
    }
}
