/**********************************************************/
/* Author    : Gehad Ekoumy                               */
/* Version   : V01                           		     */
/* Date      : 17 AUG 2023                                */
/**********************************************************/

#ifndef OS_INTERFACE_H_
#define OS_INTERFACE_H_

/* Copy_u8Priority : Task ID*/
void SOS_voidCreateTask(u8 Copy_u8Priority ,u16 Copy_u16periodicity ,void (*ptr)(void) ,u16 Copy_u16firstDelay);
void SOS_voidStart(void);

void SOS_voidSuspendTask(u8 Copy_u8Priority);
void SOS_voidResumeTask(u8 Copy_u8Priority);
void SOS_voidDeleteTask(u8 Copy_u8Priority);

#endif
