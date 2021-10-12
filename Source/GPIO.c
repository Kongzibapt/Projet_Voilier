#include "GPIO.h"
#define BITS_PAR_BROCHE (4)
#include "stm32f10x.h"

void MyGPIO_Init( MyGPIO_Struct_TypeDef* GPIOStructPtr ){
	if (GPIOStructPtr->GPIO_Pin < 8){
		GPIOStructPtr->GPIO->CRL &= ~(0xF<<((GPIOStructPtr->GPIO_Pin)*BITS_PAR_BROCHE)); //  
		GPIOStructPtr->GPIO->CRL |= (GPIOStructPtr->GPIO_Conf<<((GPIOStructPtr->GPIO_Pin)*BITS_PAR_BROCHE)); //
	} else {
		GPIOStructPtr->GPIO->CRH &= ~(0xF<<((GPIOStructPtr->GPIO_Pin % 8)*BITS_PAR_BROCHE)); //  
		GPIOStructPtr->GPIO->CRH |= (GPIOStructPtr->GPIO_Conf<<((GPIOStructPtr->GPIO_Pin % 8)*BITS_PAR_BROCHE)); //
	}
}
		
int MyGPIO_Read(GPIO_TypeDef*GPIO ,char GPIO_Pin ) {
	return (GPIO->IDR & (0x1 << GPIO_Pin));
}  //  renvoie 0 ou autre  chose  different  de 0

void MyGPIO_Set(GPIO_TypeDef*GPIO ,char GPIO_Pin ) {
	GPIO->ODR |= 1<<GPIO_Pin;
}

void MyGPIO_Reset(GPIO_TypeDef*GPIO ,char GPIO_Pin ){
	GPIO->ODR &= ~(1<<GPIO_Pin);
}

void MyGPIO_Toggle(GPIO_TypeDef*GPIO ,char GPIO_Pin ){
	if (MyGPIO_Read(GPIO,GPIO_Pin)){
		MyGPIO_Reset(GPIO,GPIO_Pin);
	} else {
		MyGPIO_Set(GPIO,GPIO_Pin);
	}
}
