/*
 * Timer2_HW.h
 *
 * Created: 2/26/2021 3:53:59 PM
 *  Author: Osama Moussa
 */ 


#ifndef TIMER2_HW_H_
#define TIMER2_HW_H_
typedef struct{
	Uint8 CS2_Bits:3;
	Uint8 WGM21_Bit:1;
	Uint8 COM2_Bits:2;
	Uint8 WGM20_Bit:1;
	Uint8 FOC2_Bit:1;
    }Timer2_TCCR2_Reg_Bits;

typedef struct{
	Uint8 TCR2UB_Bit:1;
	Uint8 OCR2UB_Bit:1;
	Uint8 TCN2UB_Bit:1;
	Uint8 AS2_Bit:1;
	Uint8 Reserved_Bits:4;
    }Timer2_ASSR_Reg_Bits;

typedef struct{
	Uint8 TOIE0_Bit:1;
	Uint8 OCIE0_Bit:1;
	Uint8 TOIE1_Bit:1;
	Uint8 OCIE1B_Bit:1;
	Uint8 OCIE1A_Bit:1;
	Uint8 TICIE1_Bit:1;
	Uint8 TOIE2_Bit:1;
	Uint8 OCIE2_Bit:1;
    }Timer2_TIMSK_Reg_Bits;

typedef struct{
	Uint8 TOV0_Bit:1;
	Uint8 OCF0_Bit:1;
	Uint8 TOV1_Bit:1;
	Uint8 OCF1B_Bit:1;
	Uint8 OCF1A_Bit:1;
	Uint8 ICF1_Bit:1;
	Uint8 TOV2_Bit:1;
	Uint8 OCF2_Bit:1;
    }Timer2_TIFR_Reg_Bits;


#define Timer2_TCCR2_Reg  ( (volatile Timer2_TCCR2_Reg_Bits *) 0x45 )
#define Timer2_ASSR_Reg   ( (volatile Timer2_ASSR_Reg_Bits *) 0x42 )
#define Timer2_TIMSK_Reg  ( (volatile Timer0_TIMSK_Reg_Bits *) 0x59 )
#define Timer2_TIFR_Reg   ( (volatile Timer0_TIFR_Reg_Bits  *) 0x58 )
#define Timer2_TCNT2_Reg  (*( (volatile Uint8 *) 0x44 ))
#define Timer2_OCR2_Reg   (*( (volatile Uint8 *) 0x43 ))

#endif /* TIMER2_HW_H_ */