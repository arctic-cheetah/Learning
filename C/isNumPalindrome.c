//A program that determines if an integer is a palindrome
#include <stdio.h>



int main () {
	printf("Enter a number: ");
	int myNum = 0;
	scanf("%d", &myNum);
	
	//reverse the number
	
	//If the number is equal to the reversed number,
	//Then it is a palindrome
	
	int reversedNum = 0;
	int i = myNum;
	//Check this condition
	while (i > 0) {
		reversedNum = reversedNum * 10 + (i % 10);
		i /=10;
	}
	printf("reversed: %d\n", reversedNum);
	
	if (reversedNum != myNum) {
		printf("The number is not palindromic\n");
	}
	else {
		printf("The number is palindromic\n");
	}
	 
}




































