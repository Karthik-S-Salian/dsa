class Solution:
    def removeElement(self, nums, val: int) -> int:
        
        last = len(nums)-1
        if(last<0):
            return 0
        first =0

        while(first<=last):
            if(nums[first]==val):
                nums[last],nums[first]= nums[first],nums[last]
                last-=1
            else:
                first+=1
    
        return first