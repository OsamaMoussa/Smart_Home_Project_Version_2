/*
 * Led.c
 *
 * Created: 2/18/2021 5:35:27 PM
 *  Author: Osama Moussa
 */ 

#include "Led.h"

void Led_Init(void)
{
	DIO_Channel_Mode(Led_1,Output);
}
void Led_Toggle(void)
{
	DIO_Channel_Toggle(Led_1);
}
void Led_On(void)
{
	DIO_Channel_Write(Led_1,STD_High);
}
void Led_Off(void)
{
	DIO_Channel_Write(Led_1,STD_Low);
}