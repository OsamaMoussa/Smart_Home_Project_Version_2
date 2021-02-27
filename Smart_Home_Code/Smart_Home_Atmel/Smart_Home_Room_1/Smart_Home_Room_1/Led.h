/*
 * Led.h
 *
 * Created: 2/18/2021 5:35:08 PM
 *  Author: Osama Moussa
 */ 


#ifndef LED_H_
#define LED_H_

#include "STD_Types.h"
#include "DIO.h"

#define Led_1 DIO_Channel_C7

void Led_Init(void);
void Led_Toggle(void);
void Led_On(void);
void Led_Off(void);

#endif /* LED_H_ */