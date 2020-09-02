/* A Problem to search the substring EAT from brilliant.org
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    char myString[] = "EATAUDRYBERNITAEATVIVANBROOKSEATJENIEATMICHALELASANDRALATIAEATLIDIAEATDEANDRAEATSYBILEATMONROEEATLATRISHAALTAEATDERICKROSANNLEVILIBBYKIRSTENCHARLESEATELLYNEATJANEEEATSTASIAEATJULIETTARANDIEATNORBERTSAGEEATARACELIKATINAMERNAEATISAIASWINNIEEATARLETHAEATMILOCAMIEEATANNABELEATLEANORABERTHASYBLECHANAEATREAGANERICKVALENTINAEATDORETHEASEBASTIANKRISROBERTAEATIVONNEEAT";
    char check[4] = "EAT";
    int wordCount = 0;
    int myLength = strlen(myString) - 1;
    int wordCheckLength = strlen(check) - 1;
    printf("String Length %d \n", myLength);
    printf("Check String Length %d \n", wordCheckLength);

    int i = 0;

    
   /*
    while (i < myLength) {
        if (check[0] == myString[i]) {
            if (check[1] == myString[i + 1]) {
                if (check[2] == myString[i + 2]) {
                    wordCount++;
                }
            }
        }
        i++;
    }
    */
    while (i < myLength) {
        if (check[0] == myString[i]) {
            int j = i + 1;
            int k = 1;
            int Match = 1;
            int InsideMatch = i + wordCheckLength + 1;
            while (j < InsideMatch && Match == 1) {
                //printf("%c.....%c \n", myString[j], check[k]);
                if (check[k] == myString[j]) {
                    Match = 1;
                } 
                else {
                    Match = 0;
                    break;
                }
                k++;
                j++;
            }
            if (Match == 1) {
                wordCount++;
            }
        }
        i++;
    }

    printf("There are %d subwords\n", wordCount);




}



























































