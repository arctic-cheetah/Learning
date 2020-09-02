
#include <stdio.h>
#include <string.h>
#include <math.h>
#define NOT_POSITIVE 0
#define SIZE 18
/*
int array_check (int size, int *array);

int main () {
    
    int array[SIZE] = {-10, 20, 30, -40, 50};

    printf("The value is: %d \n", array_check(SIZE, array) );
}

int array_check (int size, int *array) {

    int i = 0;
    int posNum = 0;
    int secondPosInteger = 0;

    while (i < size) {
        if (array[i] > 0) {
            posNum++;
        }
        if (posNum == 2) {
            secondPosInteger = array[posNum];
        }

        i++;
    }

    if (posNum < 2) {
        return NOT_POSITIVE;
    }
    else {
        return secondPosInteger;
    }
}
*/

/*
int main () {

    int myNum;
    printf("Enter instruction: ");
    
    while (scanf("%d", &myNum) != EOF) {
        int Num1;
        int Num2;
        if (myNum == 1) {
        scanf("%d", &Num1);
        Num1 = Num1 * Num1;
        }
        else if (myNum == 2) {
            scanf("%d", &Num1);
            scanf("%d", &Num2);
            int tempNum = Num1;
            int i = 1;
            while (i < Num2) {
                Num1 = Num1 * tempNum;
                i++;
            }
        }
        
        printf("%d\n", Num1);
        printf("Enter instruction: ");
    }

}

*/
/*
int quaternary(int myNum) {

    for (int j = 0; j < 4; j++) {
        printf("%d", j);
        for (int i = 0; i < 4 ; i++) {
            if (i == j) {
                printf("%d\n", i);
            }
            
        }
    }
}


int main () {

    int Upper = 5;

    for (int j = 0; j < 4; j++) {
        printf("%d", j);
        for (int i = 0; i < 4 ; i++) {
            printf("%d\n", i);
        }
    }
    
    printf("End of sequence\n");
}
*/


int main () {

    char myString[] = "AJKMLNFDBKSTRUBJQAZWSQWERTYUIOPFUNASDFGHJKLXLKHJGFDSANUFPOIUYTREWQSWZAQJBURTSKBDFNLMKJA";
    int myLength = strlen(myString) - 1;
    int palindrome = 1;

    printf("%d\n", myLength);
    //printf("%c\n", myString[myLength - 1]);


    for (int i = 0; i <= myLength / 2; i++) {
        printf("%c .... %c\n", myString[i], myString[myLength - i]);
        if (myString[i] != myString[myLength - i]) {
            printf("The string is not palindromic!\n");
            palindrome = 0;
            break;
        }

    }

    if (palindrome == 1) {
        printf("The string is a palindrome!");
    }
}

































