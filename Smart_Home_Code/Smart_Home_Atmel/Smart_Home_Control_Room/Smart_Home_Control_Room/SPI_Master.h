/*
 * SPI_Master.h
 *
 * Created: 2/18/2021 1:27:09 AM
 *  Author: Osama Moussa
 */ 


#ifndef SPI_MASTER_H_
#define SPI_MASTER_H_

#include "SPI.h"

typedef enum{
	SPI_Slave_1=SS,
	}SPI_Slave_Channel_Type;

#define SPI_Slave_Enable(SlaveChannel)  (DIO_Channel_Write(SlaveChannel,STD_Low))
#define SPI_Slave_Disable(SlaveChannel) (DIO_Channel_Write(SlaveChannel,STD_High))

void SPI_Master_Init(void);
void SPI_Master_Send_Data(SPI_Slave_Channel_Type Slave_Channel,Uint8 Data);
Uint8 SPI_Master_Recieve_Data(SPI_Slave_Channel_Type Slave_Channel);

#endif /* SPI_MASTER_H_ */