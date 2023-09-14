/*********************************************************************************/
/* Author    : Gehad Elkoumy                                                     */
/* Version   : V01                                                               */
/* Data      : 11 AUG 2023                                                       */
/*********************************************************************************/

#ifndef _RCC_CONFIG_H
#define _RCC_CONFIG_H
/*__________________________________________________________________________*/
/* Options:    RCC_HSE_CRYSTAL
               RCC_HSE_RC
               RCC_HSI
               RCC_PLL			   */
#define RCC_CLOCK_TYPE    RCC_HSE_CRYSTAL

/*__________________________________________________________________________*/
/* Note: Select value only if you have PLL as input clock source */
#if RCC_CLOCK_TYPE == RCC_PLL

/* Options:  	RCC_PLL_IN_HSI
				RCC_PLL_IN_HSE      */
#define 	RCC_PLL_INPUT     RCC_PLL_IN_HSI

/* Options:  */ 
#define 	PLL_MUL_VALUE     	0x00033F03 	//support clk of 84MHZ --> (PLLN = 252, PLLM = 3, PLLP = 8)
#endif 

#endif