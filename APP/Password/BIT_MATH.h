#ifndef _BIT_MATH_H
#define _BIT_MATH_H

#define SET_BIT(VAR,BIT_NUM)   ((VAR) |= (1<<(BIT_NUM)))
#define CLR_BIT(VAR,BIT_NUM)   ((VAR) &= (~(1<<(BIT_NUM))))
#define TOG_BIT(VAR,BIT_NUM)   ((VAR) ^= (1<<(BIT_NUM)))
#define GET_BIT(VAR,BIT_NUM)   ((VAR>>BIT_NUM)&1)





#endif

/* #include<stdio.h>
#include "../BIT_MATH.h"
int bin(int x);
int hex(int x);
int oct(int x);
int main()
{
	int Bin,Hex, Oct;
	int x = 33;
	Bin = bin(33);
	Hex = hex(33);
	Oct = oct(33);
	printf("Bin is %d\nHexa is %d\noctal is %d\n",Bin,Hex,Oct);
	
}
int bin(int x)
{
	int i, rem,sum = 0, new = 0;
	while(x != 0)
	{
		rem = x%2;
		sum =(sum*10)+rem;
		x /=2;
	}
	while(sum != 0 )
	{
		rem = sum %10;
		new = (new*10) + rem;
		sum /=10;
	}
	
	return new;
}
int hex(int x)
{
	int i, rem,sum = 0, new = 0;
	while(x != 0)
	{
		rem = x%16;
		sum =(sum*10)+rem;
		x /=16;
	}
	while(sum != 0 )
	{
		rem = sum %10;
		new = (new*10) + rem;
		sum /=10;
	}
	
	return new;
}
int oct(int x)
{
	int i, rem,sum = 0, new = 0;
	while(x != 0)
	{
		rem = x%8;
		sum =(sum*10)+rem;
		x /=8;
	}
	while(sum != 0 )
	{
		rem = sum %10;
		new = (new*10) + rem;
		sum /=10;
	}
	
	return new;
} */
