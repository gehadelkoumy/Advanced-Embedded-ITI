/**********************************************************/
/* Author    : Gehad Ekoumy                               */
/* Version   : V01                           		     */
/* Date      : 15 AUG 2023                                */
/**********************************************************/

#include "../../01-LIB/01-STD_TYPES/STD_TYPES.h"
#include "../../01-LIB/02-BIT_MATH/BIT_MATH.h"

#include "NVIC_private.h"
#include "NVIC_config.h"
#include "NVIC_interface.h"



void MNVIC_voidEnableInterrupt (u8 Copy_u8IntNumber)
{
	NVIC->ISER[Copy_u8IntNumber/RegisterSize] = (1 << (Copy_u8IntNumber%RegisterSize));
}


void MNVIC_voidDisableInterrupt (u8 Copy_u8IntNumber)
{
	NVIC->ICER[Copy_u8IntNumber/RegisterSize] = (1 << (Copy_u8IntNumber%RegisterSize));
}


		/*for testing & debugging*/
void MNVIC_voidSetPendingFlag(u8 Copy_u8IntNumber)
{
	NVIC->ISPR[Copy_u8IntNumber/RegisterSize] = (1 << (Copy_u8IntNumber%RegisterSize));
}


void MNVIC_voidClearPendingFlag(u8 Copy_u8IntNumber)
{
	NVIC->ICPR[Copy_u8IntNumber/RegisterSize] = (1 << (Copy_u8IntNumber%RegisterSize));
}


u8 MNVIC_u8GetActiveFlag(u8 Copy_u8IntNumber)
{
	u8 Local_u8Result = 0;
	
	Local_u8Result = GET_BIT((NVIC->IABR[Copy_u8IntNumber/RegisterSize]),(Copy_u8IntNumber%RegisterSize));
	
	return Local_u8Result;      /*1 : interrupt is executing*/
}


/*function takes : peripheral + group proirity + sub proirity*/
void MNVIC_voidSetPriority(u8 Copy_u8IntNumber , u8 Copy_u8GroupPriority ,u8 Copy_u8SubPriority )
{				
				  /* group priority value is shifted by number of sub bits */			
				  /* priority = sub priority value | group priority value */
/* ex : 0x05FA0400 3 Group & 1 sub priority (group priority is shifted by 1)*/
	u8 Local_u8Priority = Copy_u8SubPriority | (Copy_u8GroupPriority << ((NUM_OF_GROUPS_SUB - 0x05FA0300)/256));
	
	/*each byte --> first 4 bits are reserved*/
	NVIC->IPR[Copy_u8IntNumber] = Local_u8Priority << 4 ;
	
	SCB_AIRCR = NUM_OF_GROUPS_SUB ;
}
