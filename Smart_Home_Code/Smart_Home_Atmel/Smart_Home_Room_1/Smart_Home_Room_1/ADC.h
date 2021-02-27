/*
 * ADC.h
 *
 * Created: 2/8/2021 2:40:12 PM
 *  Author: Osama Moussa
 */ 


#ifndef ADC_H_
#define ADC_H_

#include "STD_Types.h"
#include "ADC_HW.h"
#include "ADC_Types.h"

#define ADC_Voltage_Refrence_Bits 0b11   //Prescaler -> 64
#define ADC_Prescaler_Select_Bits 0b111  //Reference Voltage -> internal (2.56V)

void ADC_Init(void);
Uint16 ADC_Channel_Read(ADC_Channel_Type Channel); 

#endif /* ADC_H_ */