#include <iostream>

using namespace std;

#define MAX_LENGTH 10

void swap_val (int *a, int *b);
void print_array(int array[]);
void selection_sort(int array[]);

int main () {
	int array[MAX_LENGTH];
	cout << "Enter " << MAX_LENGTH << " numbers: ";
	for (int i = 0; i < MAX_LENGTH; i++) {
		cin >> array[i];
	}
	
	selection_sort(array);
	print_array(array);
	
	return 0;
}


void swap_val (int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void selection_sort(int array[]) {
	int i = 0;
	while (i < MAX_LENGTH) {
		int j = i;
		int min_idx = i;
		while (j < MAX_LENGTH) {
			if (array[min_idx] > array[j]) {
				min_idx = j;
			}
			j++;
		}
		swap_val(&array[min_idx], &array[i]);
		i++;
	}

}

void print_array(int array[]) {
	for (int i = 0; i < MAX_LENGTH; i++) {
		cout << array[i] << " ";
	}
	printf("\n");
}


























































