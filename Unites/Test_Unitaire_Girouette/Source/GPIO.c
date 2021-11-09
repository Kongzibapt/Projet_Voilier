#include "../Include/GPIO.h"
#include "stm32f10x.h"

void MyGPIO_Init( MyGPIO_Struct_TypeDef* GPIOStructPtr ){
	//Activation Horloge GPIO
	if(GPIOStructPtr->GPIO == GPIOA) {
		RCC->APB2ENR |= RCC_APB2ENR_IOPAEN;
	} else if (GPIOStructPtr->GPIO == GPIOB) {
		RCC->APB2ENR |= RCC_APB2ENR_IOPBEN;
	} else if (GPIOStructPtr->GPIO == GPIOC) {
		RCC->APB2ENR |= RCC_APB2ENR_IOPCEN;
	} else if (GPIOStructPtr->GPIO == GPIOD) {
		RCC->APB2ENR |= RCC_APB2ENR_IOPDEN;
	}

	//Activation PIN
	if (GPIOStructPtr->GPIO_Pin < LIMIT_CRL){
		GPIOStructPtr->GPIO->CRL &= ~(0xF<<((GPIOStructPtr->GPIO_Pin)*BITS_PAR_BROCHE)); //  
		GPIOStructPtr->GPIO->CRL |= (GPIOStructPtr->GPIO_Conf<<((GPIOStructPtr->GPIO_Pin)*BITS_PAR_BROCHE)); //
	} else {
		GPIOStructPtr->GPIO->CRH &= ~(0xF<<((GPIOStructPtr->GPIO_Pin % LIMIT_CRL)*BITS_PAR_BROCHE)); //  
		GPIOStructPtr->GPIO->CRH |= (GPIOStructPtr->GPIO_Conf<<((GPIOStructPtr->GPIO_Pin % LIMIT_CRL)*BITS_PAR_BROCHE)); //
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
