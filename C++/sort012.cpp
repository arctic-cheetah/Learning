#include <iostream>

using namespace std;

void print_array(int array[], int size);
void quick_sort(int array[], int left, int right);
int partition(int array[], int left, int right);
void swap_val (int *a, int *b);

int main () {
	int size = 0;	
	
	cout << "Enter the size of the array: ";
	cin >> size;
	
	int array[size];
	cout << "Enter the elements of the array: ";
	for (int i = 0; i < size; i++) {
		cin >> array[i];
	}
	
	quick_sort(array, 0, size);
	print_array(array, size);
		
	return 0;
}

void print_array(int array[], int size){
	for (int i = 0; i < size; i++) {
		cout << array[i] << " ";
	}
	printf("\n");
}

void swap_val (int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void quick_sort(int array[], int left, int right) {
	if (left < right) {
		int party = partition(array, left, right);
		//Send in the lower half
		quick_sort(array, left, party - 1);
		//Send in the upper half
		quick_sort(array, party + 1, right);
	}


}

int partition(int array[], int left, int right) {
	int pivot = array[right];
	int pIndex = left;
	int i = left;
	while (i < right) {
		if (array[i] <= pivot) {
			swap_val(&array[i], &array[pIndex]);
			pIndex++;
		}
		i++;
	}
	swap_val(&array[right], &array[pIndex]);
	return pIndex;
	
}





























































