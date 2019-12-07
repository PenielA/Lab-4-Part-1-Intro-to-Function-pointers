#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#define UPPER 100
#define LOWER 10

typedef int (*Conditional)(int a, int b);
/* IMPLEMENT ME: Declare your functions here */
int add (int a, int b);
int subtract (int a, int b);
int multiply (int a, int b);
int divide (int a, int b);

int main (void)
{
  Conditional condition_functions[5];
  char option[20];
  condition_functions[0] = &add;
  condition_functions[1] = &subtract;
  condition_functions[2] = &multiply;
  condition_functions[3] = &divide;
  srand(time(NULL));
  
  int num1 = rand()%(UPPER - LOWER + 1) + LOWER;
  int num2 = rand()%(UPPER - LOWER + 1) + LOWER;
  
  while(1){
    printf("Operand 'a' : %d | Operand 'b' : %d Specify the operation to perform"
					 "(0 : add | 1 : subtract | 2 : Multiply | 3: divide | 4 : exit):", num1, num2);
    scanf("%s", option);
		
		if (atoi(option) == 4){
			printf("Exitting!!\n");
			break;
    }
      // Index the funtion array and get result. 
		int ans = (*condition_functions[atoi(option)])(num1, num2);
		printf("X: %d\n", ans);
  }
	return 0;
}
int add(int a, int b) { 
  printf ("Adding 'a' and 'b'\n"); 
  return a + b; 
}
int subtract(int a, int b) { 
  printf ("Subtracting 'b' from 'a'\n"); 
  return a - b; 
}
int multiply(int a, int b) { 
  printf ("Multiplying 'a' by 'b'\n"); 
  return a * b; 
}
int divide(int a, int b) { 
  printf ("Dividing 'a' by 'b'\n"); 
  return a / b; 
}
