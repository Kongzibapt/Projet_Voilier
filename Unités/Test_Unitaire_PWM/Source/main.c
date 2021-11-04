#include "stm32f10x.h"
#include "Timer.h"

#define MON_ARR 0x0168
#define RC_50_Prct 0x00B4
#define RC_20_Prct 0x0048
#define MON_PSC 0x0001

void TIM4_callback(void)
{
	
}

int main ( void )
{
	MyTimer_Struct_TypeDef  MyTimer;
	
	MyTimer.Timer = TIM4;
	MyTimer.ARR = MON_ARR;
	MyTimer.PSC = MON_PSC;

	MyTimer_Base_Init(&MyTimer);
	MyTimer_ActiveIT(MyTimer.Timer,0);
	Modif_RapportCyclique(MyTimer.Timer,RC_20_Prct);
	MyTimer_PWM(MyTimer.Timer,1);
	
	do
	{	} while (1);
}
