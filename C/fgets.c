#include <stdio.h>

//Argument counter :argc : track number inputs

//Argument vector :
//Name of file --> 0
//Hello --> 1
//world --> 2
//jeremy --> 3

//4 inputs

//2D array
int main (int argc, char *argv[]) {

    //Objective: print the all inputs from argv
    
    int i = 0;
    while ( i < argc) {
        printf("%s\n", argv[i]);
        i +=1;
    }
    

    return 0;
}