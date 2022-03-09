/*
 * RTOS_Interface.h
 *
 *  Created on: Mar 7, 2022
 *      Author: gerges
 */

#ifndef RTOS_STACK_RTOS_INTERFACE_H_
#define RTOS_STACK_RTOS_INTERFACE_H_

#define TASK_RESUME  1
#define TASK_SUSPEND 0

/*RTOS Init*/
void RTOS_VidInit(void);
/*Create Task */
void RTOS_VidCreateTask(void (*Task)(void) ,u32 Copy_u32Periodicity,u8 Copy_u8Priority,u32 Copy_u32FirstDelay);


void RTOS_VidDeleteTask(u8 Copy_u8Priority);
void RTOS_VidSuspendTask(u8 Copy_u8Priority);
void RTOS_VidResumeTask(u8 Copy_u8Priority);

#endif /* RTOS_STACK_RTOS_INTERFACE_H_ */
