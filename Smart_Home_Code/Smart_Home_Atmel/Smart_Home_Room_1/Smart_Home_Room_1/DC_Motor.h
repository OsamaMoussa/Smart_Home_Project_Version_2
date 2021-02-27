/*
 * DC_Motor.h
 *
 * Created: 2/14/2021 5:34:28 PM
 *  Author: Osama Moussa
 */ 


#ifndef DC_MOTOR_H_
#define DC_MOTOR_H_

#include "STD_Types.h"
#include "DIO.h"
#include "Timer2.h"

#define DC_Motor_IN1  DIO_Channel_D2
#define DC_Motor_IN2  DIO_Channel_D3
#define DC_Motor_E    DIO_Channel_D7 //E->OC1B

typedef enum{
	DC_Motor_Full_Speed   =100,
	DC_Motor_High_Speed   =75,
	DC_Motor_Medium_Speed =50,
	DC_Motor_Low_Speed    =25
	}DC_Motor_Speed_type;
	
void DC_Motor_Init(void);
void DC_Motor_CW(DC_Motor_Speed_type Speed);
void DC_Motor_ACW(DC_Motor_Speed_type Speed);
void DC_Motor_Stop(void);

#endif /* DC_MOTOR_H_ */