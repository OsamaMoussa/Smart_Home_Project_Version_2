/*
* Smart_Home_Room_1.c
*
* Created: 2/18/2021 7:24:09 AM
* Author : Osama Moussa
*/

#include "Smart_Home_Room.h"

int main(void)
{
	Smart_Home_Room_Init();	
	while (1)
	{
	   Smart_Home_Receive_Cmd_From_Control_Room();
	}
}

