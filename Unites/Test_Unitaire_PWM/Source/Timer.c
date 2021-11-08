#include "stm32f10x.h"
#include "../Include/Timer.h"

__WEAK void TIM4_callback (void) 
{
}

//Interruption pour la musique (update la freq de la PWM)
__WEAK void TIM2_callback (void) 
{
}

void MyTimer_Base_Init ( MyTimer_Struct_TypeDef * Timer ) {
	if(Timer->Timer == TIM1){
		RCC->APB2ENR |= RCC_APB2ENR_TIM1EN;
	} else if (Timer->Timer == TIM2){
		RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;
	} else if (Timer->Timer == TIM3){
		RCC->APB1ENR |= RCC_APB1ENR_TIM3EN;
	} else if (Timer->Timer == TIM4){
		RCC->APB1ENR |= RCC_APB1ENR_TIM4EN;
	}

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

void Modif_ARR_PSC(TIM_TypeDef* Timer, unsigned short _ARR, unsigned short _PSC) {
	Timer->ARR = _ARR;
	Timer->PSC = _PSC;
}

void MyTimer_PWM(TIM_TypeDef* Timer, char Channel ){
	Timer->CCMR1 = TIM_CCMR1_OC1M_1 + TIM_CCMR1_OC1M_2;
	Timer->CCER = TIM_CCER_CC1E;
}
