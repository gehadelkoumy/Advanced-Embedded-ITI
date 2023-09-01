/**********************************************************/
/* Author    : Gehad Ekoumy                               */
/* Version   : V01                           		     */
/* Date      : 16 AUG 2023                                */
/**********************************************************/

#ifndef STK_PRIVATE_H
#define STK_PRIVATE_H

#define 	STK_Base_Address		0xE000E010

typedef struct
{
	volatile u32 CTRL  ;
	volatile u32 LOAD  ;
	volatile u32 VAL   ;
	volatile u32 CALIB;

}MSTK_t;

#define     MSTK    ((volatile MSTK_t*) STK_Base_Address)


#define     MSTK_SRC_AHB           0
#define     MSTK_SRC_AHB_8         1

#define     MSTK_SINGLE_INTERVAL    0
#define     MSTK_PERIOD_INTERVAL    1

/* Define Callback Global Variable */
#define  NULL 	(void*)0
static void(*MSTK_GlobalPtr)(void) = '\0';

#endif
