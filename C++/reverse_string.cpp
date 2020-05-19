#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 64

void print_array(char array[]) {
	int k = 0;
	while (array[k] != '\0') {
		printf("%c", array[k]);
		k++;
	}
}

void string_reverse (char array[]) {
	if (*array != '\0') {
		string_reverse(array + 1);
		printf("%c", *array);
	}
}

int main () {
	char array[MAX_LENGTH];
	printf("Enter a string: ");
	fgets(array, MAX_LENGTH, stdin);
	printf("Before: ");
	print_array(array);
	printf("\n");
	printf("After: ");
	string_reverse(array);
	printf("\n");
	
	return 0;
}





























































