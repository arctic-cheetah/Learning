class Solution:
    def shuffle(self, nums: List[int], n: int) -> List[int]:
        arr = []
        i = 0
        x = 0
        y = n
        
        while (i < 2*n):
            arr.insert(i, nums[x])
            i +=1
            x +=1
            arr.insert(i, nums[y])
            y +=1
            i +=1
            
        return arr
        
        