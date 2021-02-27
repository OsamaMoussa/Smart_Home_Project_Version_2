/*
 * ADC_HW.h
 *
 * Created: 2/8/2021 2:16:04 PM
 *  Author: Osama Moussa
 */ 


#ifndef ADC_HW_H_
#define ADC_HW_H_

#include "STD_Types.h"

typedef struct{
	Uint8 ADPS_Bits:3;
	Uint8 ADIE_Bit:1;
	Uint8 ADIF_Bit:1;
	Uint8 ADATE_Bit:1;
	Uint8 ADSC_Bit:1;
	Uint8 ADEN_Bit:1;
    }ADC_ADCSRA_Reg_Bits;

typedef struct{
	Uint8 MUX_Bits:5;
	Uint8 ADLAR_Bit:1;
	Uint8 REFS_Bits:2;     
	}ADC_ADMUX_Reg_Bits;
	
typedef union{
	ADC_ADCSRA_Reg_Bits Bits;
	Uint8               All_Reg;
    }ADC_ADCSRA_Reg;
	
typedef union{
	ADC_ADMUX_Reg_Bits Bits;
	Uint8              All_Reg;
	}ADC_ADMUX_Reg;

typedef struct{
    Uint8           ADCL_Reg;
	Uint8           ADCH_Reg;
	ADC_ADCSRA_Reg  ADCSRA_Reg;
	ADC_ADMUX_Reg  	ADMUX_Reg;
	}ADC_Registers;

#define ADC_1 ((volatile ADC_Registers *) 0x24)
	
#endif /* ADC_HW_H_ */