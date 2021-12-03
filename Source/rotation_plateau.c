#include "stm32f10x.h"
#include "USART.h"
#include "../Unites/Test_Unitaire_PWM/Include/Timer.h"
#include "../Unites/Test_Unitaire_GPIO/Include/GPIO.h"
#include "rotation_plateau.h"

static char directionBit = 0;
static int RC = 0;
static unsigned short Frac_ARR;

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
		MyGPIO_Set(GPIOB, BROCHE_DIRECTION);
	} else {
		RC = 100 - (value - 156);
		MyGPIO_Reset(GPIOB, BROCHE_DIRECTION);
	}
	Frac_ARR = MON_ARR*(RC/100.0);
	Modif_RapportCyclique(TIM4, Frac_ARR);
	
}

void manage_rotation()
{	
	//Declarations
	MyUSART_Struct_TypeDef MyUSART1;
	MyTimer_Struct_TypeDef MyTimer;
	//MyTimer_Struct_TypeDef MyTimer_Musique;
	MyGPIO_Struct_TypeDef MyGPIO_PWM;
	MyGPIO_Struct_TypeDef MyGPIO_Direct;

	//Temp
	//RCC->APB1ENR |= RCC_APB1ENR_TIM4EN;
	
	//Spec
	MyUSART1.USART = USART1;

	MyTimer.Timer = TIM4;
	MyTimer.PSC = MON_PSC;
	MyTimer.ARR = MON_ARR;

	//MyTimer_Musique.Timer = TIM2;
	//MyTimer_Musique.PSC = PSC_MUSIQUE;
	//MyTimer_Musique.ARR = ARR_MUSIQUE;

	MyGPIO_PWM.GPIO = GPIOB;
	MyGPIO_PWM.GPIO_Pin = BROCHE_PWM;
	MyGPIO_PWM.GPIO_Conf = AltOut_Ppull;

	MyGPIO_Direct.GPIO = GPIOB;
	MyGPIO_Direct.GPIO_Pin = BROCHE_DIRECTION;
	MyGPIO_Direct.GPIO_Conf = Out_Ppull;
	
	//Inits
	MyUSART_Base_Init(&MyUSART1, 1, 0);
	MyUSART_ActiveIT(MyUSART1.USART, 0);

	MyTimer_Base_Init(&MyTimer);
	MyTimer_PWM(MyTimer.Timer,1);

	//MyTimer _Base_Init(&MyTimer_Musique);

	MyGPIO_Init(&MyGPIO_PWM);
	MyGPIO_Init(&MyGPIO_Direct);
}
