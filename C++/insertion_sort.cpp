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
	int k = 0;
	while (k < MAX_LENGTH) {
		scanf("%d", &array[k]);
		k++;
	}
	
	for (int i = 0; i < MAX_LENGTH; i++) {
		int curr = i;
		while (curr > 0 && array[curr - 1] > array[curr]) {
			swap_val (&array[curr - 1], &array[curr]);
			curr--;
		}
	}
	
	
	int j = 0;
	while (j < MAX_LENGTH) {
		printf("%d ", array[j]);
		j++;
	}
	printf("\n");
	
	return 0;
}























