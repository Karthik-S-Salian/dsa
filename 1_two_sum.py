class Solution:
    def twoSum(self, nums: list[int], target: int) -> list[int]:
        M = {}
        for i,num in enumerate(nums):
            if M.get(num,None) is not None:
                return [M[num],i]
            M[target - num] = i