/**********************************************************/
/* Author    : Gehad Ekoumy                               */
/* Version   : V01                           		     */
/* Date      : 17 AUG 2023                                */
/**********************************************************/

#include "../01-LIB/01-STD_TYPES/STD_TYPES.h"
#include "../01-LIB/02-BIT_MATH/BIT_MATH.h"

#include "../02-MCAL/06-STK/STK_interface.h"

#include "OS_interface.h"
#include "OS_private.h"
#include "OS_config.h"


/*OStasks is array of struct*/
static Task OStasks[NUMBER_OF_TASKS] = {NULL};

void SOS_voidCreateTask(u8 Copy_u8Priority ,u16 Copy_u16periodicity ,void (*ptr)(void) ,u16 Copy_u16firstDelay)
{
	OStasks[Copy_u8Priority].Periodicity = Copy_u16periodicity;
	OStasks[Copy_u8Priority].TaskHandler = ptr;
	OStasks[Copy_u8Priority].firstDelay = Copy_u16firstDelay;
	OStasks[Copy_u8Priority].State = TASK_READY;
}

void SOS_voidStart(void)
{
	/*determining tick time*/
	MSTK_voidInit();

	/*when HSI=8Mhz , sytem tick is 1ms*/
	MSTK_voidSetIntervalPeriodic(1000 , SCHEDULER );

}

static void SCHEDULER(void)
{
	//static u16 Local_u16TickCounter=0;
	u8 Local_u8TaskCounter;
	/*Increment of Scheduler tick counter*/

		/*Loop on the tasks*/
		for(Local_u8TaskCounter=0 ; Local_u8TaskCounter<NUMBER_OF_TASKS ; Local_u8TaskCounter++)
		{
			/*chack that task isn't deleted or suspended */
			if((OStasks[Local_u8TaskCounter].TaskHandler != NULL) && (OStasks[Local_u8TaskCounter].State == TASK_READY) )
			{
				/*Check until the first delay equal to zero*/
				if(OStasks[Local_u8TaskCounter].firstDelay == 0)
				{
					OStasks[Local_u8TaskCounter].firstDelay = OStasks[Local_u8TaskCounter].Periodicity - 1;
					/*Invoke the task function*/
					OStasks[Local_u8TaskCounter].TaskHandler();
				}
				else
				{
					/*Decrement the first delay*/
					OStasks[Local_u8TaskCounter].firstDelay--;
				}
			}
			else
			{
				/*Do nothing*/
			}
		}
}

void SOS_voidSuspendTask(u8 Copy_u8Priority)
{
	OStasks[Copy_u8Priority].State = TASK_SUSPENDED;
}

void SOS_voidResumeTask(u8 Copy_u8Priority)
{
	OStasks[Copy_u8Priority].State = TASK_READY;
}

void SOS_voidDeleteTask(u8 Copy_u8Priority)
{
	OStasks[Copy_u8Priority].TaskHandler = NULL;
}
