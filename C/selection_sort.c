// C program for implementation of selection sort 
#include <stdio.h> 
  
void swap (int *ap, int *bp) {
	int temp = *ap;
	*ap = *bp;
	*bp = temp;
}

void selectionSort (int array[], int length) {
	int min = array[0];
	int sorted = 0;
	int unsorted = 0;
	//Move by one index in sorted sub array
	while (sorted < length - 1) {
		min = sorted;
		unsorted = sorted + 1;
		//Find minimum element in unsorted array
		while (unsorted < length) {
			if (array[unsorted] < array[min]) {
				min = unsorted;
			}
			unsorted++;
		}
		//swap the values;
		swap (&array[min], &array[sorted]);
		sorted++;
	}
}


/* Function to print an array */
void printArray(int arr[], int size) 
{ 
    int i; 
    for (i=0; i < size; i++) 
        printf("%d ", arr[i]); 
    printf("\n"); 
} 
  
// Driver program to test above functions 
int main() 
{ 
    int arr[] = {64, 25, 12, 22, 11}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    selectionSort(arr, n); 
    printf("Sorted array: \n"); 
    printArray(arr, n); 
    return 0; 
} 
