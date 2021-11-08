#include "Musique.h"


void initMusique() {

}

void getNextARR() {
	FILE* file = NULL;
	file = fopen(NOTES_FILE, "r");

	char str[5];
	fgets(str, 5, file);

	unsigned short ARR = (unsigned short)(str);
}

void getNextPSC() {

}