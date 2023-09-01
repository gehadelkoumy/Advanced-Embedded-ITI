/**********************************************************/
/* Author    : Gehad Ekoumy                               */
/* Version   : V01                           		     */
/* Date      : 16 AUG 2023                                */
/**********************************************************/

#ifndef SYSCFG_INTERFACE_H
#define SYSCFG_INTERFACE_H

void	MSYSCFG_voidSetEXTIConfiguration(u8 Copy_u8Line ,u8 Copy_u8PortMap);

/*portmap used as an interrupt*/
#define 	SYSCFG_A	   0b0000
#define 	SYSCFG_B	   0b0001
#define 	SYSCFG_C	   0b0010

/*lines are in EXTI driver*/

#endif