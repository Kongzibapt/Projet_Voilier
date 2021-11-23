#include "stm32f10x.h"
#include "MyTimer.h"
#include "PWM.h"
#include "stdlib.h"


void angle_servo(int alpha, TIM_TypeDef * MyTimer){
	int alphap = alpha-180;
	if(abs((alphap)>=135)){
		PWM_RapportCyclique(MyTimer, 6000);
	} else {
		if(alphap>-135 && alphap<0){
				int beta = -(300/9)*((4*alphap)/6 + 30) + 6000;
				PWM_RapportCyclique(MyTimer, beta);
		} else {
			int beta = (300/9)*((4*alphap)/6 - 30) + 3000;
			PWM_RapportCyclique(MyTimer, beta);
		}
	}
}
