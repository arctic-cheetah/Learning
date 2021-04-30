#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int size_of_word(char *word);

//Find all b's that are a subset of a
char ** wordSubsets(char ** A, int ASize, char ** B, int BSize, int* returnSize){
    //The returned Array has a max size size of array A.
    
    //Check that every char in b, is a word in a
    bool is_word_A_universal = true;
    char **universal_array = (char **) malloc(sizeof(* universal_array) * ASize);
    int matched_words = 0;

    //Choose a word 'a' that is in A
    for (int i = 0; i < ASize; i +=1) {
        
        bool word_b_matches_word_a = true;  
            
            //Check if a word from 'B' is contained within a word from 'a'
            for (int k = 0; k < BSize && word_b_matches_word_a; k +=1) {
                
                int size_of_word_b = size_of_word(B[k]);
                int matched_char = 0;

                char *copy_word_a = malloc(sizeof(char) * 256);
                copy_word_a = strcpy(copy_word_a, A[i]);
                
                for (int l = 0; B[k][l] != '\0'; l +=1) {
                    char char_of_b = B[k][l];
                    //Go through the word 'a', and check that it contains the letters from b
                    for (int j = 0; copy_word_a[j] != '\0' && matched_char != size_of_word_b; j +=1) {
                        char char_of_a = copy_word_a[j];
                        if (char_of_a == char_of_b) {
                            copy_word_a[j] = '_';
                            matched_char +=1;
                            break;
                        }
                        
                    }
                }
                
                //word b is in word a, need to check that other words in B
                //are in a
                if (matched_char == size_of_word_b) {
                    word_b_matches_word_a = true;
                }
                //Matched words aren't equal
                //Ergo, a isn't a universal word
                else {
                    word_b_matches_word_a = false;
                    is_word_A_universal = false;
                }
                free(copy_word_a);
            }
        
        //Add the word only if a contains all the words from B
        if (is_word_A_universal) {
            universal_array[matched_words] = malloc( (size_of_word(A[i]) + 1) * sizeof(char));
            strcpy(universal_array[matched_words], A[i]);
            matched_words +=1;
        }
        //reset the question
        else {
            is_word_A_universal = true;
        }
        
    }
    *returnSize = matched_words;
    return universal_array;
}

//Return the size of the word
//Excluding the null character
int size_of_word(char *word){
    int i = 0;
    while (word[i] != '\0') {
         i +=1;
    }
    return i;
}





int main(){
    char* A[256] = {"amazon","apple","facebook","google","leetcode"};
    char* B[256] = {"leo","oeo"};
    int mynum = 0;
    char **test = wordSubsets(A, 5, B, 2, &mynum);
}