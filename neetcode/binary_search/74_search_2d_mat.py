class Solution:
    def searchMatrix(self, matrix: list[list[int]], target: int) -> bool:
        if target<matrix[0][0] or target>matrix[-1][-1]:
            return False

        low =0
        high = len(matrix)-1

        while low<=high:
            row = low + (high-low)//2
            if target>matrix[row][-1]:
                low = row+1
            elif target<matrix[row][0]:
                high = row-1
            else:
                break

        low = 0
        high = len(matrix[0])-1

        while low<=high:
            mid = low + (high-low)//2
            if target == matrix[row][mid]:
                return True
            if target<matrix[row][mid]:
                high = mid-1
            else:
                low = mid+1
        
        return False