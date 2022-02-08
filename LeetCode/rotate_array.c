#include <stdio.h>
//My helper function to calculate the gcd of two numbers
//Accepts only ints
//Uses the Euclidean Algorithm
//Assumes, a > b
int gcd(int a, int b) {
    int r = 1;
    while (r != 0) {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}


void rotate(int* nums, int numsSize, int k){
    
    //Perform modulo on k. Since, if k > numsSize. The rotation must wrap around.
    k = k % numsSize;
    
     //Need to check if numsSize is co-prime to k mod(k). 
    //Otherwise, multiple iterations to complete the modular cycle need to be performed
    
    int temp_1 = nums[0];
    int temp_2 = 0;
    //Starting from 0
    //add k to the index of the element and perform modulo.
    //Be sure to store the number in temp.
    
    //Here, k is always smaller than numsSize
    //Be careful if k = 0 !
    int modular_cycle = 1;
    if (k != 0) {
        modular_cycle = gcd(numsSize, k);
    }
    
    for (int cycle = 0; cycle < modular_cycle; cycle +=1) {
        int temp_1 = nums[cycle];
        int temp_2 = 0;
        int i = k + cycle;
        while (i != cycle) {
            temp_2 = nums[i];
            nums[i] = temp_1;
            temp_1 = temp_2;
            //Follow the index of the array that needs to be swapped. Until modulo is equal 0--The starting position
            //This is a modular arithmetic problem!
            i = (i+k) % numsSize;
        }
        nums[i] = temp_1;
    }
        
    
}