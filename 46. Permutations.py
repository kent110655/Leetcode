class Solution:
    def permute(self, nums: list[int]) -> list[list[int]]:
        ans, path = [], []
        def dfs(remain):
            if remain == []:
                ans.append(path[:])
                return
            for index in range(0, len(remain)):
                path.append(remain[index])
                dfs(remain[:index] + remain[index+1:])
                path.pop()
        dfs(nums)
        return ans
"""
Comment:
Time Complexity: Ｏ(n!)
Space Complexity: Ｏ(n)
"""
