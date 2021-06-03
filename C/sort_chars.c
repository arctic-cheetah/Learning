//A program that sorts characters via bubble sort
#include <stdio.h>
#include <stdlib.h>

void swap (char *a, char *b) {
    char temp = *a;
    *a = *b;
    *b = temp;

}

int main (int argc, char **argv) {
    if (argc != 2) {
        printf("Need to enter one argument");
        exit(0);
    }   
    printf("Unsorted %s \n", argv[1]);
    int j = 0; 
    for (int i = 0; argv[1][i] != '\0'; i +=1) {
        j = i; 
        int swapped = 0;
        while (argv[1][j] != '\0') {    
            if (argv[1][i] > argv[1][j]) {
                swap(&argv[1][i], &argv[1][j]);
                swapped +=1;    
            }     
            j +=1;
        }
        //Nothing has been swapped. Exit sorting
        if (!swapped) {
            break;
        }

    }
    printf("Sorted %s \n", argv[1]);

}
