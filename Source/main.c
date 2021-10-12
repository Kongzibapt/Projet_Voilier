#include "stm32f10x.h"
#include "USART.h"

int main (void)
{
	MyUSART_Struct_TypeDef MyUSART1;
	
	RCC->APB2ENR |= (0x01 << 2)|(0x01 << 3)|(0x01 << 4);
	
	MyUSART1.USART = USART1;
	
	MyUSART_Base_Init (&MyUSART1) ;
	MyUSART_ActiveIT (MyUSART1.USART, 0);
	
	
	do
	{	} while (1);
}
