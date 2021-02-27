/*
 * DIO.h
 *
 * Created: 2/7/2021 6:59:44 PM
 *  Author: Osama Moussa
 */ 


#ifndef DIO_H_
#define DIO_H_

#include "STD_Types.h"
#include "DIO_HW.h"
#include "DIO_Types.h"

void  DIO_Channel_Mode(DIO_Channel_Type Channel , DIO_Direction_Type Direction);
void  DIO_Channel_Write(DIO_Channel_Type Channel , STD_Level_Type Level);
void  DIO_Channel_Toggle(DIO_Channel_Type Channel);
STD_Level_Type DIO_Channel_Read(DIO_Channel_Type Channel);
void  DIO_Port_Write(DIO_Port_Type Port, Uint8 Data);
Uint8 DIO_Port_Read(DIO_Port_Type Port);

#endif /* DIO_H_ */