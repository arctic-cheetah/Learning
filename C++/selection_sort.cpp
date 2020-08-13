#include <iostream>

using namespace std;

#define MAX_LENGTH 5

void swap_val (int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

int main () {
	
	int array[MAX_LENGTH];
	printf("Enter an array of numbers: ");
	for (int i = 0; i < MAX_LENGTH; i++) {
		scanf("%d", &array[i]);
	}
	
	
	int min_index;
	for (int i = 0; i < MAX_LENGTH; i++) {
		min_index = i;
		for (int k = i + 1; k < MAX_LENGTH; k++) {
			if (array[i] > array[k]) {
				min_index = k;
			}
		}
		swap_val(&array[min_index], &array[i]);
	}
	
	for (int i = 0; i < MAX_LENGTH; i++) {
		printf("%d ", array[i]);
	}
	printf("\n");

	return 0;
}








































