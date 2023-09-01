/**********************************************************/
/* Author    : Gehad Ekoumy                               */
/* Version   : V01                           		     */
/* Date      : 16 AUG 2023                                */
/**********************************************************/

#include "../../01-LIB/01-STD_TYPES/STD_TYPES.h"
#include "../../01-LIB/02-BIT_MATH/BIT_MATH.h"

#include "SYSCFG_private.h"
#include "SYSCFG_config.h"
#include "SYSCFG_interface.h"


void	MSYSCFG_voidSetEXTIConfiguration(u8 Copy_u8EXTILine , u8 Copy_u8PortMap)
{
	u8 Local_u8RegIndex = 0 ;		
	/* Assign to EXTICRX register */
	if(Copy_u8EXTILine <= 3 )
	{
		Local_u8RegIndex = 0;
	}
	else if(Copy_u8EXTILine <= 7)
	{	
		Local_u8RegIndex = 1;
		
		/*bit0 to bit3 not 4 to 7*/
		Copy_u8EXTILine -= 4;
	}
	else if(Copy_u8EXTILine <= 11)
	{
		Local_u8RegIndex = 2;
		/*4bits from 0 to 3*/
		Copy_u8EXTILine -= 8;
	
	}
	else if(Copy_u8EXTILine <= 15)
	{
		Local_u8RegIndex = 3;
		/*4bits from 0 to 3*/
		Copy_u8EXTILine -= 12;
	}
	
	/*reset first --> (avoiding overwrite)*/
	SYSCFG->EXTICR[Local_u8RegIndex] &= ~((0b1111) << (Copy_u8EXTILine * 4));
	
	/*set*/
	SYSCFG->EXTICR[Local_u8RegIndex]  |= ((Copy_u8PortMap) << (Copy_u8EXTILine * 4));	
}
