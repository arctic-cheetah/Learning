#include <stdio.h>


int main() {
    int myNum;
    printf("Enter a year: ");
    scanf("%d", &myNum);

    if (myNum % 4 == 0) {
        if (myNum % 100 == 0) {
            if (myNum % 400 == 0) {
                printf("%d is a leap year", myNum);
            }
            else {
                printf("%d is not a leap year", myNum);
            }
        }
        else {
            printf("%d is not a leap year", myNum);
        }

    }
    else {
       printf("%d is not a leap year", myNum); 
    }
    /*
    if (myNum % 4 != 0) {
        printf("%d is not a leap year", myNum);
    }
    else if (myNum % 100 != 0) {
        printf("%d is a leap year", myNum);
    }
    else if (myNum % 400 != 0) {
        printf("%d is not a leap year", myNum);
    }
    else {
        printf("%d is a leap year", myNum);
    }
    */
}








