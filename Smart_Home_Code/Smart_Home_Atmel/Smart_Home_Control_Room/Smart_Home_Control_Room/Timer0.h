/*
 * Timer0.h
 *
 * Created: 2/18/2021 7:52:30 AM
 *  Author: osama yassin
 */ 


#ifndef TIMER0_H_
#define TIMER0_H_

#include "STD_Types.h"
#include "Timer0_HW.h"
#include "Timer0_Types.h"

Uint8 Timer0_CS_Select(Timer0_CS_Type ClockSource);
void  Timer0_Mode_Select(Timer0_WG_Mode_Type WG_Mode , Timer0_COM_Mode_Type CMO_Mode);
void  Timer0_Init(Timer0_Init_Type* Timer0_Init_Instance);

#endif /* TIMER0_H_ */