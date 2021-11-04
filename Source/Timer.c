#include "stm32f10x.h"
#include "Timer.h"
#include "../Unités/Test_Unitaire_GPIO/Include/GPIO.h"
#define OUT_PUSHPULL_2MHZ (0x2)

__WEAK void TIM4_callback (void) 
{
}

void MyTimer_Base_Init ( MyTimer_Struct_TypeDef * Timer ) {
	Timer->Timer->ARR = Timer->ARR;
	Timer->Timer->PSC = Timer->PSC;
	Timer->Timer->CR1 |= TIM_CR1_CEN;
}

void MyTimer_ActiveIT (TIM_TypeDef * Timer, char Prio){
	Timer->DIER = TIM_DIER_UIE; // Vers pending
	NVIC->ISER[0] |= NVIC_ISER_SETENA_30;
}

void TIM4_IRQHandler(void) {
	TIM4->SR &= ~(TIM_SR_UIF);
	TIM4_callback();
}

void Modif_RapportCyclique(TIM_TypeDef* Timer, unsigned short mon_cc1){
	Timer->CCR1 = mon_cc1;
}

void MyTimer_PWM(TIM_TypeDef* Timer, char Channel ){
	Timer->CCMR1 = TIM_CCMR1_OC1M_1 + TIM_CCMR1_OC1M_2;
	Timer->CCER = TIM_CCER_CC1E;
}
