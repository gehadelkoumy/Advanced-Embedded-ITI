/*********************************************************************************/
/* Author    : Gehad Elkoumy                                                     */
/* Version   : V01                                                               */
/* Date      : 13 AUG 2023                                                       */
/*********************************************************************************/

#ifndef GPIO_PRIVATE_H
#define GPIO_PRIVATE_H


#define 	GPIOA_Base_Address        0x40020000            // Base address of GPIO port A
#define 	GPIOB_Base_Address        0x40020400            // Base address of GPIO port B
#define 	GPIOC_Base_Address        0x40020800            // Base address of GPIO port C

/* Register Map for GPIO */
typedef struct{
	
	volatile u32 MODER;
	volatile u32 OTYPER;
	volatile u32 OSPEEDR;
	volatile u32 PUPDR;
	volatile u32 IDR;
	volatile u32 ODR;
	volatile u32 BSRR;
	volatile u32 LCKR;
	volatile u32 AFRL;
	volatile u32 AFRH;
	
}GPIO_t;

#define 	GPIOA 		((GPIO_t *) GPIOA_Base_Address)
#define 	GPIOB 		((GPIO_t *) GPIOB_Base_Address)
#define 	GPIOC 		((GPIO_t *) GPIOC_Base_Address)


/*lock key bit*/
#define LCKK  16

#endif