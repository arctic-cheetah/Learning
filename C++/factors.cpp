//A program that finds


#include <iostream>
#include <cmath>
#include <cstdlib>

#define MAX_LEN 0xFFFF

int main () {
	std::cout << "Enter a number: ";
	int myNum = 0;
	std::cin >> myNum;
	
	//Check if 5 is divisible by all the numbers up to sqrt of 5
	double stop = sqrt(myNum);
	
	//Add any divisible numbers into an array
	int *factors = (int *)calloc(MAX_LEN, sizeof(int));
	
	double i = 0;
	int div = 1;
	int numOfFactors = 0;
	int isPrime = 1;
	while (i < stop) {
		if (myNum % div == 0) {
			factors[numOfFactors] = div;
			numOfFactors +=1;
			factors[numOfFactors] = myNum / div;
			numOfFactors +=1;
			
			if (div != 1) {
				isPrime = 0;
			}
		}
		div +=1;
		i +=1;
	}
	
	if (isPrime) {
		std::cout << "The number is a prime!\n";
	}
	//Print the factors of a number
	for (int i = 0; i < numOfFactors; i +=1) {
		if (i == numOfFactors - 1) {
			std::cout << factors[i];
		}
		else {
			std::cout << factors[i] << + ", ";
		}
	}
	std::cout << "\n";
	free(factors);
	
	return 0;
}























