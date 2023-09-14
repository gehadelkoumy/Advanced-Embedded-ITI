/**********************************************************/
/* Author    : Gehad Ekoumy                               */
/* Version   : V01                           		     */
/* Date      : 16 AUG 2023                                */
/**********************************************************/

#include "../../01-LIB/01-STD_TYPES/STD_TYPES.h"
#include "../../01-LIB/02-BIT_MATH/BIT_MATH.h"

#include "../../02-MCAL/02-GPIO/GPIO_interface.h"

#include "SWITCH_private.h"
#include "SWITCH_interface.h"
#include "SWITCH_config.h"


void HSWITCH_VoidInit(u8 Copy_u8Port,u8 Copy_u8Pin,u8 Copy_u8PullType)
{
	MGPIO_VoidSetPinMode(Copy_u8Port , Copy_u8Pin , INPUT);
	MGPIO_VoidSetPullType(Copy_u8Port , Copy_u8Pin , Copy_u8PullType);
	/* pin high?? -- Hardware*/
}


u8 HSWITCH_u8GetSwitchState(u8 Copy_u8Port,u8 Copy_u8Pin)
{
	u8 Local_u8SwitchState;
	Local_u8SwitchState = MGPIO_u8GetPinValue(Copy_u8Port , Copy_u8Pin);
	return Local_u8SwitchState;
}
