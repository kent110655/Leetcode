class Solution:
    def searchMatrix(self, matrix: list[list[int]], target: int) -> bool:
        M = len(matrix)
        N = len(matrix[0])
        left, right = -1, M*N

        while left+1 < right:
            mid = left + (right-left)//2
            x, y = mid%N , mid//N
            if matrix[y][x] > target:
                right = mid
            elif matrix[y][x] < target:
                left = mid
            else:
                return True
        return False

"""
Comment:
I use a binary search to search the target.
Time Complexity:Ｏ(log(mn))
Space Complexity:Ｏ(1)
"""
