/*
 * SPI_Master.c
 *
 * Created: 2/18/2021 1:27:26 AM
 *  Author: Osama Moussa
 */ 
#include "SPI_Master.h"
#include "Delay.h"

void SPI_Master_Init(void)
{
	DIO_Channel_Mode(SPI_Slave_1,Output);
	SPI_Slave_Disable(SPI_Slave_1);
	
	SPI_Init_Type SPI_Init_Master = {SPI_State_Master,SPI_Data_Order_MSB,SPI_Presc_16};		
	SPI_Init(&SPI_Init_Master);
}

void SPI_Master_Send_Data(SPI_Slave_Channel_Type Slave_Channel,Uint8 Data)
{
	SPI_Slave_Enable(Slave_Channel);
	Delay_ms(20);
	SPI_Send_Data(Data);
    SPI_Slave_Disable(Slave_Channel);
	
}

Uint8 SPI_Master_Recieve_Data(SPI_Slave_Channel_Type Slave_Channel)
{
	Uint8 Data =0;
	SPI_Slave_Enable(Slave_Channel);
	Data = SPI_Recieve_Data();
	SPI_Slave_Disable(Slave_Channel);
	return Data ;
}