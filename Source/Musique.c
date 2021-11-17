#include "Musique.h"


void initMusique() {

}

void getNextARR() {
	char str[5];
	FILE* file = NULL;
	unsigned short ARR;

	file = fopen(NOTES_FILE, "r");
	fgets(str, 5, file);
	ARR = (unsigned short)(str);
}

void getNextPSC() {

}