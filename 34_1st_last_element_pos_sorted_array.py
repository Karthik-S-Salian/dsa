class Solution:
    def searchRange(self, nums: list[int], target: int) -> list[int]:
        if len(nums)==0:
            return [-1,-1]
        start = 0
        end = len(nums)-1
        mid = 0
        while(start<=end):
            mid = (start+end)//2
            if nums[mid]==target:
                if mid>0 and nums[mid-1]!=target:
                    break
            if nums[mid]<target:
                start=mid+1
            else:
                end = mid-1

        if nums[mid]!=target:
            return [-1,-1]

        start = mid
        si= mid
        end = len(nums)-1

        while(start<=end):
            mid = (start+end)//2
            if nums[mid]>target:
                end = mid-1
            else:
                start=mid+1

        return si,mid if nums[mid]==target else mid-1