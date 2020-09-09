//A practice on implementing quick sort

#include <stdio.h>

#define MAX_LENGTH 6

void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

void print_array(int *array, int length){
	for (int i = 0; i < length; i++) {
		printf("%d ", array[i]);
	}
	printf("\n");
}
/*
//Hoare's partition
int partition(int *array, int left, int right){
	int pivot = array[left + (right - left) / 2];
	int start = left;
	int end = right;
	
	while (start < end) {
		while (array[start] < pivot) {
			start++;
		}
		while (array[end] > pivot) {
			end--;
		}
		if (start >= end) {
			return end;
		}
		swap(&array[start], &array[end]);
	}
}
*/

//Lomuto's partition

int partition (int *array, int left, int right) {
	int pivotLocation = left + (right - left) / 2;
	int pivot = array[pivotLocation];
	int i = left;
	int j = left;
	
	while (i < right) {
		if (array[i] < pivot) {
			swap(&array[i], &array[j]);
			j++;
		}
		
		i++;
	}
	swap(&array[j], &array[pivotLocation]);
	return j;
}

void quickSort(int *array, int left, int right){
	if (left < right) {
		int mid = partition(array, left, right);
		quickSort(array, left, mid - 1);
		quickSort(array, mid + 1, right);
	}
}



int main(){
	int array[MAX_LENGTH] = {78, 54, 24, 36, 58, 99};
	quickSort(array, 0, MAX_LENGTH - 1);
	print_array(array, MAX_LENGTH);
	
}

















































