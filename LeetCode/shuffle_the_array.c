int* shuffle(int* nums, int numsSize, int n, int* returnSize){
    //Make array
    int *shuffled_array = (int *) calloc(2*n, sizeof(int));   
    
    //Get the size of the array
    int arr_size = 2*n;
    *returnSize = 2*n;
    //this will begin our y values
    
    int x = 0;
    int y = n;
    
    //At most O(n)
    for (int i = 0; i < arr_size; i +=1) {
        
        shuffled_array[i] = nums[x];
        //printf("%d ", shuffled_array[i]);
        x +=1;
        i +=1; //Go to next position
        shuffled_array[i] = nums[y];
        y +=1;
        //printf("%d ", shuffled_array[i]);
    }
    return shuffled_array;
    
}