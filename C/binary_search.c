//A program that illustrates a recursive binary search
#include <stdio.h>

#define MAX_LENGTH 20

int binary_search(int v, int *array, int lo, int hi) {

	int mid = hi - (hi - lo) / 2;
	int result;
	if (lo > hi) {
		return 0;
	}
	
	if (array[mid] == v) {
		return array[mid];
	}
	else if (v > array[mid]) {
		result = binary_search(v, array, mid + 1, hi);
	}
	else {
		result = binary_search(v, array, lo, mid - 1);
	}
	
	return result;
}



int main () {
	
	int array[MAX_LENGTH] = {1,
	2,
	3,
	4,
	5,
	6,
	7,
	8,
	9,
	10,
	11,
	12,
	13,
	14,
	15,
	16,
	17,
	18,
	19,
	20
	};
	
	printf("%d \n", binary_search(9, array, 0, MAX_LENGTH - 1)); 
	
}
























