#include <iostream>
#include <bits/stdc++.h>

using namespace std;
//Size of the array
int size;

void print_array(int array[]);
void merge(int array[], int left, int mid, int right);
void merge_sort(int array[], int left, int right);

int main () {
	cout << "Enter the size of the array: ";
	cin >> size;
	
	int array[size];
	cout << "Enter the elements of the array: ";
	for (int i = 0; i < size; i++) {
		cin >> array[i];
	}
	merge_sort(array, 0, size - 1);
	
	print_array(array);

}

void print_array(int array[]){
	for (int i = 0; i < size; i++) {
		cout << array[i] << " ";
	}
	printf("\n");
}

void merge_sort(int array[], int left, int right) {
	if (left < right) {
		int mid = left + ( (right - left)/2 );
		//merge_sort in the lower half
		merge_sort(array, left, mid);
		//merge_sort the upper half
		merge_sort(array, mid + 1, right);
		//Prepare for merging
		merge(array, left, mid, right);
	}

}

void merge(int array[], int left, int mid, int right) {
	int i = left;
	int j = mid + 1;
	int k = left;
	int temp[size];
	//merge the two sub-arrays
	while (i <= mid && j <= right) {
		if (array[i] <= array[j]) {
			temp[k] = array[i];	
			k++;
			i++;
		}
		else {
			temp[k] = array[j];	
			k++;
			j++;
		}
	}
	//add any remaining elements in the sub-array to the temp
	while (i <= mid) {
		temp[k] = array[i];	
		k++;
		i++;
	}
	while (j <= right) {
		temp[k] = array[j];	
		k++;
		j++;
	}
	
	for (int z = left; z <= right; z++) {
		array[z] = temp[z];
	}
}































































