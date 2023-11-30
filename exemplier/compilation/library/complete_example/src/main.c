#include <stdio.h>

#include "f.h"

int main() {
	printf("Returned by f1: %d\n", f1(1)); 
	printf("Returned by f2: %f\n", f2()); 
	printf("Returned by f3: %c\n", f3()); 
	printf("Returned by f4: %s\n", f4()); 
	return 0;
}
