/*
 * Smart_Home_Control_Room.h
 *
 * Created: 2/18/2021 5:36:18 PM
 *  Author: Osama Moussa
 */ 


#ifndef SMART_HOME_CONTROL_ROOM_H_
#define SMART_HOME_CONTROL_ROOM_H_

#include "STD_Types.h"
#include "Delay.h"
#include "LCD.h"
#include "Bluetooth.h"
#include "SPI_Master.h"


#define Smart_Home_Room_1   SPI_Slave_1
#define Room_Light_Is_On    ((Uint16) (0x0066))
#define Room_Light_Is_Off   ((Uint16) (0x0099))
#define Data_Signal         ((Uint8) (0x01))

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

void Smart_Home_Control_Room_Init(void);
void Smart_Home_LCD_Display_1(String Str);
void Smart_Home_LCD_Display_2(String Str);
Uint16 Smart_Home_Receive_Data_From_Room(SPI_Slave_Channel_Type Room_num ,Smart_Home_Confirm_Type Confirmation_Msg);
void Smart_Home_Toggle_Light_Task(void);
void Smart_Home_Measure_Temp_Task(void);
void Smart_Home_SpeedUP_Motor_Task(void);
void Smart_Home_SpeedDown_Motor_Task(void);
void Smart_Home_Stop_Motor_Task(void);
void Smart_Home_Close_Door_Task(void);
void Smart_Home_Open_Door_Task(void);
void Smart_Home_Send_Cmd_To_Room(Smart_Home_Cmd_Type Cmd_From_Device);

#endif /* SMART_HOME_CONTROL_ROOM_H_ */