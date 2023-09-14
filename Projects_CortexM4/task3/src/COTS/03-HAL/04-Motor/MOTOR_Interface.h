/*****************************************/
/* Author  :  Gehad Elkoumy              */
/* Version :  V01                        */
/* Date    :  13 Sep 2023                */
/*****************************************/

#ifndef _MOTOR_INTERFACE_H
#define _MOTOR_INTERFACE_H

#define 	stop 	 0
#define 	CW   	 1
#define 	CCW  	 2

void HMOTOR_voidInit(u8 Copy_u8EN, u8 Copy_u8IN1, u8 Copy_u8IN2);
void HMOTOR_voidRotation(u8 Copy_u8EN, u8 Copy_u8IN1, u8 Copy_u8IN2, u8 Copy_u8Direction);


#endif
