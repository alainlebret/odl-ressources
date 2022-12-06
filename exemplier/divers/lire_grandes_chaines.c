#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 15

char* read_input() {
   char* input = NULL;
   char temp_buf[MAX_LENGTH];
   size_t input_len;
   size_t temp_len;
   
   input_len = 0;
   temp_len = 0;
   
   do {
       fgets(temp_buf, MAX_LENGTH, stdin);
       temp_len = strlen(temp_buf);
       input = realloc(input, input_len + temp_len + 1);
       strcpy(input + input_len, temp_buf);
       input_len += temp_len;
	   printf("%d\n",temp_len);
    } while (temp_len == MAX_LENGTH-1 && temp_buf[MAX_LENGTH-2] != '\n');

    return input;
}

int main(void) {
    char* result = read_input();

    printf("Grande chaîne lue : %s\n", result);
    free(result);

    return 0;
}
