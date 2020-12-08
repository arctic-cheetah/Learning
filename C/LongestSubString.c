#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//A helper function that returns true if the char has been repeated in the buffer
//Otherwise false
int isInBuff(char *buff, char c, int len) {
    for (int i = 0; i < len; i +=1) {
        if (buff[i] == c) {
            return 1;
        }
    }
    return 0;
}

int main (int argc, char **argv) {
    if (argc != 2) {
        printf("Incorrect number of arguments");
        exit(1);
    }
    
    int len = strlen(argv[1]);
    char *buff = calloc(len, sizeof(char));
    int buffLen1 = 0;
    int longest = 0;
    for (int i = 0; i < len; i +=1) {
        if (!isInBuff(buff, argv[1][i], buffLen1)) {
            buff[buffLen1] = argv[1][i];
            buffLen1 +=1;
        }
        //There's a repeated character in the buffer
        //Reset the buffer
        else {
            if (longest < buffLen1) {
                longest = buffLen1;
            }
            buffLen1 = 0;
        }
    }
    printf("The longest substring length is: %d\n", longest);
    
}

