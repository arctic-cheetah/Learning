//A C program to copy a file
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_LEN 0xff

//Function declaration

int main () {
    char file[MAX_LEN] = "0";
    printf("Enter the path of the filename to copy: ");
    scanf("%s", file);
    FILE *fp = fopen(file, "r");

    //Append copy to the existing file name
    char *cp_file_name = calloc(sizeof(char), MAX_LEN);
    cp_file_name = memcpy(cp_file_name, file, MAX_LEN);
    strcat(cp_file_name, "_copy.c");
    FILE *cp_file = fopen(cp_file_name, "w");

    char c = 0;
    while ((c = fgetc(fp)) != EOF) {
        fputc(c, cp_file);
    }

    free(cp_file_name);
    fclose(fp);
    fclose(cp_file);
}

//Function 
//Does not return 