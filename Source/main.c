#include "stm32f10x.h"
#include "rotation_plateau.h"
#include "bordage.h"

int main (void)
{
	init_bordage();
	manage_rotation();
	
	do
	{
		bordage_auto();
	} while (1);
}
