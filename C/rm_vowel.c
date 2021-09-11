#include <stdio.h>

int main (int argc, char *argv[]) {

    //Objective: print the all inputs from argv
    int i = 0;
    //Reading each char
    while ((i = getchar()) != EOF) {
        if (i == 'a' || i == 'e' || i == 'i' || i == 'o' || i == 'u') {
            putchar('*');
        }
        else {
            putchar(i);
        }
    }

    return 0;
}
