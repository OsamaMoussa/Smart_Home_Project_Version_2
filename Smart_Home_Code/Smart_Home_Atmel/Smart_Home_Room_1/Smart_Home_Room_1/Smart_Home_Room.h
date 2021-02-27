/*
 * Smart_Home_Room.h
 *
 * Created: 2/18/2021 5:27:49 PM
 *  Author: Osama Moussa
 */ 


#ifndef SMART_HOME_ROOM_H_
#define SMART_HOME_ROOM_H_

#include "STD_Types.h"
#include "Delay.h"
#include "Led.h"
#include "LCD.h"
#include "SPI_Slave.h"
#include "DC_Motor.h"
#include "Servo_Motor.h"
#include "Temp_Sensor.h"

#define Room_Light_Is_On    ((Uint16) (0x0066))
#define Room_Light_Is_Off   ((Uint16) (0x0099))
#define Data_Signal         ((Uint8) (0x01))
#define Door_Close_Angle    0.0
#define Door_Open_Angle     90.0

typedef enum{
	Smart_Home_Toggle_Light_Cmd    ='0',
	Smart_Home_Measure_Temp_Cmd    ='1',
	Smart_Home_SpeedUP_Motor_Cmd   ='2',
	Smart_Home_SpeedDown_Motor_Cmd ='3',
	Smart_Home_Stop_Motor_Cmd      ='4',
	Smart_Home_Close_Door_Cmd      ='5',
	Smart_Home_Open_Door_Cmd       ='6'
    }Smart_Home_Cmd_Type;

typedef enum{
	Smart_Home_Toggle_Light_Confirm    = 0x09,
	Smart_Home_Measure_Temp_Confirm    = 0xAA,
	Smart_Home_SpeedUP_Motor_Confirm   = 0x65,
	Smart_Home_SpeedDown_Motor_Confirm = 0x44,
	Smart_Home_Stop_Motor_Confirm      = 0x99,
	Smart_Home_Close_Door_Confirm      = 0x77,
	Smart_Home_Open_Door_Confirm       = 0x88
    }Smart_Home_Confirm_Type;

void Smart_Home_Room_Init(void);
void Smart_Home_LCD_Display(String Str1 , String Str2);
void Smart_Home_Send_Data_To_Control_Room(Smart_Home_Confirm_Type Confirm_msg , Uint16 Data);
void Smart_Home_Toggle_Light_Task(Uint8* Toggle_Count_Ptr);
void Smart_Home_Measure_Temp_Task(void);
void Smart_Home_SpeedUP_Motor_Task(void);
void Smart_Home_SpeedDown_Motor_Task(void);
void Smart_Home_Stop_Motor_Task(void);
void Smart_Home_Close_Door_Task(void);
void Smart_Home_Open_Door_Task(void);
void Smart_Home_Receive_Cmd_From_Control_Room(void);

#endif /* SMART_HOME_ROOM_H_ */