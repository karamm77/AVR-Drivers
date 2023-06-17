#ifndef LED_INTERFACE_H_
#define LED_INTERFACE_H_



#define Active_Low 		0u
#define Active_High		1u

typedef struct
{
	uint8 Type;
	uint8 Port;
	uint8 Pin;
}Led_t;

void Led_voidLedON(Led_t *object);
void Led_voidLedOFF(Led_t *object);
void Led_voidLedToggle(Led_t *object);


#endif
