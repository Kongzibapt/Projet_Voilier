#include "stm32f10x.h"
#include "MyTimer.h"
#include "PWM.h"
#include "stdlib.h"


void angle_servo(int alpha, TIM_TypeDef * MyTimer){
	int alphap = abs(alpha-180);
	if(alphap<=45 || alphap>=135){
		PWM_RapportCyclique(MyTimer, 6000);
	} else {
		if(alphap>45 && alphap<90){
				int beta = -(3000/45)*(2*alphap - 90) + 9000;
				PWM_RapportCyclique(MyTimer, beta);
		} else if(alphap>=90 && alphap<135){
				int beta = (3000/45)*(2*alphap - 90) - 3000;
				PWM_RapportCyclique(MyTimer, beta);
		}
	}
}
