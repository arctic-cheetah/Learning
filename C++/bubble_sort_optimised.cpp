#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int size;

void swap(int *a, int *b);
void bubble_sort(int array[]);
void print_array(int array[]);

int main () {
	cout << "Enter the size of the array: ";
	cin >> size;
	
	int array[size];
	cout << "Enter the elements of the array: ";
	for (int i = 0; i < size; i++) {
		cin >> array[i];
	}
	
	bubble_sort(array);
	
	print_array(array);

	return 0;
}

void print_array(int array[]) {
	for (int i = 0; i < size; i++) {
		cout << array[i] << " ";
	}
	printf("\n");
}	

void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void bubble_sort(int array[]) {
	int i = size - 1;
	bool ordered = 0;
	while (i > 0 && ordered == 0) {
		ordered == 1;
		int j = 0;
		while (j < i) {
			if (array[j] >= array[i]) {
				swap(&array[j], &array[i]);
				ordered = 0;
			}
			j++;
		}
		i--;
	}
	
}
















































