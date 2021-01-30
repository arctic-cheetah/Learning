//A program that reads in a folder, and removes all special characters 
//and replaces them with an underscore or hyphen
//This program assumes that a file extension exists
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <ctype.h>

#define MAX_LEN 0xffff

//A function that gets the index of the last '.' for the file extension
int lastDotFileExtension (char *s) {
    int i = strlen(s);
    while (i > 0 && s[i] != ':') {
         i -=1;
    }
    return i;
}

//A function that replaces the special character
void replaceSpecialChar(DIR *d, char *parent, char replacement) {
    struct dirent *curr;
    while ((curr = readdir(d)) != NULL) {
        //Fetch the path of the file;
        char *currPath = calloc(MAX_LEN, sizeof(char));
        currPath = strcpy(currPath, parent);
        currPath = strcat(currPath, curr->d_name);

        //Fetch the position of dot of the file extension
        int lastDot = lastDotFileExtension(curr->d_name);
        char *renamedFile = calloc(MAX_LEN, sizeof(char));
        renamedFile = strcpy(renamedFile, curr->d_name);
        int i = 0;
        while (i < lastDot) {
            //Check for special characters
            if (!isalpha( (int)renamedFile[i] ) ) {
                //replace with desired characters
                renamedFile[i] = replacement;
            }
            i +=1;
        }
        char *newPath = calloc(MAX_LEN, sizeof(char) );
        newPath = strcpy(newPath, parent);
        //Construct a path with the new file name
        newPath = strcat(newPath, renamedFile);

        //Rename the file
        rename(currPath, newPath);

        //Free extra memory
        free(currPath);
        free(newPath);
        free(renamedFile);
    }
    free(parent);
}

//A function that reads a directory of files
int main (int argc, char **argv) {
    if (argc != 2) {
        printf("Incorrect number of arguments");
        exit(1);
    }
    //Fetch the directory pointer
    DIR *d = opendir(argv[1]);
    if (!d) {
        printf("Not a directory");
        exit(1);
    }
    
    //Change the replacement character here.
    char *parent = calloc(MAX_LEN, sizeof(char) );
    replaceSpecialChar(d, strcat(strcpy(parent, argv[1]), "/"), '_' );
    closedir(d);
}
