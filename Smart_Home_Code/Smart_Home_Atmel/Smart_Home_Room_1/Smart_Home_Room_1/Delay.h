/*
 * Delay.h
 *
 * Created: 2/18/2021 7:49:53 AM
 *  Author: osama yassin
 */ 


#ifndef DELAY_H_
#define DELAY_H_

#include "Timer0.h"

#define F_CPU 16000000UL
#include <avr/interrupt.h>

volatile Uint32 Timer0_OVFs;
volatile Uint32 Timer0_OVF_Count;
volatile Uint8  Timer0_OCR_Flag;

#define Enable_OVF_Interrupt()      (Timer0_TIMSK_Reg->TOIE0_Bit = STD_High)
#define Enable_OCR_Interrupt()      (Timer0_TIMSK_Reg->OCIE0_Bit = STD_High)
#define Enable_General_Interrupt()  sei()

void Delay_Init(void);
void Delay_us(Uint32 Delay_Time_us);
void Delay_ms(Uint32 Delay_Time_ms);

#endif /* DELAY_H_ */