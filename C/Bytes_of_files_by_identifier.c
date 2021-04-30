//A C program that finds the total size of a group of files
//By a file extension
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>

#define MAX_LEN 0xFFFF

//Checks if the file matches the extension name
int file_match_extn(char *fileName, char *fileExt) {

    //Get to the last '.'
    int i = strlen(fileName);
    while (i > 0 && fileName[i] != '.') {
        i -=1;
    }
    if (i == 0) {
        return 0;
    }
    //Exclude the parent directory
    if (fileName[i - 1] == '.') {
        return 0;
    }
    //Check the file extension
    int j = 0;
    while (fileName[i] != 0) {
        //file Extension is different
        if (fileName[i] != fileExt[j]) {
            return 0;
        }
        j +=1;
        i +=1;
    }
    //File extension is the same, 
    //because it stopped at the null terminator
    return 1;
}

int main () {
    char *fileExt = calloc(MAX_LEN, sizeof(char));
    printf("Enter a file extension: ");
    scanf("%s", fileExt);

    char *dirPath = calloc(MAX_LEN, sizeof(char));
    printf("Enter a directory: ");
    scanf("%s", dirPath);

    DIR *currDir = opendir(dirPath);
    if (!currDir) {
        perror("");
        exit(1);
    }
    struct dirent *dir;
    double fileSize = 0;

    //Read files in the current directory
    while ((dir = readdir(currDir)) != NULL) {
        //skip the parent directory

        //Get the size of the file
        if (file_match_extn(dir->d_name, fileExt)){
            struct stat currFile;
            if (stat(dir->d_name, &currFile) == -1) {
                perror("");
                exit(1);
            }
            fileSize += (double)currFile.st_size;
        }

    }
    
    printf("The size of %s files is: %lf\n", fileExt, fileSize);
    closedir(currDir);

    free(dirPath);
    free(fileExt);
}







