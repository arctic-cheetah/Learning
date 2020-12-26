#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

#define MAX_LENGTH 0xff
//Determine the max iterations
#define MAX_BOUND 20
//A program that finds solutions via the bisection method
//Only uses polynomials

//No error checking at all!

//A function that evaluates for powers
double get_pow (char *s, double x, int *i) {
	*i +=1;
	if (s[*i] == 'x') {
		*i +=1;
		//Check if an exponent is present
		if (s[*i] == '^') {
			*i +=1;
			//Get the exponent
			return pow(x, s[*i] - '0');
		}
		return x;
	}
}

//A function that evaluates a function given an input

//It does not consider brackets
double cal_func(char *s, double x) {
	
	int i = 0;
	double evalTerm = 0;
	double coeff = 1;
	double result = 0;
	while (s[i] != 0) {
	
		//Check for a coefficient
		if ( isdigit(s[i]) ) {
			coeff = s[i] - '0';
		}
		else {
			coeff = 1;
		}
		i +=1;
		
		//Check if the expression ends here
		if (s[i] == 0) {
			break;
		}
		
		//Check for divison or multiplication
		if (s[i] == '*') {
			evalTerm = coeff * get_pow(s, x, &i);
		}
		else if (s[i] == '/') {
			evalTerm = coeff / get_pow(s, x, &i);
		}
		printf("%lf\n", evalTerm);
		i +=1;
		
		//Check if the expression ends here
		if (s[i] == 0) {
			break;
		}
		
		//Check if addition or subtraction is needed
		if (s[i] == '+') {
			result +=evalTerm;
		}
		else if (s[i] == '-') {
			result -=evalTerm;
		}
		i +=1;
	}
	
	printf("The result is: %lf \n", result);
	return result;
}


int main () {
	
	//Enter a function via scanf
	char *expression = calloc(MAX_LENGTH, sizeof(char));
	printf("Enter the function f(x) = ");
	scanf("%s", expression);
	
	//Or a variable
	//char *expression = {""}
	
	printf("Enter two ranges\n");
	//double a, b;
	//scanf("%lf, %lf", &a, &b);
	
	/*
	int i = 0;
	while (i < MAX_BOUND) {
		
		double c = (a + b) / 2;
		
		if () {
			
		}
		
		i +=1;
	}
	*/
	
	cal_func(expression, 5);
	
	free(expression);
	return 0;
}
