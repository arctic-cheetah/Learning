#include <iostream>
using namespace std;

#define MAX_LENGTH 7

void print_array(int array[]);
void merge_sort(int array[], int left, int right);
void merge(int array[], int left, int mid, int right);

int main () {
	int array[MAX_LENGTH];
	
	cout << "Enter " << MAX_LENGTH << " numbers: ";
	for (int i = 0; i < MAX_LENGTH; i++) {
		cin >> array[i];
	}
	merge_sort(array, 0, MAX_LENGTH - 1);
	
	print_array(array);

	return 0;
}


void print_array(int array[]) {
	for (int i = 0; i < MAX_LENGTH; i++) {
		cout << array[i] << " ";
	}
	printf("\n");
}

void merge_sort(int array[], int left, int right) {
	if (left < right) {
		int mid = left + ( (right - left) / 2 );
		//Consider the left half
		merge_sort(array, left, mid);
		//Consider the right half
		merge_sort(array, mid + 1, right);
		//Merge the sub-arrays
		merge(array, left, mid, right);
	}
	
}

void merge(int array[], int left, int mid, int right) {
	int i = 0;
	int j = mid + 1;
	int k = 0;
	int temp[MAX_LENGTH];
	
	while (i <= mid && j <= right) {
		if (array[i] <= array[j]) {
			temp[k] = array[i];
			i++;
			k++;
		} 
		else {
			temp[k] = array[j];
			j++;
			k++;
		}
		
	}
	//Fill the temp array with the remaining elements from each sub-array
	while (j <= right) {
		temp[k] = array[j];
		j++;
		k++;
	}
	while (i <= mid) {
		temp[k] = array[i];
		k++;
		i++;
	}
	print_array(temp);
	//Copy the temp array into the original
	for (int h = 0; h <= right; h++) {
		array[h] = temp[h];
	}

}







































