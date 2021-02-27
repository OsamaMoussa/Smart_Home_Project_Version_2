/*
 * ADC.c
 *
 * Created: 2/8/2021 2:40:25 PM
 *  Author: Osama Moussa
 */ 

#include "ADC.h"

void ADC_Init(void)
{
	//ADC Enable:
	ADC_1->ADCSRA_Reg.Bits.ADEN_Bit = STD_High;
	//ADC Frequency Prescaler -> 64:
	ADC_1->ADCSRA_Reg.Bits.ADPS_Bits = ADC_Prescaler_Select_Bits;
	//ADC Reference Voltage -> internal (2.56V):
	ADC_1->ADMUX_Reg.Bits.REFS_Bits = ADC_Voltage_Refrence_Bits;
}

Uint16 ADC_Channel_Read(ADC_Channel_Type Channel)
{
	Uint16 Data = 0;

	//ADC Analog Channel Choice:
	ADC_1->ADMUX_Reg.Bits.MUX_Bits  =  Channel;
	//Clear ADC interrupt flag: 
	ADC_1->ADCSRA_Reg.Bits.ADIF_Bit = STD_Low;
	//ADC Start Conversion:
	ADC_1->ADCSRA_Reg.Bits.ADSC_Bit=STD_High;
	//Wait for ADC interrupt flag:
	while (ADC_1->ADCSRA_Reg.Bits.ADIF_Bit==STD_Low);
	//ADC Read Data
	Data |= (ADC_1->ADCL_Reg | (ADC_1->ADCH_Reg << STD_Reg_Bits_Number) );
	return Data;
}