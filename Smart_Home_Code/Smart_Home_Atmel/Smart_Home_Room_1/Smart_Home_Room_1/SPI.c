/*
* SPI.c
*
* Created: 2/17/2021 11:50:44 PM
*  Author: Osama Moussa
*/

#include "SPI.h"

void  SPI_Init(SPI_Init_Type * SPI_Init_Instace)
{
	SPI_State_Select(SPI_Init_Instace->SPI_State);
	SPI_Data_Order_Select(SPI_Init_Instace->SPI_Data_Order);
	SPI_Presc_Select(SPI_Init_Instace->SPI_Presc);
	switch(SPI_Init_Instace->SPI_State)
	{
		case SPI_State_Master:
		DIO_Channel_Mode(SS,Output);
		DIO_Channel_Mode(MOSI,Output);
		DIO_Channel_Mode(MISO,Input);
		DIO_Channel_Mode(SCK,Output);
		SPI_Enable();
		break;
		
		case SPI_State_Slave:
		DIO_Channel_Mode(SS,Input);
		DIO_Channel_Write(SS,STD_High);
		DIO_Channel_Mode(MOSI,Input);
		DIO_Channel_Mode(MISO,Output);
		DIO_Channel_Mode(SCK,Input);
		SPI_Enable();
		break;
	}
	
}

void  SPI_Send_Data(Uint8 Data)
{
	SPI_Data_Reg = Data;
	while(SPI_IS_Transfer_Complete()==STD_Low);
}

Uint8 SPI_Recieve_Data(void)
{
	while(SPI_IS_Transfer_Complete()==STD_Low);
	return SPI_Data_Reg;
}

Uint8 SPI_TxRx(Uint8 Data)
{
	SPI_Data_Reg = Data;
	while(SPI_IS_Transfer_Complete()==STD_Low);
	return SPI_Data_Reg;
}