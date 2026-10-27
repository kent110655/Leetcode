class Solution:
    def subsets(self, nums: list[int]) -> list[list[int]]:
        n = len(nums)
        ans = []
        for s in range(0, 1<<n):
            subset = []
            for i in range(0, n):
                if s & 1<<i:
                    subset.append(nums[i])
            ans.append(subset)
        return ans

"""
Comment:
use bit operation. 1<<len(nums) represent all the possible subset. So I can find all the subset by mask (s & 1 <<i).
Time Complexity: Ｏ(n * 2^n)
Space Complexity: Ｏ(n)
"""

"""
class Solution:
    def subsets(self, nums: list[int]) -> list[list[int]]:
        ans, subset = [],[]

        def dfs(i):
            if i == len(nums):
                ans.append(subset[:])
                return
            
            # not choose nums[i]
            dfs(i+1)
            # choose nums[i]
            subset.append(nums[i])
            dfs(i+1)
            subset.pop()

        dfs(0)
        return ans
Comment:
use decision tree to present the choice. And then use dfs to traverse all the possible subset.
Time Complexity: Ｏ(n * 2^n)
Space Complexity: Ｏ(n)
"""

"""
class Solution:
    def subsets(self, nums: list[int]) -> list[list[int]]:
        sub = [[]]
        for n in nums: # n: int
            subN = [[], [n]]
            tempt = [[]]
            for sn in subN: # sn: []
                for s in sub: # s: []
                    if sn == [] and s == []:
                        continue
                    tempt.append(sn+s)
            sub = tempt
        return sub
Comment:
every set make pair and remove the duplicate []
Time Complexity: Ｏ(n * 2^n)
Space Complexity: Ｏ(n)
"""
