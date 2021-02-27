/*
 * Timer0_HW.h
 *
 * Created: 2/10/2021 8:12:35 PM
 *  Author: Osama Moussa
 */ 


#ifndef TIMER0_HW_H_
#define TIMER0_HW_H_

typedef struct{
	Uint8 CS0_Bits:3;
	Uint8 WGM01_Bit:1;
	Uint8 COM0_Bits:2;
	Uint8 WGM00_Bit:1;
	Uint8 FOC0_Bit:1;
	}Timer0_TCCR0_Reg_Bits;

typedef struct{
	Uint8 TOIE0_Bit:1;
	Uint8 OCIE0_Bit:1;
	Uint8 TOIE1_Bit:1;
	Uint8 OCIE1B_Bit:1;
	Uint8 OCIE1A_Bit:1;
	Uint8 TICIE1_Bit:1;
	Uint8 TOIE2_Bit:1;
	Uint8 OCIE2_Bit:1;
    }Timer0_TIMSK_Reg_Bits;

typedef struct{
	Uint8 TOV0_Bit:1;
	Uint8 OCF0_Bit:1;
	Uint8 TOV1_Bit:1;
	Uint8 OCF1B_Bit:1;
	Uint8 OCF1A_Bit:1;
	Uint8 ICF1_Bit:1;
	Uint8 TOV2_Bit:1;
	Uint8 OCF2_Bit:1;
    }Timer0_TIFR_Reg_Bits;


#define Timer0_TCCR0_Reg  ( (volatile Timer0_TCCR0_Reg_Bits *) 0x53 )
#define Timer0_TIMSK_Reg  ( (volatile Timer0_TIMSK_Reg_Bits *) 0x59 )
#define Timer0_TIFR_Reg   ( (volatile Timer0_TIFR_Reg_Bits  *) 0x58 )
#define Timer0_TCNT0_Reg  (*( (volatile Uint8 *) 0x52 ))
#define Timer0_OCR0_Reg   (*( (volatile Uint8 *) 0x5C ))
		
#endif /* TIMER0_HW_H_ */