/**********************************************************/
/* Author    : Gehad Ekoumy                               */
/* Version   : V01                           		     */
/* Date      : 15 AUG 2023                                */
/**********************************************************/

#ifndef NVIC_PRIVATE_H
#define NVIC_PRIVATE_H

#define 	NVIC_Base_Address        0xE000E100

/* Register Map for NVIC */
typedef struct{
	
	volatile u32 ISER[8];
	volatile u32 RESERVED0[24];
	volatile u32 ICER[8];
	volatile u32 RESERVED1[24];
	volatile u32 ISPR[8];
	volatile u32 RESERVED2[24];
	volatile u32 ICPR[8];
	volatile u32 RESERVED3[24];
	volatile u32 IABR[8];
	volatile u32 RESERVED4[56];
	volatile u8 IPR[240];				// 60 registers each one has 4 of 8 bits --> 60*4 = 240
	volatile u32 RESERVED5[580];
	volatile u32 STIR;
	
}NVIC_t;

#define 	NVIC 		((NVIC_t *) NVIC_Base_Address)

#define 	RegisterSize		32		// needed to select the right register (array) and right bit in that register

//_____________________________________________________________________________________________________
/* For dividing group & sub priority bits , SCB core peripheral is needed*/
		   /*for priority group controlling IPR*/
#define SCB_AIRCR		 *((volatile u32*)0xE000ED0C)

/* 4 bits in (IPR) to determine group number */
/* in (SCB_AIRCR) 4 bits for Group and 0 bit for sub */
#define		MNVIC_GROUP_4_SUB_0		0x05FA0300 
/* in (SCB_AIRCR) 3 bits for Group and 1 bit for sub */
#define		MNVIC_GROUP_3_SUB_1		0x05FA0400 
/* in (SCB_AIRCR) 2 bits for Group and 2 bit for sub */
#define		MNVIC_GROUP_2_SUB_2		0x05FA0500 
/* in (SCB_AIRCR) 1 bits for Group and 3 bit for sub */
#define		MNVIC_GROUP_1_SUB_3		0x05FA0600 
/* in (SCB_AIRCR) 0 bits for Group and 4 bits for sub */
#define		MNVIC_GROUP_0_SUB_4		0x05FA0700 

#endif
