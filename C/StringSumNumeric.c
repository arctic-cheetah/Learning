#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_LEN 0xffff

int main () {
    printf("Enter a string: ");
    char s[MAX_LEN];
    scanf("%s", s);
    //Get the length of the string
    int len = strlen(s);
    int sum = 0;
    for (int i = 0; i < len; i +=1) {
        if ('0' <= s[i] && s[i] <= '9') {
            printf("%c", s[i]);
            sum += (s[i] - '0');
        }
    }
    printf("The sum is %d\n", sum);
}