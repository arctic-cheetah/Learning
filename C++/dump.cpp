#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int size;

void swap(int *a, int *b);
void selection_sort(int array[]);
void print_array(int array[]);

int main () {
	cout << "Enter the size of the array: ";
	cin >> size;
	
	int array[size];
	cout << "Enter the elements of the array: ";
	for (int i = 0; i < size; i++) {
		cin >> array[i];
	}
	
	selection_sort(array);
	
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

void selection_sort(int array[]) {
	int i = 0;
	int min_idx = i;
	while (i < size) {
		min_idx = i;
		int j = i + 1;
		while (j < size) {
			if (array[j] <= array[min_idx]) {
				min_idx = j;
			}
			j++;
		}
		swap(&array[min_idx], &array[i]);
		i++;
	}
	
}
















































