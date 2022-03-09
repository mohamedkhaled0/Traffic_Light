/*
 * RTOS_Program.c
 *
 *  Created on: Mar 7, 2022
 *      Author: gerges
 */

#include"../LIB/LSTD_TYPES.h"
#include"../MCAL/TIMER/TIMER_Interface.h"
#include"../MCAL/MGIE/MGIE_Interface.h"
#include"RTOS_Private.h"
#include"RTOS_Config.h"
#include"RTOS_Interface.h"

Task_t SysTasks[MAX_TASK]={{NULL}};
/*RTOS Init*/
void RTOS_VidInit(void)
{
	u32 Loc_u32TickTime_Ns;
	u32 Loc_u32CTCValue;
	/*Set Timer CallBack*/
	TIMER0_VidCTC_SetCallBack(RTOS_VidScheduler);
	/*Calculate and Set System Tick*/
	Loc_u32TickTime_Ns=(RTOS_Prescaler*1000)/RTOS_Fcpu_M;
	Loc_u32CTCValue=(SYSTEM_TICK_ms*1000000)/Loc_u32TickTime_Ns;
	/*Check on CTC Value less than 256 To set CTC Register*/
	if(Loc_u32CTCValue<256)
	{
		TIMER0_VidSetCTCValue(Loc_u32CTCValue);
	}
	/* if CTC Value greater than 256 Go to algorithm to calculate CTC Value and number of Count*/
	else
	{
		/*Assignment*/
	}
	/*Timer init*/
	TIMER0_VidInit();
	/*GIE*/
	MGIE_VidEnable();
}
/*Create Task */
void RTOS_VidCreateTask(void (*Task)(void) ,u32 Copy_u32Periodicity,  u8 Copy_u8Priority,u32 Copy_u32FirstDelay)
{
	/*Check on Function is deleted or is created from before*/
	if(SysTasks[Copy_u8Priority].Fun==NULL)
	{
		/*Set Task Parameters*/
		SysTasks[Copy_u8Priority].Fun=Task;
		SysTasks[Copy_u8Priority].Periodicity=Copy_u32Periodicity;
		SysTasks[Copy_u8Priority].TaskState=TASK_RESUME;
		SysTasks[Copy_u8Priority].FirstDelay=Copy_u32FirstDelay;

	}
	else
	{
		/*Do Nothing*/
	}
}
void RTOS_VidScheduler(void)
{
	u8 Loc_u8Count;

	/*Loop on all tasks in RTOS system*/
	for(Loc_u8Count=0;Loc_u8Count<MAX_TASK;Loc_u8Count++)
	{
		/*check on Task is not deleted and Task State*/
		if((SysTasks[Loc_u8Count].Fun!=NULL)&&(SysTasks[Loc_u8Count].TaskState=TASK_RESUME))
		{
			/*check on Task periodicity*/
			if(SysTasks[Loc_u8Count].FirstDelay==0)
			{
				SysTasks[Loc_u8Count].Fun();
				SysTasks[Loc_u8Count].FirstDelay=SysTasks[Loc_u8Count].Periodicity-1;
			}
			else
			{
				SysTasks[Loc_u8Count].FirstDelay--;
			}
		}
		else
		{
			/*Do Nothing*/
		}
	}
}
void RTOS_VidDeleteTask(u8 Copy_u8Priority)
{
	SysTasks[Copy_u8Priority].Fun=NULL;
}
void RTOS_VidSuspendTask(u8 Copy_u8Priority)
{
	SysTasks[Copy_u8Priority].TaskState=TASK_SUSPEND;
}
void RTOS_VidResumeTask(u8 Copy_u8Priority)
{
	SysTasks[Copy_u8Priority].TaskState=TASK_RESUME;
}
