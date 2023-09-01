/**********************************************************/
/* Author    : Gehad Ekoumy                               */
/* Version   : V01                           		     */
/* Date      : 16 AUG 2023                                */
/**********************************************************/

#ifndef SYSCFG_PRIVATE_H
#define SYSCFG_PRIVATE_H

#define		SYSCFG_Base_Address		0x40013800

typedef struct{
	volatile u32 MEMRMP;
	volatile u32 PMC;
	volatile u32 EXTICR[4];
	volatile u32 CMPCR;
	
}SYSCFG_t;


#define 	SYSCFG 		((SYSCFG_t *) SYSCFG_Base_Address )


#endif