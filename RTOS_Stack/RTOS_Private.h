/*
 * RTOS_Private.h
 *
 *  Created on: Mar 7, 2022
 *      Author: gerges
 */

#ifndef RTOS_STACK_RTOS_PRIVATE_H_
#define RTOS_STACK_RTOS_PRIVATE_H_

typedef struct
{
	void (*Fun)(void);
	u32 Periodicity;
	u8 TaskState;
	u32 FirstDelay;
}Task_t;

/*Scheduler*/
void RTOS_VidScheduler(void);

#endif /* RTOS_STACK_RTOS_PRIVATE_H_ */
