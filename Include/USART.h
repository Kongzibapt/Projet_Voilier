#ifndef USART_H
#define USART_H
#include "stm32f10x.h"
#define BAUD_RATE 0x1D4C

typedef  struct{
	USART_TypeDef * USART ; 
} MyUSART_Struct_TypeDef ;



void MyUSART_Base_Init ( MyUSART_Struct_TypeDef * USART , char num, char mode) ;
void MyUSART_ActiveIT (USART_TypeDef * USART, char Prio);
int Read_DR_Value (USART_TypeDef * USART);

#endif
