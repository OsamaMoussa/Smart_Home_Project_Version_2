/*
 * Temp_Sensor.c
 *
 * Created: 2/18/2021 5:52:26 PM
 *  Author: Osama Moussa
 */ 

#include "Temp_Sensor.h"
#include <stdlib.h>

void   Temp_Sensor_Init(void)
{
	ADC_Init();
}

Uint16 Temp_Sensor_Read_Value(void)
{
	Uint16 Voltage_Value = 0 ;
	Uint16 Temp_Value    = 0 ;
		
	Voltage_Value = ADC_Channel_Read(Temp_Sensor_Channel);
	Temp_Value    = Voltage_Value/4;
	return Temp_Value;
}

String Temp_Sensor_Read_String(void)
{
		Uint16 Temp_Value = 0;
		static Sint8 Temp_String[3];
		Temp_Value = Temp_Sensor_Read_Value();
		itoa(Temp_Value,Temp_String,10);
		return Temp_String;	
}

