#include "f.h"

#include <stdlib.h> 
#include <string.h>

char *f4() {
	char *value;
	
	value = (char *)malloc(8 * sizeof(char));
	strncpy(value, "Bonjour", 8);
	
	return value;
}

