#include <stdlib.h>
#include <string.h>

#include "util.h"

void *f1(int n) {
	void *result = NULL;

	switch (n) {
		case 1:
			result = (int *)malloc(sizeof(int));
			*((int *)result) = 10;
			break;
		case 2:
			result = (double *)malloc(sizeof(double));
			*((double *)result) = 23.5;
			break;
		case 3:
			result = (char *)malloc(STR_SIZE * sizeof(char));
			strcpy(result, "Bonjour");
			break;
		case 4:
			result = (character_t *)malloc(sizeof(character_t));
			character_t *p = (character_t *)result;
			strcpy(p->name, "The Equalizer");
			p->health = 100;
		default:
			break;
	}
	return result;
}
