//A program that demonstrates bubble sort 
//06-09-2020

#include <stdio.h>
#include <stdlib.h> 
#include <ctype.h>
#include <string.h>
#include <stdint.h>

#define BYTE 8
#define MAX_LENGTH 100

void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

void print_array(int *myArray, int length) {
	
	for (int i = 0; i < length; i++) {
		printf("%d\n", myArray[i]);
	}
}

void bubbleSort(int *myArray, int length) {
	
	while (length > 0) {
		int cmp = 0;
		for (int i = 0; i < length; i++) {
			if (myArray[i] >= myArray[i + 1]) {
				swap(&myArray[i], &myArray[i + 1]);
				cmp +=1;
			}
		}
		if (!cmp) {
			break;
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

//Helper function for merge sort that combines all the partitions
void merge(int *myArray, int left, int mid, int right) {
	int i = left;
	int j = mid + 1;
	int k = left;
	int temp[MAX_LENGTH];
	
	while (i <= mid && j <= right) {
		if (myArray[i] <= myArray[j]) {
			temp[k] = myArray[i];
			i++;
		}
		else {
			temp[k] = myArray[j];
			j++;
		}
		k++;
	}
	while (i <= mid) {
		temp[k] = myArray[i];
		i++;
		k++;
	}
	while (j <= right) {
		temp[k] = myArray[j];
		j++;
		k++;
	}
	
	print_array(temp, k);
	
	int m = 0;
	while (m <= right) {
		myArray[m] = temp[m];
		m++;
	}
}


void mergeSort(int *myArray, int left, int right) {
	if (left < right) {
		int mid = left + (right - left) / 2 ;
		mergeSort(myArray, left, mid);
		mergeSort(myArray, mid + 1, right);
		merge(myArray, left, mid, right);
	}
}
//A helper function for Quicksort that partitions the array
int partition(int *array, int left, int right){
	int pivot = array[left];
	int start = left;
	int end = right;
	
	while (start < end) {
		while (array[start] < pivot) {
			start++;
		}
		while (array[end] > pivot){
			end--;
		}
		if (start >= end) {
			return end;
		}
		//need to account for case where there are duplicate entries
		if (array[start] == array[end]) {
			return end;
		}
		swap(&array[start], &array[end]);
		
	}
}

void quickSort(int *array, int left, int right){
	if (left < right) {
		int part = partition(array, left, right);
		quickSort(array, left, part - 1);
		quickSort(array, part + 1, right);
	}
}

//A function which converts a single digit into a multiple digit integer
int getBitNum (int c, int digit, int num) {
	
	c = c << (digit * BYTE);
	return (num | c);
}

//Get a file
int main (int argc, char **argv) {
	
	if (argc < 2) {
		perror("Insufficient arguments!\n");
		exit(1);
	}
	
	//Open the file
	FILE *f = fopen(argv[1], "r");
	if (!f) {
		perror("Error");
		exit(1);
	}	
	//Get the number of lines
	int count = 0;
	uint32_t c = 0;
	while ((c = fgetc(f)) != EOF) {
		if (c == '\n') {
			count +=1;
		}
	}
	printf("Size is: %d\n", count);



	//Get the array
	int *array = calloc(count, sizeof(int));

	//Reposition the pointer to the beginning
	if (fseek(f, 0, SEEK_SET) ) {
		perror("Error");
		exit(1);
	}

	c = 0;
	int i = 0;
	//The number will always end before a '\n'
	while (i < count) {
		int digit = 0;

		char *num = calloc(MAX_LENGTH, sizeof(int));
		c = fgetc(f);
		//printf("Test");
		//Read until the new line character
		while (c != '\n' && digit < 10) {	
			//c = c - '0';
			num[digit] = c;
			digit +=1;
			c = fgetc(f);
		}

		int result = 0;
		//Convert the digit to a number
		result = strtol(num, NULL, 10);
		printf("%d\n", result);
		//Convert the number
		array[i] = result;
		free(num);
		i +=1;
	}
	print_array(array, count);
	quickSort(array, 0, count - 1);
	print_array(array, count);


	/*
	int myArray[MAX_LENGTH] = {3, 93 , 24, 119, 27};
	quickSort(myArray, 0, 4);
	print_array(myArray, MAX_LENGTH);
	*/
	free(array);
}























































