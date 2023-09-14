/**********************************************************/
/* Author    : Gehad Ekoumy                               */
/* Version   : V01                           		     */
/* Date      : 16 AUG 2023                                */
/**********************************************************/

#ifndef SWITCH_INTERFACE_H_
#define SWITCH_INTERFACE_H_

void HSWITCH_VoidInit(u8 Copy_u8Port,u8 Copy_u8Pin,u8 Copy_u8PullType);
u8 HSWITCH_u8GetSwitchState(u8 Copy_u8Port,u8 Copy_u8Pin);


#endif
