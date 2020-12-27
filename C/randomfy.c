//A program that randomises each byte
//After reading the file signature
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LEN 0xff
#define MAGIC_NUM 5

int main () {
	
	time_t t = 0;
	srand(time(&t));
	
	printf("Enter the file name: ");
	char *fileName = calloc(MAX_LEN, sizeof(char)); 
	scanf("%s", fileName);
	FILE *f = fopen(fileName, "r+");
	
	//Don't remove the file signature
	
	fseek(f, MAGIC_NUM, SEEK_SET);
	
	int c = rand();
	while (fputc(c, f) != NULL) {
		c = rand();
	}
	
	fclose(f);
}
