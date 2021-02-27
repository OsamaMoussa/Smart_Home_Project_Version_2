/*
* Smart_Home_Control_Room.c
*
* Created: 2/18/2021 5:36:52 PM
*  Author: Osama Moussa
*/
#include "Smart_Home_Control_Room.h"
#include <stdlib.h>

void Smart_Home_Control_Room_Init()
{
	Delay_Init();
	SPI_Master_Init();
	Bluetooth_Init();
	LCD_Init();
}

void Smart_Home_LCD_Display_1(String Str)
{
	LCD_Clear();
	LCD_Write_String(Str);
}

void Smart_Home_LCD_Display_2(String Str)
{
	LCD_Write_String_xy(Str,LCD_Line_2, LCD_Position_1);
}

Uint16 Smart_Home_Receive_Data_From_Room(SPI_Slave_Channel_Type Room_num ,Smart_Home_Confirm_Type Confirmation_Msg)
{
	Uint8 Msg_From_Room=0xFF;
	Uint16 Data=0xFFFF;

	while ( Msg_From_Room != Confirmation_Msg)
	{
		SPI_Master_Send_Data(Room_num,0x01);
		Msg_From_Room = SPI_Master_Recieve_Data(Room_num);
		if (Msg_From_Room == Confirmation_Msg)
		{
			SPI_Master_Send_Data(Room_num,Data_Signal);
			Data = SPI_Master_Recieve_Data(Room_num);
			
			SPI_Master_Send_Data(Room_num,Data_Signal);
			Data|= (SPI_Master_Recieve_Data(Room_num)<<STD_Reg_Bits_Number);
			return Data;
		}
	}
	return Data;
}

void Smart_Home_Toggle_Light_Task()
{
	Uint16 Data=0;
	
	Smart_Home_LCD_Display_1("R1_Toggle_Light: ");
	
	Delay_ms(100);
	
	Data = Smart_Home_Receive_Data_From_Room(Smart_Home_Room_1 ,Smart_Home_Toggle_Light_Confirm);
	if (Data == (Uint16)Room_Light_Is_On)
	{
		Smart_Home_LCD_Display_2("Light Is ON");
	}
	else if (Data == (Uint16)Room_Light_Is_Off)
	{
		Smart_Home_LCD_Display_2("Light Is OFF");
	}
}

void Smart_Home_Measure_Temp_Task()
{
	Uint16 Temp_Value=0;
	Sint8  Temp_Value_String[3];
	
	Smart_Home_LCD_Display_1("R1_Temperature: ");
	
	Delay_ms(100);
	
	Temp_Value = Smart_Home_Receive_Data_From_Room(Smart_Home_Room_1 , Smart_Home_Measure_Temp_Confirm);
	itoa(Temp_Value,Temp_Value_String,10);
	LCD_Write_String(Temp_Value_String);
	Smart_Home_LCD_Display_2(Temp_Value_String);
}

void Smart_Home_SpeedUP_Motor_Task()
{
	Uint16 Duty_Value=0;
	Sint8  Duty_Value_String[3];
	
	Smart_Home_LCD_Display_1("R1_Fan_SpeedUP: ");
	
	Delay_ms(100);
	
	Duty_Value = Smart_Home_Receive_Data_From_Room(Smart_Home_Room_1 , Smart_Home_SpeedUP_Motor_Confirm);
	itoa(Duty_Value,Duty_Value_String,10);
	Smart_Home_LCD_Display_2("Duty_Cycle= ");
	LCD_Write_String(Duty_Value_String);
	LCD_Write_String("%");
}

void Smart_Home_SpeedDown_Motor_Task()
{
	Uint16 Duty_Value=0;
	Sint8  Duty_Value_String[3];
	
	Smart_Home_LCD_Display_1("R1_Fan_SpeedDown: ");
	
	Delay_ms(100);
	
	Duty_Value = Smart_Home_Receive_Data_From_Room(Smart_Home_Room_1 , Smart_Home_SpeedDown_Motor_Confirm);
	itoa(Duty_Value,Duty_Value_String,10);
	Smart_Home_LCD_Display_2("Duty_Cycle= ");
	LCD_Write_String(Duty_Value_String);
	LCD_Write_String("%");
}

void Smart_Home_Stop_Motor_Task()
{
	Uint16 Duty_Value=0;
	Sint8  Duty_Value_String[3];
	
	Smart_Home_LCD_Display_1("R1_Fan_Stop: ");
	
	Delay_ms(100);
	Duty_Value = Smart_Home_Receive_Data_From_Room(Smart_Home_Room_1 , Smart_Home_Stop_Motor_Confirm);
	itoa(Duty_Value,Duty_Value_String,10);
	Smart_Home_LCD_Display_2("Duty_Cycle= ");
	LCD_Write_String(Duty_Value_String);
	LCD_Write_String("%");
}

void Smart_Home_Close_Door_Task()
{
	Uint16 Angle_Value=0;
	Sint8  Angle_Value_String[3];
	
	Smart_Home_LCD_Display_1("R1_Door_Close: ");
	
	Delay_ms(100);
	Angle_Value = Smart_Home_Receive_Data_From_Room(Smart_Home_Room_1 , Smart_Home_Close_Door_Confirm);
	itoa(Angle_Value,Angle_Value_String,10);
	Smart_Home_LCD_Display_2("Servo_Angle= ");
	LCD_Write_String(Angle_Value_String);
	LCD_Write_String("d");
}

void Smart_Home_Open_Door_Task()
{
	Uint16 Angle_Value=0;
	Sint8  Angle_Value_String[3];
	
	Smart_Home_LCD_Display_1("R1_Door_Open: ");
	
	Delay_ms(100);
	Angle_Value = Smart_Home_Receive_Data_From_Room(Smart_Home_Room_1 , Smart_Home_Open_Door_Confirm);
	itoa(Angle_Value,Angle_Value_String,10);
	Smart_Home_LCD_Display_2("Servo_Angle= ");
	LCD_Write_String(Angle_Value_String);
	LCD_Write_String("d");
}

void  Smart_Home_Send_Cmd_To_Room(Smart_Home_Cmd_Type Cmd_From_Device)
{
	if ((Cmd_From_Device == Smart_Home_Toggle_Light_Cmd)|
	(Cmd_From_Device == Smart_Home_Measure_Temp_Cmd)|
	(Cmd_From_Device == Smart_Home_SpeedUP_Motor_Cmd)|
	(Cmd_From_Device == Smart_Home_SpeedDown_Motor_Cmd)|
	(Cmd_From_Device ==Smart_Home_Stop_Motor_Cmd)|
	(Cmd_From_Device == Smart_Home_Close_Door_Cmd)|
	(Cmd_From_Device == Smart_Home_Open_Door_Cmd))
	{
		SPI_Master_Send_Data(Smart_Home_Room_1,Cmd_From_Device);
		switch(Cmd_From_Device)
		{
			case Smart_Home_Toggle_Light_Cmd:
			Smart_Home_Toggle_Light_Task();
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
	else
	{
		return;
	}
}

