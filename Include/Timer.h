#ifndef TIMER_H
	#define TIMER_H
	#include "stm32f10x.h"
	
	typedef struct
	{
		TIM_TypeDef * Timer ; // TIM1 � TIM4
		unsigned short ARR ;
		unsigned short PSC ;
	} MyTimer_Struct_TypeDef;
	
	void MyTimer_Base_Init ( MyTimer_Struct_TypeDef * Timer ) ;
	void MyTimer_ActiveIT (TIM_TypeDef* Timer, char Prio);
	void MyTimer_PWM(TIM_TypeDef* Timer, char Channel );
	void Modif_RapportCyclique(TIM_TypeDef* Timer, unsigned short mon_cc1);
	void TIM4_IRQHandler(void) ;

	#define MyTimer_Base_Start ( Timer ) ( . . . )
	#define MyTimer_Base_Stop ( Timer ) ( . . . )
#endif
