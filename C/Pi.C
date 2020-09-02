//Prints the first n digits of pi, where n is specified 
// by the user

#include <stdio.h>

#define MAX_DIGITS 10
#define PI 3.1415

int main(void) {
    int pi[MAX_DIGITS] = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3};
    printf("How many digits of pi would you like to print? ");
    //TODO: Insert your code here
    int value = 0;
    scanf("%d", &value);

    int i = 0;
    while (i < value) {
        
        if (i == 1) {
            printf(".");
        }
        printf("%d", pi[i]);

        i++;
    }
    printf("%d \n", PI);

    return 0;
}


