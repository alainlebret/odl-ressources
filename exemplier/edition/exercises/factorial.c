#include <stdio.h>

int factorial(int n) {
 int i, result = 1;
	
 for (i = 1; i <= n; ++i) { 
  result *= i; 
 }
 return result;
}

int main() {
 int n; 

 scanf("%d", &n);
	
 if (n >= 0) {
  printf("%d / %d\n", n, factorial(n));
 } else {
  printf("The integer should be positive or equals to zero.\n");
  return -1;
 }
	
 return 0;
}
