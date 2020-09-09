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
	int pivot = array[right];
	int j = left;
	int i = left;
	
	while (i < right) {
		if (array[i] <= pivot) {
			swap(&array[i], &array[j]);
			j++;
		}
		
		i++;
	}
	swap(&array[j], &array[right]);
	return j;
}

void quickSort(int *array, int left, int right){
	if (left < right) {
		int part = partition(array, left, right);
		quickSort(array, left, part - 1);
		quickSort(array, part + 1, right);
	}
}


int main () {
	int myArray[MAX_LENGTH] = {3, 93 , 24, 119, 27};
	quickSort(myArray, 0, 4);
	print_array(myArray, MAX_LENGTH);
	
}























































