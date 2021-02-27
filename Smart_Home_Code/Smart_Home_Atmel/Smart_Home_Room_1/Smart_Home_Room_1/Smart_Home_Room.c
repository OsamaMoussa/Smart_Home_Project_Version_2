/*
* Smart_Home_Room.c
*
* Created: 2/18/2021 5:28:13 PM
*  Author: Osama Moussa
*/

#include "Smart_Home_Room.h"

void Smart_Home_Room_Init(void)
{
	Delay_Init();
	SPI_Slave_Init();
	Led_Init();
	LCD_Init();
	DC_Motor_Init();
	Servo_Motor_Init();
	Temp_Sensor_Init();
}

void Smart_Home_LCD_Display(String Str1 , String Str2)
{
	LCD_Clear();
	LCD_Write_String(Str1);
	LCD_Write_String(Str2);
}

void Smart_Home_Send_Data_To_Control_Room(Smart_Home_Confirm_Type Confirm_msg , Uint16 Data)
{
	SPI_Slave_Send_Data(Confirm_msg);
	while (SPI_Slave_Recieve_Data() != Data_Signal);
	SPI_Slave_Send_Data((Uint8)(Data));
	while (SPI_Slave_Recieve_Data() != Data_Signal);
	SPI_Slave_Send_Data((Uint8)(Data>>STD_Reg_Bits_Number));
}

void Smart_Home_Toggle_Light_Task(Uint8* Toggle_Count)
{
	Uint16 Light_State = 0;
	String Light_State_str;
	Led_Toggle();
	*Toggle_Count+=1;
	if (*Toggle_Count==2)
	{
		Light_State = Room_Light_Is_Off;
		Light_State_str="OFF";
		*Toggle_Count=0;
	}
	else
	{
		Light_State = Room_Light_Is_On;
		Light_State_str="On";
	}
	Smart_Home_LCD_Display("Light: " , Light_State_str);
	Smart_Home_Send_Data_To_Control_Room(Smart_Home_Toggle_Light_Confirm , Light_State);
}

void Smart_Home_Measure_Temp_Task()
{
	String Temp_Value_String;
	Temp_Value_String = Temp_Sensor_Read_String();
	Smart_Home_LCD_Display("Temperature: " , Temp_Value_String);
	Smart_Home_Send_Data_To_Control_Room(Smart_Home_Measure_Temp_Confirm ,Temp_Sensor_Read_Value());
}

void Smart_Home_SpeedUP_Motor_Task()
{
	DC_Motor_CW(DC_Motor_High_Speed);
	Smart_Home_LCD_Display("Fan: " ,"Speed Up");
	Smart_Home_Send_Data_To_Control_Room(Smart_Home_SpeedUP_Motor_Confirm , DC_Motor_High_Speed);
}

void Smart_Home_SpeedDown_Motor_Task()
{
	DC_Motor_CW(DC_Motor_Low_Speed);
	Smart_Home_LCD_Display("Fan: " ,"Speed Down");
	Smart_Home_Send_Data_To_Control_Room(Smart_Home_SpeedDown_Motor_Confirm , DC_Motor_Low_Speed);
}

void Smart_Home_Stop_Motor_Task()
{
	DC_Motor_Stop();
	Smart_Home_LCD_Display("Fan: " ,"Stopped");
	Smart_Home_Send_Data_To_Control_Room(Smart_Home_Stop_Motor_Confirm , 0x0000);
}

void Smart_Home_Close_Door_Task()
{
	Servo_Motor_Angle(Door_Close_Angle);
	Smart_Home_LCD_Display("Door: " ,"Closed");
	Smart_Home_Send_Data_To_Control_Room(Smart_Home_Close_Door_Confirm, (Uint16)Door_Close_Angle);
}

void Smart_Home_Open_Door_Task()
{
	Servo_Motor_Angle(Door_Open_Angle);
	Smart_Home_LCD_Display("Door: " ,"Opened");
	Smart_Home_Send_Data_To_Control_Room(Smart_Home_Open_Door_Confirm, (Uint16)Door_Open_Angle);
}

void Smart_Home_Receive_Cmd_From_Control_Room(void)
{
    Smart_Home_Cmd_Type Cmd_From_Control_Room;
	static Uint8 Toggle_Count =0 ;
	Cmd_From_Control_Room = SPI_Slave_Recieve_Data(); 
	switch(Cmd_From_Control_Room)
	{
		case Smart_Home_Toggle_Light_Cmd:
		Smart_Home_Toggle_Light_Task(&Toggle_Count);
		break;
		
		case Smart_Home_Measure_Temp_Cmd:
		Smart_Home_Measure_Temp_Task();
		break;
		
		case Smart_Home_SpeedUP_Motor_Cmd:
		Smart_Home_SpeedUP_Motor_Task();
		break;
		
		case Smart_Home_SpeedDown_Motor_Cmd:
		Smart_Home_SpeedDown_Motor_Task();
		break;
		
		case Smart_Home_Stop_Motor_Cmd:
		Smart_Home_Stop_Motor_Task();
		break;
		
		case Smart_Home_Close_Door_Cmd:
		Smart_Home_Close_Door_Task();
		break;
		
		case Smart_Home_Open_Door_Cmd:
		Smart_Home_Open_Door_Task();
		break;
	}
}
