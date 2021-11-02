#include "stm32f10x.h"
#include "USART.h"
#include "Timer.h"
#include "GPIO.h"

#define MON_ARR 0x0E0F
#define MON_PSC 0x0000

#define BROCHE_PWM 6;

char directionBit = 0;
int RC = 0;
unsigned short Frac_ARR;

//sens horaire = positif
char Is_Positive (int arg) {
	if (0 <= arg && arg <= 100) {
		return 1;
	} else {
		return 0;
	}
}

void USART1_callback (void) 
{
	int value = 0;
	value = Read_DR_Value(USART1);
	directionBit = Is_Positive(value);
	
	if(directionBit) {
		RC = value;
	} else {
		RC = 100 - (value - 156);
	}
	Frac_ARR = MON_ARR*(RC/100.0);
	Modif_RapportCyclique(TIM4, Frac_ARR);
}

int main (void)
{
	MyUSART_Struct_TypeDef MyUSART1;
	MyTimer_Struct_TypeDef MyTimer;
	MyGPIO_Struct_TypeDef MyGPIO_PWM;
	
	RCC->APB2ENR |= RCC_APB2ENR_IOPAEN | RCC_APB2ENR_IOPBEN;
	RCC->APB1ENR |= RCC_APB1ENR_TIM4EN;
	
	MyUSART1.USART = USART1;
	MyTimer.Timer = TIM4;
	MyTimer.PSC = MON_PSC;
	MyTimer.ARR = MON_ARR;

	MyGPIO_PWM.GPIO = GPIOB;
	MyGPIO_PWM.GPIO_Pin = BROCHE_PWM;
	MyGPIO_PWM.GPIO_Conf = AltOut_Ppull;
	
	MyUSART_Base_Init(&MyUSART1) ;
	MyUSART_ActiveIT(MyUSART1.USART, 0);

	MyTimer_Base_Init(&MyTimer);
	MyTimer_PWM(MyTimer.Timer,1);

	MyGPIO_Init(&MyGPIO_PWM);
	
	do
	{	} while (1);
}
