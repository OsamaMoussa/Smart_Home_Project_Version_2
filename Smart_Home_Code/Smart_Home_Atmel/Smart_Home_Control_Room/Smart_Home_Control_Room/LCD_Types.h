/*
 * LCD_Types.h
 *
 * Created: 2/8/2021 7:08:18 PM
 *  Author: Osama Moussa
 */ 


#ifndef LCD_TYPES_H_
#define LCD_TYPES_H_

typedef enum {
	LCD_RS_Instruction_Reg=0,
	LCD_RS_Data_Reg
	}LCD_RS_Type;

typedef enum {
	LCD_RW_Write_Mode=0,
	LCD_RW_Read_Mode
    }LCD_RW_Type;

typedef enum{
	LCD_Clear_Cmd        = 0b00000001,
	LCD_ReturnHome_Cmd   = 0b00000010,
	LCD_EntryMode_Cmd    = 0b00000110,
	LCD_DisplayOff_Cmd   = 0b00001000,
	LCD_DisplayOn_Cmd    = 0b00001100,
	LCD_FuncSet_Cmd      = 0b00101000,
	LCD_Init1_Cmd        = 0b00110011,
	LCD_Init2_Cmd        = 0b00110010,
	LCD_FirstLineAdr_Cmd = 0x80,
	LCD_SecLineAdr_Cmd   = 0xC0
	}LCD_Command_type;
	
typedef enum{
	LCD_Line_1 = 0,
	LCD_Line_2 
    }LCD_Line_Type;

typedef enum{
	LCD_Position_1 =0,
	LCD_Position_2,
	LCD_Position_3,
	LCD_Position_4,
	LCD_Position_5,
	LCD_Position_6,
	LCD_Position_7,
	LCD_Position_8,
	LCD_Position_9,
	LCD_Position_10,
	LCD_Position_11,
	LCD_Position_12,
	LCD_Position_13,
	LCD_Position_14,
	LCD_Position_15,
	LCD_Position_16
    }LCD_Position_Type;	
	
#endif /* LCD_TYPES_H_ */