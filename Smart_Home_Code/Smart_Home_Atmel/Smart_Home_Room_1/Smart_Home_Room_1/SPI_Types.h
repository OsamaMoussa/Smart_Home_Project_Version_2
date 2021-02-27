/*
* SPI_Types.h
*
* Created: 2/17/2021 11:46:38 PM
*  Author: Osama Moussa
*/


#ifndef SPI_TYPES_H_
#define SPI_TYPES_H_

typedef enum {
	SPI_State_Slave=0,
	SPI_State_Master
    }SPI_State_Type;

typedef enum {
	SPI_Data_Order_MSB=0,
	SPI_Data_Order_LSB
    }SPI_Data_Order_Type;

typedef enum{
	SPI_Presc_4   = 0b00,
	SPI_Presc_16  = 0b01,
	SPI_Presc_64  = 0b10,
	SPI_Presc_128 = 0b11
	}SPI_Presc_Type;	

typedef struct  {
	SPI_State_Type      SPI_State;
	SPI_Data_Order_Type SPI_Data_Order;
    SPI_Presc_Type      SPI_Presc;
    }SPI_Init_Type;

#endif /* SPI_TYPES_H_ */