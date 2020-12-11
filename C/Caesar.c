#include <stdio.h>
#include <stdlib.h>
#define MAX_LEN 0xffff

void caesarShift (int shift, char *s) {
    char temp = 0;
    for (int i = 0; s[i] != '\0'; i +=1) {
        if (s[i] != ' ') {
            temp = (s[i] - 'a') + shift;
            //Check for wrapping
            temp = temp % 26;
            s[i] = 'a' + temp;
        }
    }
}

int main () {

    char s[MAX_LEN] = {'\0'};
    int shift = 0;
    printf("Enter a string: ");
    int c = 0;
    int i = 0;
    while (( c = fgetc(stdin) ) != EOF && c != '\n') {
        s[i] = c;
        i +=1;
    }
        printf("Enter a shift: ");
        scanf("%d", &shift);
        caesarShift(shift, s);
        printf("Result: %s\n", s);
       // printf("Enter a string: ");

}