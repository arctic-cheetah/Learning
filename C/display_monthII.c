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


char *display_month (int val) {
	char *month;
	switch (val) {
	case 1:
		  month = "January"; break;
	case 2:
		  month = "February"; break;
	case 3:
		  month = "March"; break;
	case 4:
		  month = "April"; break;
	case 5:
		  month = "May"; break;
	case 6:
		  month = "June"; break;
	case 7:
		  month = "July"; break;
	case 8:
		  month =   "August"; break;
	case 9:
		  month =   "September"; break;
	case 10:
		  month =   "October"; break;
	case 11:
		  month =   "November"; break;
	default:
		  month =   "December"; break;
	}
	
	return month;
}

void print_array (char *array, int length) {
	for (int i = 0; i < length; i++) {
		printf("%c", array[i]);
	}
	printf("\n");
}

int main () {
	int monthNum;
	printf("Enter a number: ");
	scanf("%d", &monthNum);
	
	printf("The month is ");
	printf("%s \n", display_month(monthNum) );
}








































