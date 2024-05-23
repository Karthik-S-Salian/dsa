class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        result = [[]]

        for n1 in nums:
            temp =[]

            for n2 in result:
                l1 = n2.copy()
                l1.append(n1)
                temp.append(l1)
            result.extend(temp)

        return result