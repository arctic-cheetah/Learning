//A program that inputs a number and displays a month
#include <stdio.h>
#include <string.h>
	
#define MAX_LENGTH 20

int string_to_array (char *array, char *month) {
	int i = 0;
	int month_length = strlen(month);
	while (i < month_length) {
		array[i] = month[i];	
		i++;
	}
	return month_length;
}

int display_month (char *month, int val) {
	int month_length;
	switch (val) {
	case 1:
		month_length = string_to_array(month, "January"); break;
	case 2:
		month_length = string_to_array(month, "February"); break;
	case 3:
		month_length = string_to_array(month, "March"); break;
	case 4:
		month_length = string_to_array(month, "April"); break;
	case 5:
		month_length = string_to_array(month, "May"); break;
	case 6:
		month_length = string_to_array(month, "June"); break;
	case 7:
		month_length = string_to_array(month, "July"); break;
	case 8:
		month_length = string_to_array(month, "August"); break;
	case 9:
		month_length = string_to_array(month, "September"); break;
	case 10:
		month_length = string_to_array(month, "October"); break;
	case 11:
		month_length = string_to_array(month, "November"); break;
	default:
		month_length = string_to_array(month, "December"); break;
	}
	
	return month_length;
}


void print_array (char *array, int length) {
	for (int i = 0; i < length; i++) {
		printf("%c", array[i]);
	}
	printf("\n");
}

int main () {
	char month[MAX_LENGTH];
	int monthNum;
	printf("Enter a number: ");
	scanf("%d", &monthNum);
	
	int length = display_month(month, monthNum);
	printf("The month is ");
	print_array(month, length);
}








































