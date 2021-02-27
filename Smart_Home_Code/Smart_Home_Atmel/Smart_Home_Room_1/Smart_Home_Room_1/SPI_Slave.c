/*
* SPI_Slave.c
*
* Created: 2/18/2021 2:07:10 AM
*  Author: Osama Moussa
*/

#include "SPI_Slave.h"

void SPI_Slave_Init(void)
{
	SPI_Init_Type SPI_Init_Slave= {SPI_State_Slave,SPI_Data_Order_MSB,SPI_Presc_16};
	SPI_Init(&SPI_Init_Slave);
}
void SPI_Slave_Send_Data(Uint8 Data)
{
	while (SPI_IS_Slave_Enabled()==STD_Low);
	SPI_Send_Data(Data);
}
Uint8 SPI_Slave_Recieve_Data(void)

{
	while (SPI_IS_Slave_Enabled()==STD_Low);
	return SPI_Recieve_Data();
}