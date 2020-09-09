// Author: 
// Date: 
// UNSW Freefall assignment.

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SIZE 15
#define EMPTY 0
#define STONE 1

// TODO: Add any extra #defines here.

void printMap(int map[SIZE][SIZE], int playerX);

// TODO: Add any extra function prototypes here.

int main (void) {
    // This line creates our 2D array called "map" and sets all
    // of the blocks in the map to EMPTY.
    int map[SIZE][SIZE] = {EMPTY};

    // This line creates out playerX variable. The player starts in the
    // middle of the map, at position 7.
    int playerX = SIZE / 2;

    printf("How many lines of stone? ");
    // TODO: Scan in the number of lines of blocks.


    printf("Enter lines of stone:\n");
    // TODO: Scan in the lines of blocks.


    printMap(map, playerX);

    // TODO: Scan in commands until EOF.
    // After each command is processed, you should call printMap.pr


    return 0;
}

// Print out the contents of the map array. Then print out the player line
// which will depends on the playerX variable.
void printMap(int map[SIZE][SIZE], int playerX) {
    
    // Print values from the map array.
    int i = 0;
    while (i < SIZE) {
        int j = 0;
        while (j < SIZE) {
            printf("%d ", map[i][j]);
            j++;
        }
        printf("\n");
        i++;
    }    
    
    // Print the player line.
    i = 0;
    while (i < playerX) {
        printf("  ");
        i++;
    }
    printf("P\n");
}






int j = 0;
while (j < Number_of_Lines) {
		scanf("%d", &THIS SPECIFIES THE ROW);
		scanf("%d", &LENGTH OF STONES);
		int i = 0;
		while (i <  LENGTH OF STONES) {
			map[THIS SPECIFIES THE ROW][i] = 1;
			i++;
		}
		j++;
	}











int row = 0;
int column = 0;
int stones = 0;


while ( scanf("%d", &Row) != EOF ) {

	scanf("%d", &Column);
	scanf("%d", &Stones);
	scanf("%d", &Value);

}


















