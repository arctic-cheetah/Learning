#include <iostream>

using namespace std;

#define MAX_LENGTH 10

void swap_val (int *a, int *b);
void bubble_sort (int array[]);
void print_array(int array[]);

int main () {
	
	int array[MAX_LENGTH];
	cout << "Enter " << MAX_LENGTH << " integers: ";
	for (int i = 0; i < MAX_LENGTH; i++) {
		cin >> array[i];
	}
	bubble_sort(array);
	print_array(array);
	

	return 0;
}

void swap_val (int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}


void bubble_sort (int array[]) {
	int upper = 0;
	bool ordered = 0;
	while (upper < MAX_LENGTH - 1 && ordered == 0) {
		int lower = 0;
		ordered = 1;
		while (lower < MAX_LENGTH - 1 - upper) {
			if (array[lower] > array[lower + 1]) {
				swap_val(&array[lower], &array[lower + 1]);
				ordered = 0;
			}
			lower++;
		}
		upper++;
	}
}

void print_array(int array[]) {
	for (int i = 0; i < MAX_LENGTH; i++) {
		cout << array[i] << " ";
	}
	printf("\n");
}





































