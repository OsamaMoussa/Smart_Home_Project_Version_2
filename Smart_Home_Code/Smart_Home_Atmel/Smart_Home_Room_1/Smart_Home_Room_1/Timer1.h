/*
 * Timer1.h
 *
 * Created: 2/11/2021 6:16:54 PM
 *  Author: Osama Moussa
 */ 


#ifndef TIMER1_H_
#define TIMER1_H_

#include "STD_Types.h"
#include "Timer1_HW.h"
#include "Timer1_Types.h"

#define  F_CPU 16000000UL

Uint16 Timer1_Presc;
Uint16 Timer1_Top;

void Timer1_CS_Select(Timer1_CS_Type ClockSource);
void Timer1_Mode_Select(Timer1_WG_Mode_Type WG_Mode ,Timer1_COM_Type COM_Type ,Timer1_COM_Mode_Type COM_Mode);

void Timer1_Init(Timer1_Init_Type* Timer1_Init_Instance);
void Timer1_NonInv_FPWM_Duty(Timer1_COM_Type COM_Num , Float32 Duty);

#endif /* TIMER1_H_ */