//A program that reads a folder 
//and removes any special characters from the filename exclusind the 

#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>


#define MAX_LENGTH 0xffff

//A function that reads a file recursively
struct dirent getFile(DIR *d) {
	
	
	
}

int main () {
	//Begin from the relative base path
	DIR startDir = opendir("Serif");
	
	closedir(startDir);
}
