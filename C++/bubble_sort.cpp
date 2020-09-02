#include <iostream>

using namespace std;

#define MAX_LENGTH 6

void swap_val(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

int bubble_sort(int array[]) {
	
	int i = 0;
	while (i < MAX_LENGTH) {
		int j = 0;
		while (j < MAX_LENGTH - i - 1) {
			if (array[j] > array[j + 1]) {
				swap_val (&array[j], &array[j + 1]);
			}
			j++;
		}
		i++;
	}
	return 0;
}

int main () {
	int array[MAX_LENGTH];
	
	cout << "Enter an array with " << MAX_LENGTH << " elements :";
	for (int i = 0; i < MAX_LENGTH; i++) {
		cin >> array[i];
	}
	bubble_sort(array);
	
	for (int i = 0; i < MAX_LENGTH; i++) {
		cout << array[i] << " ";
	}
	printf("\n");

	return 0;
}


























































