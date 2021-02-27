/*
* Smart_Home_Control_Room.c
*
* Created: 2/18/2021 7:23:20 AM
* Author : Osama Moussa
*/

#include "Smart_Home_Control_Room.h"

int main(void)
{
	Smart_Home_Control_Room_Init();
	Smart_Home_Cmd_Type Cmd_From_Device;
	while (1)
	{
		Cmd_From_Device = (Uint8)Blutooth_Receive_From_Device_Char();
		Smart_Home_Send_Cmd_To_Room(Cmd_From_Device);
	}
}
