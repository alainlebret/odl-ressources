#include "factorial.h"

unsigned int factorial(int n) {
	return ((n <= 1) ? n : factorial(n-1)*n);
}

double circumference(int radius) {
	return 2 * MY_PI * radius;
}
