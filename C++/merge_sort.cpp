#include <iostream>
using namespace std;

#define MAX_LENGTH 6

int merge(int array[MAX_LENGTH], int mid, int left, int right);
int merge_sort(int array[MAX_LENGTH], int left, int right);
int swap_val(int *a, int *b);
void print_array (int array[]);

int main () {
	
	int array[MAX_LENGTH];
	
	cout << "Enter an array of length " << MAX_LENGTH << ": ";
	for (int i = 0; i < MAX_LENGTH; i++) {
		cin >> array[i];
	}
	int left = 0;
	int right = MAX_LENGTH - 1;
	
	merge_sort(array, left, right);
	
	
	print_array(array);
	return 0;
}

int swap_val(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void print_array (int array[]) {
	for (int i = 0; i < MAX_LENGTH; i++) {
		cout << array[i] << " ";
	}
	printf("\n");
}

int merge(int array[MAX_LENGTH], int mid, int left, int right) {
	int i = left;
	int j = mid + 1;
	int k = left;
	int temp[MAX_LENGTH];
	//The loop will cease once we trespass any sub array 
	while (i <= mid && j <= right) {
		if (array[i] <= array[j]) {
			temp[k] = array[i];
			k++;
			i++;
		}else{
			temp[k] = array[j];
			k++;
			j++;
		}
	}
	//Copy the remaining elements into temp since the sub arrays have been sorted
	//It will be guaranteed that the temp array will also be sorted
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
	
	print_array(temp);
	
	//Copy the elements from temp into array
	for (int h = 0; h <= right; h++) {
		array[h] = temp[h];
	}

}
int merge_sort(int array[MAX_LENGTH], int left, int right) {
	if (left < right) {
		int mid = left + ( (right - left) / 2 );
		//Send in the left half
		merge_sort(array, left, mid);
		//Send in the right half
		merge_sort(array, mid + 1, right);
		//merge the sub-arrays
		merge(array, mid, left, right);
	}
	return 0;
}










































