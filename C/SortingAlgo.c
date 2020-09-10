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

void print_array(int *myArray, int length) {
	
	for (int i = 0; i < length; i++) {
		printf("%d ", myArray[i]);
	}
	printf("\n");
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

void selectionSort(int *myArray, int length) {
	
	for (int i = 0; i < length - 1; i++) {
		int j = i + 1;
		int lowest = i;
		while (j < length) {
			if (myArray[lowest] > myArray[j]) {
				lowest = j;
			}
			j++;
		}
		swap(&myArray[i], &myArray[lowest]);
	}
}

void insertionSort(int *myArray, int length) {
	
	for (int i = 0; i < length - 1; i++) {
		int j = i;
		while (j >= 0 && myArray[j] > myArray[j + 1]) {
			swap(&myArray[j], &myArray[j + 1]);
			j -=1;
		}	
	}
}





int main () {
	int myArray[MAX_LENGTH] = {3, 93 , 24, 119, 27};
	quickSort(myArray, 0, 4);
	print_array(myArray, MAX_LENGTH);
	
}























































