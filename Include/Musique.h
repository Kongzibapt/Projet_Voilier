#ifndef MUSIQUE_H
	#define MUSIQUE_H


	#include <stdlib.h>
	#include <stdio.h>

	#include "stm32f10x.h"
	#include "../Unites/Test_Unitaire_PWM/Include/Timer.h"
	#include "../Unites/Test_Unitaire_GPIO/Include/GPIO.h"

	#define NOTES_FILE "Notes.txt"
	
	void initMusique();
	void getNextARR();
	void getNextPSC();

#endif
