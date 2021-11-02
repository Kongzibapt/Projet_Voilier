#include "stm32f10x.h"
#include "USART.h"

__WEAK void USART1_callback (void) 
{
}

void MyUSART_Base_Init ( MyUSART_Struct_TypeDef * USART, char num, char mode) {
	switch(num) {
		case 1: RCC->APB2ENR |= RCC_APB2ENR_USART1EN;
			break;
		case 2: RCC->APB2ENR |= RCC_APB1ENR_USART2EN;
			break;
		default: break;
	}
	//mode 0 : read, mode 1 : write
	switch (mode) {
		case 0: USART->USART->CR1 |= USART_CR1_RE;
			break;
		case 1: USART->USART->CR1 |= USART_CR1_TE;
			break;
		default: break;
	}
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

void Write_DR_Value(USART_TypeDef * USART, unsigned short data) {
	USART->DR = data;
}

void USART1_IRQHandler(void) {
	USART1_callback();
}
