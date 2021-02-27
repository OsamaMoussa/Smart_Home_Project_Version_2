/*
 * Timer1_HW.h
 *
 * Created: 2/11/2021 4:47:51 PM
 *  Author: Osama Moussa
 */ 


#ifndef TIMER1_HW_H_
#define TIMER1_HW_H_

#include "STD_Types.h"

typedef struct{
	Uint8 WGM10_Bit:1;
	Uint8 WGM11_Bit:1;
	Uint8 FOC1_Bits:2;
	Uint8 COM1B_Bits:2;
	Uint8 COM1A_Bits:2;
    }Timer1_TCCR1A_Reg_Bits;
	
typedef struct{
	Uint8 CS1_Bits:3;
	Uint8 WGM12_Bit:1;
	Uint8 WGM13_Bit:1;
    Uint8 DC_Bit:1;
	Uint8 ICES1_Bit:1;
	Uint8 ICNC1_Bit:1;
    }Timer1_TCCR1B_Reg_Bits;
	
typedef struct{
	Uint8 TOIE0_Bit:1;
	Uint8 OCIE0_Bit:1;
	Uint8 TOIE1_Bit:1;
	Uint8 OCIE1B_Bit:1;
	Uint8 OCIE1A_Bit:1;
	Uint8 TICIE1_Bit:1;
	Uint8 TOIE2_Bit:1;
	Uint8 OCIE2_Bit:1;
    }Timer1_TIMSK_Reg_Bits;

typedef struct{
	Uint8 TOV0_Bit:1;
	Uint8 OCF0_Bit:1;
	Uint8 TOV1_Bit:1;
	Uint8 OCF1B_Bit:1;
	Uint8 OCF1A_Bit:1;
	Uint8 ICF1_Bit:1;
	Uint8 TOV2_Bit:1;
	Uint8 OCF2_Bit:1;
    }Timer1_TIFR_Reg_Bits;


#define Timer1_TCCR1A_Reg  ( (volatile Timer1_TCCR1A_Reg_Bits *) 0x4F)
#define Timer1_TCCR1B_Reg  ( (volatile Timer1_TCCR1B_Reg_Bits *) 0x4E)

#define Timer1_TIMSK_Reg   ( (volatile Timer1_TIMSK_Reg_Bits *) 0x59)
#define Timer1_TIFR_Reg    ( (volatile Timer1_TIFR_Reg_Bits  *) 0x58)

#define Timer1_TCNT1_Reg  (*( (volatile Uint16 *) 0x4C ))

#define Timer1_OCR1A_Reg  (*( (volatile Uint16 *) 0x4A ))

#define Timer1_OCR1B_Reg  (*( (volatile Uint16 *) 0x48 ))

#define Timer1_ICR1_Reg   (*( (volatile Uint16 *) 0x46 ))

#endif /* TIMER1_HW_H_ */