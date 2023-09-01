/*********************************************************************************/
/* Author    : Gehad Elkoumy                                                     */
/* Version   : V01                                                               */
/* Data      : 11 AUG 2023                                                       */
/*********************************************************************************/

#include "../../01-LIB/01-STD_TYPES/STD_TYPES.h"
#include "../../01-LIB/02-BIT_MATH/BIT_MATH.h"

#include "RCC_private.h"
#include "RCC_config.h"
#include "RCC_interface.h"


void MRCC_voidInitSysClock(void)
{
	#if     RCC_CLOCK_TYPE == RCC_HSE_CRYSTAL
		RCC -> CR   = 0x00010000; /* Enable HSE with no bypass */
		RCC -> CFGR = 0x00000001;
		
	#elif   RCC_CLOCK_TYPE == RCC_HSE_RC
		RCC -> CR   = 0x00050000; /* Enable HSE with bypass */
		RCC -> CFGR = 0x00000001;
		
	#elif   RCC_CLOCK_TYPE == RCC_HSI
		RCC -> CR   = 0x00000081; /* Enable HSI + Trimming(default) = 0 */
		RCC -> CFGR = 0x00000000;
	
	#elif   RCC_CLOCK_TYPE == RCC_PLL
		
			RCC -> PLLCFGR = PLL_MUL_VALUE;  
		
		#if   RCC_PLL_INPUT == RCC_PLL_IN_HSI
			RCC -> CR   = 0x00000001;  /*HSI*/
			/*PLL as system clock + HSI*/
			CLR_BIT(RCC->CFGR , SW0);
			SET_BIT(RCC->CFGR , SW1);
			CLR_BIT(RCC->PLLCFGR , PLLSRC);
			/*Enable PLL*/
			SET_BIT(RCC->CR , PLL_ON);
		
		#elif RCC_PLL_INPUT == RCC_PLL_IN_HSE
			RCC -> CR   = 0x00010000;  /*HSE*/
			/*PLL as system clock + HSE*/
			CLR_BIT(RCC->CFGR , SW0);
			SET_BIT(RCC->CFGR , SW1);
			SET_BIT(RCC->PLLCFGR , PLLSRC);
			/*Enable PLL*/
			SET_BIT(RCC->CR , PLL_ON);
		
		#endif
	
	#else
		#error("You chosed Wrong Clock type")
	#endif
}


void MRCC_voidEnableClock(u8 Copy_u8BusId, u8 Copy_u8PeripheralId)
{
	/*check input validation (32 bits)*/
	if (Copy_u8PeripheralId <= 31)     
	{
		switch (Copy_u8BusId)
		{
			case RCC_AHB1 : SET_BIT(RCC->AHB1ENR  , Copy_u8PeripheralId);   
			break;
			
			case RCC_AHB2 : SET_BIT(RCC->AHB2ENR  , Copy_u8PeripheralId);   
			break;
			
			case RCC_APB1 : SET_BIT(RCC->APB1ENR , Copy_u8PeripheralId);   
			break;
			
			case RCC_APB2 : SET_BIT(RCC->APB2ENR , Copy_u8PeripheralId);   
			break;
		}
	}

}


void MRCC_voidDisableClock(u8 Copy_u8BusId, u8 Copy_u8PeripheralId)
{
	/*check input validation (32 bits)*/
	if (Copy_u8PeripheralId <= 31)
	{
		switch (Copy_u8BusId)
		{
			case RCC_AHB1 : CLR_BIT(RCC->AHB1ENR  , Copy_u8PeripheralId);   
			break;
			
			case RCC_AHB2 : CLR_BIT(RCC->AHB2ENR  , Copy_u8PeripheralId);   
			break;
			
			case RCC_APB1 : CLR_BIT(RCC->APB1ENR , Copy_u8PeripheralId);   
			break;
			
			case RCC_APB2 : CLR_BIT(RCC->APB2ENR , Copy_u8PeripheralId);   
			break;
		}
	}

}

