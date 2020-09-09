//A program that illustrates quickSort

#include <stdio.h>

#define MAX_LENGTH 6

void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

void print_array(int *array, int length){
	
	for(int i = 0; i < length; i++){
		printf("%d ", array[i]);
	}
	printf("\n");
}
//Lomuto's implementation
int partition(int *array, int left, int right){
	//Median-of-three pivot (sedgewick)
	int mid = left + (right - left) / 2;
	if (array[mid] < array[left]) {
		swap(&array[mid], &array[left]);
	}
	if (array[right] < array[left]) {
		swap(&array[right], &array[left]);
	}
	if (array[mid] < array[right]) {
		swap(&array[right], &array[mid]);
	}
	
	int pivot = array[right];
	int i = left;
	int part = left; 
	
	while (i < right) {
		if (array[i] <= pivot) {
			swap(&array[i], &array[part]);
			part++;
		}
		i++;
	}
	swap(&array[part], &array[right]);
	return part;
}


void quickSort(int *array, int left, int right){
	if (left < right) {
		int mid = partition(array, left, right);
		quickSort(array, left, mid - 1);
		quickSort(array, mid + 1, right);
	}
}

int main(){
	int array[MAX_LENGTH] = {74, 69, 52, 32, 12, 4};
	quickSort(array, 0, MAX_LENGTH - 1);
	print_array(array, MAX_LENGTH);

}







/*







//Lumoto's implementation of partitioning
int partition(int *array, int left, int right){
	int pivot = array[right];
	int i = left;
	int part = left; 
	
	while (i < right) {
		if (array[i] <= pivot) {
			swap(&array[i], &array[part]);
			part++;
		}
		i++;
	}
	swap(&array[part], &array[right]);
	return part;
}

void quickSort(int *array, int left, int right){
	if (left < right) {
		int mid = partition(array, left, right);
		quickSort(array, left, mid - 1);
		quickSort(array, mid + 1, right);
	}
}


//Hoare's implementation of partitioning
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
		else {
			swap(&array[start], &array[end]);
		}
	}

}

void quickSort(int *array, int left, int right){
	if (left < right) {
		int mid = partition(array, left, right);
		partition(array, left, mid - 1);
		partition(array, mid + 1, right);
	}
}


*/
































