//Code for the implementation of heaps
//https://www.youtube.com/watch?v=Q_eia3jC9Ts&list=PLdo5W4Nhv31bbKJzrsKfMpo_grxuLl8LU&index=104&t=0s


#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_LENGTH 100

int arraySize = 0;

void swap (int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}


//Helper function to print array
void print_array(int *array) {
	for(int i = 0; i <= arraySize ; i++) {
		printf("%d ", array[i]);
	}
	printf("\n");
}

//Insert's a heap
void insert_heap(int *array, int value) {
	arraySize++;
	int currSize = arraySize;
	array[arraySize] = value;
	int parent = (currSize - 1) / 2;
	
	while (parent >= 0) {
		if (array[parent] < array[currSize]) {
			swap(&array[parent], &array[currSize]);
		}
		else {
			return;
		}
		currSize = parent;
		parent = (parent - 1) / 2;
		//Consider the case if we need to check the value of the parent but
		//parent is a negative number
		if (parent < 0) {
			parent = 0;
		}
	}
}

//Delete a node in the heap
void delete_node(int *array) {
	array[0] = array[arraySize];
	array[arraySize] = 0;
	int i = 0;
	while (i <= arraySize) {
		int l = 2*i + 1;
		int r = 2*i + 2;
		if (array[l] > array[r]) {
			swap(&array[l], &array[i]);
			i = l;
		}
		else {
			swap(&array[r], &array[i]);
			i = r;
		}
	}
	arraySize--;
}

void max_heapify(int *array, int n, int i) {
	int largest = i;
	int l = 2*i + 1;
	int r = 2*i + 2;
	
	while (l <= n && array[l] > array[largest]) {
		largest = l;
	}
	while (r <= n && array[r] > array[largest]) {
		largest = r;
	}
	if (largest != i) {
		swap(&array[largest], &array[i]);
		max_heapify(array, n, largest);
	}
}
//Algorithm that organises an array by "heap" style
void heap_sort(int *array, int n) {
	for(int i = (n / 2) - 1; i >= 0; i--) {
		max_heapify(array, n, i);
	}
}


int main () {
	
	int array[MAX_LENGTH] = {31, 2, 4, 65, 3, 8, 88};
	/*
	array[0] = 15;
	array[1] = 5;
	array[2] = 20;
	array[3] = 1;
	array[4] = 17;
	array[5] = 10;
	array[6] = 30;
	*/
	arraySize = 6;
	print_array(array);
	/*
	array[0] = 80;
	array[1] = 75;
	array[2] = 55;
	array[3] = 54;
	array[4] = 20;
	array[5] = 40;
	array[6] = 33;
	arraySize = 6;
	print_array(array);
	
	insert_heap(array, 99);
	print_array(array);
	
	delete_node(array);
	print_array(array);
	*/
	
	heap_sort(array, arraySize);
	print_array(array);
	
	
	
}






























































