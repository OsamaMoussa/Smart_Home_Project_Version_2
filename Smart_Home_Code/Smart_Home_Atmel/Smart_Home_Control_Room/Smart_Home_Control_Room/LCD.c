/*
* LCD.c
*
* Created: 2/8/2021 6:40:19 PM
*  Author: Osama Moussa
*/
#include "LCD.h"
#include "Delay.h"

void LCD_Init(void)
{   //Pins Configuration:
	DIO_Channel_Mode(LCD_D4 , Output);
	DIO_Channel_Mode(LCD_D5 , Output);
	DIO_Channel_Mode(LCD_D6 , Output);
	DIO_Channel_Mode(LCD_D7 , Output);
	DIO_Channel_Mode(LCD_RS , Output);
	DIO_Channel_Mode(LCD_RW , Output);
	DIO_Channel_Mode(LCD_E  , Output);
	//LCD Initialization:
	DIO_Channel_Write(LCD_RW , LCD_RW_Write_Mode);
	DIO_Channel_Write(LCD_E  , STD_High);
	Delay_ms(20);
	LCD_Command(LCD_Init1_Cmd);
	Delay_us(100);
	LCD_Command(LCD_Init2_Cmd);
	LCD_Command(LCD_FuncSet_Cmd);
	LCD_Command(LCD_DisplayOff_Cmd);
	LCD_Command(LCD_EntryMode_Cmd);
	LCD_Command(LCD_Clear_Cmd);
	LCD_Command(LCD_DisplayOn_Cmd);
	Delay_ms(2);
}

void LCD_Send_Data(Uint8 Data)
{
	Uint8 PortA_Data = 0;
	Uint8 High_Bits  = 0;
	Uint8 Low_Bits   = 0;
	//Send High Order Bits:
	PortA_Data = DIO_Port_Read(DIO_PortA);
	High_Bits  = (PortA_Data & 0x0F)|(Data & 0xF0);
	DIO_Port_Write(DIO_PortA , High_Bits);
	//
	DIO_Channel_Write(LCD_E , STD_Low);
	Delay_ms(2);
	DIO_Channel_Write(LCD_E , STD_High);
	Delay_ms(2);
	//
	//Send Low Order Bits:
	PortA_Data = DIO_Port_Read(DIO_PortA);
	Low_Bits  = (PortA_Data & 0x0F) | (Data << (STD_Reg_Bits_Number/2) );
	DIO_Port_Write(DIO_PortA , Low_Bits);
	//
	DIO_Channel_Write(LCD_E , STD_Low);
	Delay_ms(2);
	DIO_Channel_Write(LCD_E , STD_High);
	Delay_ms(2);
	//
}

void LCD_Command(LCD_Command_type Cmd)
{
	DIO_Channel_Write(LCD_RS , LCD_RS_Instruction_Reg);
	DIO_Channel_Write(LCD_RW , LCD_RW_Write_Mode);
	LCD_Send_Data(Cmd);
}

void LCD_Write_Char(Uint8 Char)
{
	DIO_Channel_Write(LCD_RS , LCD_RS_Data_Reg);
	DIO_Channel_Write(LCD_RW , LCD_RW_Write_Mode);
	LCD_Send_Data(Char);
}

void LCD_Write_Char_xy(Uint8 Char , LCD_Line_Type Line , LCD_Position_Type Position)
{
	Uint8 First_Char_Adr[] = {LCD_FirstLineAdr_Cmd , LCD_SecLineAdr_Cmd};
	LCD_Command(First_Char_Adr[Line] + Position);
	LCD_Write_Char(Char);
}

void LCD_Write_String(String Str)
{
	Uint8 i = 0;
	for(i=0 ;Str[i] != '\0';i++)
	{
		LCD_Write_Char(Str[i]);
	}
}

void LCD_Write_String_xy(String Str , LCD_Line_Type Line ,  LCD_Position_Type Position)
{
	Uint8 First_Char_Adr[] = { LCD_FirstLineAdr_Cmd , LCD_SecLineAdr_Cmd };
	LCD_Command(First_Char_Adr[Line] + Position);
	LCD_Write_String(Str);
}

void LCD_Clear(void)
{
	LCD_Command(LCD_Clear_Cmd);
}
