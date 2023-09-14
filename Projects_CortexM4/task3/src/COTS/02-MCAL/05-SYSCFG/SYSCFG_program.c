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
	/*reset first --> (avoiding overwrite)*/
	SYSCFG->EXTICR[Copy_u8EXTILine/4] &= ~((0b1111) << (4*(Copy_u8EXTILine % 4)));
	
	/*set*/
	SYSCFG->EXTICR[Copy_u8EXTILine/4]  |= ((Copy_u8PortMap) << (4*(Copy_u8EXTILine % 4)));
}
