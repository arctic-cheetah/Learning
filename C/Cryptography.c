#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LENGTH 30


int main () {
    char panthas_message[LENGTH + 1] = "tkxhwbiscscu vfbmwlgzirlsnysqr";
    //char Alphabet[27] = "abcdefghijklmnopqrstuvwxyz";
    double AlphabetCount[26] = {0};
    int wordLen = strlen(panthas_message);
    printf("The length of the string is: %d \n", wordLen);

    int i = 0;
    while (i + 'a' <= 'z') {
        int j = 0;
        while (j < LENGTH) {
            if (i + 'a' == panthas_message[j]) {
                AlphabetCount[i]++;
            }
            j++;
        }
        i++;
    }
    i = 0;
    //int k = 0;
    printf("The letter distribution is: \n");
    while (i + 'a' <= 'z') {
        printf("%c : %lf \n", i + 'a', AlphabetCount[i]);
        i++;
    }

}










