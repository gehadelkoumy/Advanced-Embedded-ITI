/*********************************************************************************/
/* Author    : Gehad Elkoumy                                                     */
/* Version   : V01                                                               */
/* Data      : 11 AUG 2023                                                       */
/*********************************************************************************/

#ifndef RCC_PRIVATE_H
#define RCC_PRIVATE_H

#define 	RCC_Base_Address		0x40023800

/* Register Map */
typedef struct{
	
	volatile u32 CR;
	volatile u32 PLLCFGR;
	volatile u32 CFGR;
	volatile u32 CIR;
	volatile u32 AHB1RSTR;
	volatile u32 AHB2RSTR;
	volatile u32 RESERVED1;
	volatile u32 RESERVED2;
	volatile u32 APB1RSTR;
	volatile u32 APB2RSTR;
	volatile u32 RESERVED3;
	volatile u32 RESERVED4;
	volatile u32 AHB1ENR;
	volatile u32 AHB2ENR;
	volatile u32 RESERVED5;
	volatile u32 RESERVED6;
	volatile u32 APB1ENR;
	volatile u32 APB2ENR;
	volatile u32 RESERVED7;
	volatile u32 RESERVED8;
	volatile u32 AHB1LPENR;
	volatile u32 AHB2LPENR;
	volatile u32 RESERVED9;
	volatile u32 RESERVED10;
	volatile u32 APB1LPENR;
	volatile u32 APB2LPENR;
	volatile u32 RESERVED11;
	volatile u32 RESERVED12;
	volatile u32 BDCR;
	volatile u32 CSR;
	volatile u32 RESERVED13;
	volatile u32 RESERVED14;
	volatile u32 SSCGR;
	volatile u32 PLLI2SCFGR;
	volatile u32 RESERVED15;
	volatile u32 DCKCFGR;
	
}RCC_t;

#define 	RCC 		((RCC_t *) RCC_Base_Address)


/* Clock Types */
#define RCC_HSE_CRYSTAL      0
#define RCC_HSE_RC           1
#define RCC_HSI              2
#define RCC_PLL              3

/* PLL Options */
#define RCC_PLL_IN_HSI       0
#define RCC_PLL_IN_HSE       1

/*RCC_CFGR Register Bits*/
#define SW0        			 0
#define SW1        			 1
#define PLLSRC     			 22

/*RCC_CR Register Bits*/
#define PLL_ON     			 24


#endif