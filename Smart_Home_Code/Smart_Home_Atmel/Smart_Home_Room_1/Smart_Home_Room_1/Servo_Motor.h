/*
 * Servo_Motor.h
 *
 * Created: 2/15/2021 8:05:36 PM
 *  Author: Osama Moussa
 */ 


#ifndef SERVO_MOTOR_H_
#define SERVO_MOTOR_H_

#include "DIO.h"
#include "Timer1.h"

#define  Servo_Motor_Channel  DIO_Channel_D5
#define  Servo_Motor_COM      Timer1_COM_A

#define  F_W                50.0  //Hz
#define  Angle_min          0.0   //degree
#define  Angle_max          180.0 //degree
#define  T_Duty_min         0.001 //sec
#define  T_Duty_max         0.002 //sec
 
void Servo_Motor_Init(void);
void Servo_Motor_Angle(Float32 Angle);

#endif /* SERVO_MOTOR_H_ */