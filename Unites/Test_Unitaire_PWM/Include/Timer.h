#ifndef TIMER_H
	#define TIMER_H
	#include "stm32f10x.h"
	
	typedef struct
	{
		TIM_TypeDef * Timer ; // TIM1 à TIM4
		unsigned short ARR ;
		unsigned short PSC ;
	} MyTimer_Struct_TypeDef;
	
	void MyTimer_Base_Init ( MyTimer_Struct_TypeDef * Timer ) ;
	void MyTimer_ActiveIT (TIM_TypeDef* Timer, char Prio);
	void MyTimer_PWM(TIM_TypeDef* Timer, char Channel );
	void Modif_RapportCyclique(TIM_TypeDef* Timer, unsigned short mon_cc1);
	void TIM4_IRQHandler(void) ;
	void Modif_ARR_PSC(TIM_TypeDef* Timer, unsigned short _ARR, unsigned short _PSC);

#endif
