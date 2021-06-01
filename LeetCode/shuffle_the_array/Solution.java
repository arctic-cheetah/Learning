class Solution {
    public int[] shuffle(int[] nums, int n) {
        int[] shuffle_arr = new int[2*n];
        int arr_max = 2*n;
        
        int x = 0;
        int y = n;
        
        for (int i = 0; i < arr_max; i +=1) {
            shuffle_arr[i] = nums[x];
            x +=1;
            i +=1;
            shuffle_arr[i] = nums[y];
            y +=1;
            
        }
        return shuffle_arr;
    }
}