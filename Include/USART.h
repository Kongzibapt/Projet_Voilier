#ifndef USART_H
#define USART_H
#include "stm32f10x.h"

typedef  struct{
	USART_TypeDef * USART ; 
} MyUSART_Struct_TypeDef ;



void MyUSART_Base_Init ( MyUSART_Struct_TypeDef * USART ) ;
void MyUSART_ActiveIT (USART_TypeDef * USART, char Prio);

#endif
