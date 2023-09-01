/**********************************************************/
/* Author    : Gehad Ekoumy                               */
/* Version   : V01                           		     */
/* Date      : 17 AUG 2023                                */
/**********************************************************/

#ifndef OS_PRIVATE_H_
#define OS_PRIVATE_H_

#define  NULL 	(void*)0

			/*task states*/
#define			TASK_SUSPENDED			    1
#define			TASK_READY					2

/*each task has : 1. C_function
				  2. timing
				  3. context switching
				  4. storage
priodicity pointer to function(execute), first delay and state*/

typedef struct
{
	u16 Periodicity;
	void (*TaskHandler)(void);
	u16	firstDelay;
	u8 State;
}Task;



static void SCHEDULER(void);

#endif
