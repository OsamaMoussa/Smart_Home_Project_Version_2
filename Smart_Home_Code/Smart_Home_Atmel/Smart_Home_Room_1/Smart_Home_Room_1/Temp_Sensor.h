/*
 * Temp_Sensor.h
 *
 * Created: 2/18/2021 5:52:07 PM
 *  Author: Osama Moussa
 */ 


#ifndef TEMP_SENSOR_H_
#define TEMP_SENSOR_H_

#include "ADC.h"

#define Temp_Sensor_Channel  ADC_Channel_ADC0

void   Temp_Sensor_Init(void);
Uint16 Temp_Sensor_Read_Value(void);
String Temp_Sensor_Read_String(void);
#endif /* TEMP_SENSOR_H_ */