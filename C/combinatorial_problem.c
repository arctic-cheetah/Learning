#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 8

void print_array(char *array) {
    for (int i = 0; i < MAX_LEN; i +=1) {
        printf("%c, ", array[i]);
    }
    printf("\n");
}

int main () {
    char array[] = {'_','_','_','_' ,'_','_','_','_', '\0'};
    //Need to include null terminator
    char *comb = malloc((MAX_LEN + 1) * sizeof(char));
    char *comb2 = malloc((MAX_LEN + 1) * sizeof(char));
    char *comb3 = malloc((MAX_LEN + 1) * sizeof(char));

    int combinations = 0;
    for (int i = 0; i < MAX_LEN - 2; i +=1) {
        comb = strcpy(comb, array);
        comb[i] = 'A';
        for (int j = i + 1; j < MAX_LEN - 1; j +=1) {
            comb2 = strcpy(comb2, comb);
            comb2[j] = 'B';
            for (int k = j + 1; k < MAX_LEN; k +=1) {
                comb3 = strcpy(comb3, comb2);
                comb3[k] = 'C';
                combinations +=1;
                printf("%d) ", combinations);
                print_array(comb3);
            }
        }
    }
    free(comb);
    free(comb2);
    free(comb3);

    printf("The number of ways that A comes before B and B comes before C is: %d \n", combinations);
    printf("Now multiply that with the number of ways to arrange the other objects which is 5!\n");
    printf("That equals: %d\n", combinations * 120);
    printf("The probability for this question is now: 5! * 56 / (8!)");
}