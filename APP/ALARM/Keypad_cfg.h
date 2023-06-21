#ifndef KEYPAD_CFG_H_
#define KEYPAD_CFG_H_


#define KPD_u8Col_PORT		DIO_u8PORTD
#define KPD_u8Col1_PIN		DIO_u8PIN7
#define KPD_u8Col2_PIN		DIO_u8PIN6
#define KPD_u8Col3_PIN		DIO_u8PIN5
#define KPD_u8Col4_PIN		DIO_u8PIN3


#define KPD_u8Row_PORT		DIO_u8PORTC
#define KPD_u8Row1_PIN		DIO_u8PIN5
#define KPD_u8Row2_PIN		DIO_u8PIN4
#define KPD_u8Row3_PIN		DIO_u8PIN3
#define KPD_u8Row4_PIN		DIO_u8PIN2





#define KEY_PRESSED_VAL		0XFF

#define ROW_NUM				4u
#define COL_NUM				4u

#define KPD_u8BUTTON_ARR		 	{{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}}

// {{'4','8','0','*'},{'3','7','.','+'},{'2','6','=','-'},{'1','5','9','%'}};

#endif
