/*
 * LCD.h
 *
 * Created: 2/8/2021 6:40:31 PM
 *  Author: Osama Moussa
 */ 


#ifndef LCD_H_
#define LCD_H_

#include "STD_Types.h"
#include "DIO.h"
#include "LCD_Types.h"

#define LCD_D4 DIO_Channel_A4
#define LCD_D5 DIO_Channel_A5
#define LCD_D6 DIO_Channel_A6
#define LCD_D7 DIO_Channel_A7
#define LCD_RS DIO_Channel_B1
#define LCD_RW DIO_Channel_B2
#define LCD_E  DIO_Channel_B3

void LCD_Init(void);
void LCD_Send_Data(Uint8 Data);
void LCD_Command(Uint8 Cmd);
void LCD_Write_Char(Uint8 Char);
void LCD_Write_Char_xy(Uint8 Char , LCD_Line_Type Line , LCD_Position_Type Position);
void LCD_Write_String(String Str);
void LCD_Write_String_xy(String Str ,LCD_Line_Type Line ,  LCD_Position_Type Position);
void LCD_Clear(void);

#endif /* LCD_H_ */