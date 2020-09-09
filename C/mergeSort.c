#include <stdio.h>

#define MAX_LENGTH 5

void print_array(int *array, int length){
	for (int i = 0; i < length; i++) {
		printf("%d ", array[i]);
	}
	printf("\n");
}

void swap (int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void merge(int *array, int left, int mid, int right){
	int i = left;
	int j = mid + 1;
	int k = left;
	int temp[MAX_LENGTH];
	
	while (i <= mid && j <= right) {
		if (array[i] <= array[j]) {
			temp[k] = array[i];
			i++;
		}
		else {
			temp[k] = array[j];
			j++; 
		}
		k++;
	}
	
	while (i <= mid) {
		temp[k] = array[i];
		i++;
		k++;
	}
	while (j <= right) {
		temp[k] = array[j];
		j++;
		k++;
	}
	
	for(int m = 0; m < k; m++) {
		array[m] = temp[m];
	}
	
	print_array(array, MAX_LENGTH);
	 
}

void mergeSort(int *array, int left, int right){
	if (left < right) {
		int mid = left + (right - left) / 2;
		mergeSort(array, left, mid);
		mergeSort(array, mid + 1, right);
		merge(array, left, mid, right);
	} 
}





int main () {
	
	int array[MAX_LENGTH] = {54, 67, 4, 8, 24};
	mergeSort(array, 0, MAX_LENGTH - 1);

}
























































/*
void merge(int *array, int left, int mid, int right){
	int i = left;
	int j = mid + 1;
	int k = left;
	int temp[MAX_LENGTH];
	
	while (i <= mid && j <= right) {
		if (array[i] <= array[j]) {
			temp[k] = array[i];
			i++; 
		}
		else {
			temp[k] = array[j];
			j++;
		}
		k++;
	}
	
	while (i <= mid) {
		temp[k] = array[i];
		i++;
		k++;
	}
	while (j <= right) {
		temp[k] = array[j];
		j++;
		k++;
	}
	
	for (int m = 0; m <= right; m++) {
		array[m] = temp[m];
	}
	print_array(array, MAX_LENGTH);
}

void mergeSort(int *array, int left, int right){
	if (right > left) {
		int mid = left + (right - left) / 2;
		mergeSort(array, left, mid);
		mergeSort(array, mid + 1, right);
		merge(array, left, mid, right);
	}
}

*/





