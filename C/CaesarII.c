#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LEN 0xffff

void caesarShift (int shift, char *s) {
    char temp = 0;
    for (int i = 0; s[i] != '\0'; i +=1) {
        if (s[i] != ' ') {
            temp = (s[i] - 'a') + shift;
            //Check for wrapping
            temp = temp % 26;
            s[i] = temp + 'a';
        }
    }
}

int main () {

    char s[MAX_LEN] = {'\0'};
    printf("Enter a string: ");
    int c = 0;
    int i = 0;
    while (( c = fgetc(stdin) ) != EOF && c != '\n') {
        s[i] = c;
        i +=1;
    }
        for (int j = 0; j < 26; j +=1) {
            char *s2 = strdup(s);
            caesarShift(j, s2);
            printf("%d Result: %s\n", j, s2);
            free(s2);
        }
       // printf("Enter a string: ");

}