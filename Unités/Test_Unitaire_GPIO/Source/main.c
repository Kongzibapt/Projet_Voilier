#include "stm32f10x.h"
#include "GPIO.h"
#define BROCHE_LED (5)
#define BROCHE_BOUTON (13)

int main ( void )
{
	MyGPIO_Struct_TypeDef MyGPIO_Led;
	MyGPIO_Struct_TypeDef MyGPIO_Button;

	MyGPIO_Led.GPIO = GPIOA;
	MyGPIO_Led.GPIO_Pin = BROCHE_LED;
	MyGPIO_Led.GPIO_Conf = Out_Ppull;

	MyGPIO_Button.GPIO = GPIOC;
	MyGPIO_Button.GPIO_Pin = BROCHE_BOUTON;
	MyGPIO_Button.GPIO_Conf = In_Floating;
	
	MyGPIO_Init(&MyGPIO_Led);
	MyGPIO_Init(&MyGPIO_Button);

	do
	{
		if (!MyGPIO_Read(MyGPIO_Button.GPIO, MyGPIO_Button.GPIO_Pin)) {
			MyGPIO_Set(MyGPIO_Led.GPIO, MyGPIO_Led.GPIO_Pin);
		} else {
			MyGPIO_Reset(MyGPIO_Led.GPIO, MyGPIO_Led.GPIO_Pin);
		} 
	} while (1);
}
