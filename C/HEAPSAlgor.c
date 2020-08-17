//A program that lists all the possible permutations of a string using Heap's Algorithm.
//17/08/2020

#include <stdio.h>
#include <stdlib.h>
#define LENGTH 8

void printWord(char *String);
void Combinations(char *String, int Length);
void swap(char *String1, char *String2);
int Ways = 0;

int main() {

    char String[LENGTH] = "12345678";
    Combinations(String, LENGTH);
    
    printf("Ways are: %d\n", Ways);
}

void Combinations(char *String, int Length) {
    if (Length == 1) {
        printWord(String);
        Ways++;
    }
    else {
        for (int i = 0; i < Length; i++) {
            Combinations(String, Length - 1);
            if (Length % 2 == 0) {
                swap(&String[i], &String[Length - 1]);
            }
            else {
                swap(&String[0], &String[Length - 1]);
            }
        }
    }
}

void swap(char *String1, char *String2) {
    int temp = *String1;
    *String1 = *String2;
    *String2 = temp;
}

void printWord(char *String) {
    for (int i = 0; i < LENGTH; i++) {
        printf("%c", String[i]);
    }
    printf("\n");
}


/*
void Combinations(char *String, int iterator) {
    for (int i = iterator; i < LENGTH; i++) {
        int j = 65;
        while (j < 68) {
            String[i] = j;
            Combinations(String, i + 1);
            printWord(String);
            j++;
            Ways++;
        }
    }
    //printf("The number of ways was: %d\n", Ways);
}*/



















































































