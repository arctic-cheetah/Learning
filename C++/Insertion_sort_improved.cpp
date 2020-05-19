#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int size;

void swap(int *a, int *b);
void insertion_sort(int array[]);
void print_array(int array[]);

int main () {
	cout << "Enter the size of the array: ";
	cin >> size;
	
	int array[size];
	cout << "Enter the elements of the array: ";
	for (int i = 0; i < size; i++) {
		cin >> array[i];
	}
	
	insertion_sort(array);
	
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

void insertion_sort(int array[]) {
	int i = 0;
	while (i < size) {
		int j = i + 1;
		while (j > 0 && array[j] < array[j - 1]) {
			swap(&array[j], &array[j - 1]);
			j--;
		}
		i++;
	}
	
}
















































