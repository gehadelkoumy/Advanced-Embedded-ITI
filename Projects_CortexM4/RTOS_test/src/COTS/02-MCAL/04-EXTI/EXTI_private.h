/**********************************************************/
/* Author    : Gehad Ekoumy                               */
/* Version   : V01                           		     */
/* Date      : 16 AUG 2023                                */
/**********************************************************/

#ifndef EXTI_PRIVATE_H
#define EXTI_PRIVATE_H

#define 	EXTI_Base_Address		0x40013C00

/*must be ordered*/
typedef struct{
	volatile u32 IMR;
	volatile u32 EMR;
	volatile u32 RTSR;
	volatile u32 FTSR;
	volatile u32 SWIER;
	volatile u32 PR;
	
}EXTI_t;

/*without dereference as it act as pointer*/
#define		EXTI  	 	((EXTI_t *) EXTI_Base_Address )

static void (*EXTI_GlobalPtr[16]) (void) ;

#endif
