#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define MAX_UPPER_32INT 0x7FFFFFFF
#define MAX_LOWER_32INT -2147483648

long reverse_num (void) {
    printf("Enter a 32bit signed integer: ");
    long myNum = 0;
    scanf("%ld", &myNum);
    long reverseNum = 0;
    int isNegative = 0;

    if (myNum < 0) {
        isNegative = 1;
        myNum *=(-1);
    }

    while (myNum > 0) {
        reverseNum *=10;
        reverseNum +=(myNum % 10);
        myNum /=10;
    }
    if (isNegative) {
        reverseNum *=(-1);
    }
    if (reverseNum > MAX_UPPER_32INT || reverseNum < MAX_LOWER_32INT) {
        return 0;
    }
    return myNum;
}

int main () {
    reverse_num();
}








