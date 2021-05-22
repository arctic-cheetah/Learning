#include <stdio.h>
#include <stdlib.h>
#define MAX_LEN 0xff

void helperReverseString(char *s, int left, int right, int count, int maxTimes) {
    //check if left or right has passed mid
    //recursive case
    if ( count < maxTimes ) {
        char temp = s[left];
        s[left] = s[right];
        s[right] = temp;
        helperReverseString(s, left + 1, right - 1, count+=1, maxTimes);
    }
    return;
}

void reverseString(char *s, int sSize){
        helperReverseString(s, 0, sSize - 1, 0, sSize / 2);   
}

int main (){
    int l = 0;
    char c[MAX_LEN] = {0};
    printf("Enter the size of the word: ");
    scanf("%d", &l);
    printf("Enter a word: ");
    scanf("%s", c);


    reverseString(c, l);
    printf("%s\n", c);
}
