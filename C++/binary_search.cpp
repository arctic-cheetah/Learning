//My first errorsome binary search algorithm

#include <iostream>

using namespace std;

#define MAX_LENGTH 10

int binary_search (int array[], int myNum) {	
	int left = 0;
	int right = MAX_LENGTH - 1;
	int mid = (MAX_LENGTH - 1) / 2;
	
	while (left <= right) {
		
		if (array[mid] < myNum) {
			left = mid + 1;
			mid = (left + right) / 2;
		} 
		else if (array[mid] > myNum) {
			right = mid - 1;
			mid = (right - left) / 2;
		}
		else {
			return mid;
		}
	}
	
	return -1;
}

int main () {
	int array[MAX_LENGTH];
	int myNum;
	
	cout << "Enter an array in ascending order: ";
	for (int i = 0; i < MAX_LENGTH; i++) {
		cin >> array[i];
	}
	cout << "Enter a desired number: ";
	cin >> myNum;
	
	int check = binary_search(array, myNum);
	if (check == -1) {
		cout << "Number not found\n";
	}
	else {
		cout << "Number found at index position " << check << endl ;
	}
	return 0;
}














































