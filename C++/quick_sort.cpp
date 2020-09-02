#include <iostream>

using namespace std;

#define MAX_LENGTH 7

void quick_sort(int array[], int left, int right);
int partition(int array[] ,int left, int right);
void print_array(int array[]);
void swap_val(int *a, int *b);

int main () {
	
	int array[MAX_LENGTH];
	cout << "Enter " << MAX_LENGTH << " numbers: ";
	for (int i = 0; i < MAX_LENGTH; i++) {
		cin >> array[i];
	} 
	quick_sort(array, 0, MAX_LENGTH - 1);
	print_array(array);

}

void swap_val(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void print_array(int array[]) {
	for (int i = 0; i < MAX_LENGTH; i++) {
		printf("%d ", array[i]);
	}
	printf("\n");
}

void quick_sort(int array[], int left, int right) {
	if (left < right) {
		//Get the value of the partition
		int pivot = partition(array, left, right);
		//Split and organise the lower half partition
		quick_sort(array, left, pivot - 1);
		///Split and organise the upper half partition
		quick_sort(array, pivot + 1, right);
	}
}


int partition(int array[], int left, int right) {
	
	int pivot = array[right];
	int pi = left;
	int i = left;
	while (i < right) {
		if (array[i] <= pivot) {
			swap_val(&array[i], &array[pi]);
			pi++;
		}
		
		i++;
	}
	swap_val(&array[right], &array[pi]);
	return pi;
}















































