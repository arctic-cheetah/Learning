#include <iostream>
using namespace std;

#define MAX_LENGTH 6

void swap_val (int *a, int *b);
void print_array(int array[]);
void insertion_sort(int array[]);

int main () {
	int array[MAX_LENGTH];
	
	cout << "Enter " << MAX_LENGTH << " numbers: ";
	for (int i = 0; i < MAX_LENGTH; i++) {
		cin >> array[i];
	}
	
	insertion_sort(array);
	print_array(array); 

	return 0;
}


void swap_val (int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void print_array(int array[]) {
	for (int i = 0; i < MAX_LENGTH; i++) {
		cout << array[i] << " ";
	}
	printf("\n");
}
void insertion_sort(int array[]) {
	int i = 0;
	while (i < MAX_LENGTH) {
		int j = i;
		while (j > 0 && array[j - 1] > array[j]) {
			swap_val(&array[j], &array[j - 1]);
			j--;
		}
		i++;
	}
	
	
}

















































