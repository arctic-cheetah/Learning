//A program that utilises memoization and recursion to calculate factorials.
#include <stdio.h>

#define MAX_LENGTH 1023

int memory[MAX_LENGTH] = {0};
int calls = 0;

int factorial (int num) {
	calls +=1;
	
	if (memory[num] != 0) {
		return memory[num];
	}
	
	if (num == 1) {
		return num;
	}
	else {
		memory[num] = factorial(num - 1) * num;
		return memory[num];
	}
}

int main () {
	printf("The factorial of 5 is: %d \n", factorial(10) );
}





















