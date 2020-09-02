#include <iostream>
#include <string.h>

using namespace std;

#define MAX_LENGTH 1024

int main () {
	
	char word[MAX_LENGTH];
	printf("Enter a phrase: ");
	fgets(word, MAX_LENGTH, stdin);
	
	double Length = 0;
	int i = 0;
	while (word[i] != '\n') {
		if ( ('a' <= word[i] && word[i] <= 'z' ) 
		|| ( 'A' <= word[i] && word[i] <= 'Z' ) ) 
		{
			Length++;
		}
		i++;
	}
	
	int wordCount[25] = {0};
	
	for (int k = 0; word[k] != '\n'; k++) {
		if (word[k] == 'a' || word[k] == 'A') {
			wordCount[0]++;
		}
		else if (word[k] == 'b' || word[k] == 'B') {
			wordCount[1]++;
		}
		else if (word[k] == 'c' || word[k] == 'C') {
			wordCount[2]++;
		}
		else if (word[k] == 'd' || word[k] == 'D') {
			wordCount[3]++;
		}
		else if (word[k] == 'e' || word[k] == 'E') {
			wordCount[4]++;
		}
		else if (word[k] == 'f' || word[k] == 'F') {
			wordCount[5]++;
		}
		else if (word[k] == 'g' || word[k] == 'G') {
			wordCount[6]++;
		}
		else if (word[k] == 'h' || word[k] == 'H') {
			wordCount[7]++;
		}
		else if (word[k] == 'i' || word[k] == 'I') {
			wordCount[8]++;
		}
		else if (word[k] == 'j' || word[k] == 'J') {
			wordCount[9]++;
		}
		else if (word[k] == 'k' || word[k] == 'K') {
			wordCount[10]++;
		}
		else if (word[k] == 'l' || word[k] == 'L') {
			wordCount[11]++;
		}
		else if (word[k] == 'm' || word[k] == 'M') {
			wordCount[12]++;
		}
		else if (word[k] == 'n' || word[k] == 'N') {
			wordCount[13]++;
		}
		else if (word[k] == 'o' || word[k] == 'O') {
			wordCount[14]++;
		}
		else if (word[k] == 'p' || word[k] == 'P') {
			wordCount[15]++;
		}
		else if (word[k] == 'q' || word[k] == 'Q') {
			wordCount[16]++;
		}
		else if (word[k] == 'r' || word[k] == 'R') {
			wordCount[17]++;
		}
		else if (word[k] == 's' || word[k] == 'S') {
			wordCount[18]++;
		}
		else if (word[k] == 't' || word[k] == 'T') {
			wordCount[19]++;
		}
		else if (word[k] == 'u' || word[k] == 'U') {
			wordCount[20]++;
		}
		else if (word[k] == 'v' || word[k] == 'V') {
			wordCount[21]++;
		}
		else if (word[k] == 'w' || word[k] == 'W') {
			wordCount[22]++;
		}
		else if (word[k] == 'x' || word[k] == 'X') {
			wordCount[23]++;
		}
		else if (word[k] == 'y' || word[k] == 'Y') {
			wordCount[24]++;
		}
		else if (word[k] == 'z' || word[k] == 'Z') {
			wordCount[25]++;
		}
	}
	
	printf("The word frequency of each letter is: \n");
	int j = 0;
	while (j < 26) {
		printf("%c%c: %lf \n", j + 'a', j + 'A', wordCount[j] / Length);
		j++;
	}
	
	
	
	return 0;
}































































