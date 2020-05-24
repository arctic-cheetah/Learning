//An improved code for the implementation of heaps
//https://www.youtube.com/watch?v=Q_eia3jC9Ts&list=PLdo5W4Nhv31bbKJzrsKfMpo_grxuLl8LU&index=104&t=0s

#include <stdio.h>
#include <stdlib.h>

#define MAX_LENGTH 128

void print_array(int *array, int arraySize);
void print_heap(int *array, int arraySize, int level, int index);
void swap(int *a, int *b);
void max_heapify(int *array, int nth, int i);
void max_heapsort(int *array, int arraySize);
void min_heapify(int *array, int nth, int i);
void min_heapsort(int *array, int arraySize);

void max_insert(int *array, int data, int arraySize);
void min_insert (int *array, int data, int arraySize);
void max_delete_element(int *array, int *arraySize);
void min_delete_element(int *array, int *arraySize);




//Main function down here!
int main () {
	int array[MAX_LENGTH] = {8, 47, 72, 58, 69, 43, 21, 89, 12, 31, 5};
	int arraySize = 10;
	print_array(array, arraySize);
	
	printf("Sorted in a max-heap style:\n");
	max_heapsort(array, arraySize);
	print_array(array, arraySize);
	print_heap(array, arraySize, 0, 0);
	printf("\n");
	/*
	printf("Sorted in a min-heap style:\n");
	min_heapsort(array, arraySize);
	print_array(array, arraySize);
	*/
	arraySize++;
	max_insert(array, 100, arraySize);
	max_heapsort(array, arraySize);
	print_array(array, arraySize);
	/*
	min_delete_element(array, &arraySize);
	print_array(array, arraySize);
	*/
	print_heap(array, arraySize, 0, 0);
	
}


//Helper functions
void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void print_array(int *array, int arraySize) {
	for (int i = 0; i <= arraySize; i++) {
		printf("%d ", array[i]);
	}
	printf("\n");
}
//Print out the heap
void print_heap(int *array, int arraySize, int level, int i) {
	if (level == 0) {
		level = 1;
	} 
	else {
		level = 2*i + 1;
	}
	while (i < level && i <= arraySize) {
		printf("%d ", array[i]);
		i++;
	}
	printf("\n");
	if (i <= arraySize) {
		print_heap(array, arraySize, level, i);
	}
}
//------------------------------------------------------------------------
void max_heapify (int *array, int nth, int i) {
	int largest = i;
	int l = 2*i + 1;
	int r = 2*i + 2;
	if (l < nth && array[l] > array[largest]) {
		largest = l;
	}
	if (r < nth && array[r] > array[largest]) {
		largest = r;
	}
	
	if (largest != i) {
		swap(&array[largest], &array[i]);
		max_heapify(array, nth, largest);
	}
	
}

void max_heapsort(int *array, int arraySize) {
	//Check if arraySize is odd
	if (arraySize % 2 == 1) {
		arraySize+=1;
	}
	for (int i = (arraySize / 2) - 1; i >= 0; i--) {
		max_heapify(array, arraySize, i);
	}
}
//------------------------------------------------------------------------

void min_heapify (int *array, int nth, int i) {
	int largest = i;
	int l = 2*i + 1;
	int r = 2*i + 2;
	
	if (l <= nth && array[l] < array[largest]) {
		largest = l;
	}
	if (r <= nth && array[r] < array[largest]) {
		largest = r;
	}
	
	if (largest != i) {
		swap(&array[largest], &array[i]);
		min_heapify(array, nth, largest);
	}
	
}

void min_heapsort(int *array, int arraySize) {
	//Check if arraySize is odd
	if (arraySize % 2 == 1) {
		arraySize+=1;
	}
	for (int i = (arraySize / 2) - 1; i >= 0; i--) {
		min_heapify(array, arraySize, i);
	}
}
//------------------------------------------------------------------------

//Insert's an element into the heap and sorts them by "max hierarchy"
void max_insert (int *array, int data, int arraySize) {
	array[arraySize] = data;
	max_heapsort(array, arraySize);
}

//Insert's an element into the heap and sorts their property of being "min hierarchy"
void min_insert (int *array, int data, int arraySize) {
	array[arraySize] = data;
	min_heapsort(array, arraySize);
}

//Delete an element and ensure they retain their property of being "max-hierarchy"
void max_delete_element(int *array, int *arraySize) {
	array[0] = array[*arraySize];
	int i = 0;
	*arraySize = *arraySize - 1;
	for (int i = (*arraySize / 2) - 1; i >= 0; i--) {
		max_heapify(array, *arraySize, i);
	}
}
void min_delete_element(int *array, int *arraySize) {
	array[0] = array[*arraySize];
	int i = 0;
	*arraySize = *arraySize - 1;
	for (int i = (*arraySize / 2) - 1; i >= 0; i--) {
		min_heapify(array, *arraySize, i);
	}
}













































