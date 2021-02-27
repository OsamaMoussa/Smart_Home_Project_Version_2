/*
 * STD_Types.h
 *
 * Created: 2/7/2021 5:34:45 PM
 *  Author: Osama Moussa
 */ 


#ifndef STD_TYPES_H_
#define STD_TYPES_H_

typedef unsigned char  Uint8;
typedef char           Sint8;
typedef unsigned short Uint16;
typedef short          Sint16;
typedef unsigned long  Uint32;
typedef long           Sint32;
typedef float          Float32;
typedef Sint8*         String;     

typedef enum{
	STD_Low=0,
	STD_High
    }STD_Level_Type;
	
#define STD_Reg_Bits_Number 8

#endif /* STD_TYPES_H_ */