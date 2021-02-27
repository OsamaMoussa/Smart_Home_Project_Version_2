/*
 * Timer2.h
 *
 * Created: 2/26/2021 3:54:37 PM
 *  Author: Osama Moussa
 */ 


#ifndef TIMER2_H_
#define TIMER2_H_

#include "STD_Types.h"
#include "Timer2_HW.h"
#include "Timer2_Types.h"

#define Timer2_Top    255

Uint8 Timer2_CS_Select(Timer2_CS_Type ClockSource);
void  Timer2_Mode_Select(Timer2_WG_Mode_Type WG_Mode , Timer2_COM_Mode_Type CMO_Mode);
void  Timer2_Init(Timer2_Init_Type* Timer2_Init_Instance);
void  Timer2_NonInv_FPWM_Duty(Float32 Duty);


#endif /* TIMER2_H_ */