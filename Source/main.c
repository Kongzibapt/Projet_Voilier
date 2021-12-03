#include "stm32f10x.h"
#include "rotation_plateau.h"

#include "MyTimer.h"
#include "Driver_GPIO.h"
#include "Servo.h"
#include "PWM.h"
#include "Encoder.h"
#include "Bordage.h"

int main (void)
{
	init_bordage();
	manage_rotation();
	
	do
	{
		//bordage_auto();
	} while (1);
}
