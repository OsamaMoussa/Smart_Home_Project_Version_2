/*
 * ADC_Types.h
 *
 * Created: 2/8/2021 2:52:46 PM
 *  Author: Osama Moussa
 */ 


#ifndef ADC_TYPES_H_
#define ADC_TYPES_H_

typedef enum{
	ADC_Channel_ADC0=0b00000,
	ADC_Channel_ADC1=0b00001,
	ADC_Channel_ADC2=0b00010,
	ADC_Channel_ADC3=0b00011,
	ADC_Channel_ADC4=0b00100,
	ADC_Channel_ADC5=0b00101,
	ADC_Channel_ADC6=0b00110,
	ADC_Channel_ADC7=0b00111
	}ADC_Channel_Type;
	
#endif /* ADC_TYPES_H_ */