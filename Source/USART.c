#include "stm32f10x.h"
#include "USART.h"

__WEAK void USART1_callback (void) 
{
}

void MyUSART_Base_Init ( MyUSART_Struct_TypeDef * USART ) {
	RCC->APB2ENR |= RCC_APB2ENR_USART1EN;
	USART->USART->CR1 |= USART_CR1_RE;
	USART->USART->CR1 |= USART_CR1_UE;
	USART->USART->BRR |= BAUD_RATE;
}

void MyUSART_ActiveIT (USART_TypeDef * USART, char Prio){
	USART->CR1 |= USART_CR1_RXNEIE; // Vers pending
	NVIC->ISER[1] |= NVIC_ISER_SETENA_5;
}

int Read_DR_Value (USART_TypeDef * USART){
	return(USART->DR);
}

void USART1_IRQHandler(void) {
	USART1_callback();
}
