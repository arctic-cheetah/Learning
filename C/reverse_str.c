#include <stdio.h>

#define MAX_CHAR_NUM 80


int main () {

    //---------------------------------------------
    //Pseudocode---algorithm
    //Read input string until we reach '\n'
    //EOF

    //Put char into an array
    //Count str len

    //Hello -->is in the array
    //01234

    //Reverse the string
    //Need a counter (i >= 0)
    //i -=1;
    //----------------------------------------------

    //store the string
    int buffer[MAX_CHAR_NUM];
    int i = 0;
    //Read each char
    while ((i = getchar()) != EOF) {
        
        //Store string
        int counter = 0;
        while (i != '\n') {
            buffer[counter] = i;
            i = getchar();
            counter +=1;
        }

        //Reverse string and print
        while (counter >= 0) {
            putchar(buffer[counter]);
            counter -=1;
        }
        putchar('\n');

    }

    return 0;
}

