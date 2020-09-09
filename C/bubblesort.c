//A program that demonstrates bubble sort 
//06-09-2020

#include <stdio.h>
#include <stdlib.h>

#define MAX_LENGTH 5

void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

void bubbleSort(int *myArray, int length) {
	
	while (length > 0) {
		for (int i = 0; i < length; i++) {
			if (myArray[i] >= myArray[i + 1]) {
				swap(&myArray[i], &myArray[i + 1]);
			}
		}
		length -=1;
	}
}

void print_array(int *myArray, int length) {
	
	for (int i = 0; i < length; i++) {
		printf("%d ", myArray[i]);
	}
	printf("\n");
}

int main () {
	int myArray[MAX_LENGTH] = {5, 33 , 4, 19, 27};
	bubbleSort(myArray, MAX_LENGTH - 1);
	print_array(myArray, MAX_LENGTH);
	
}























































