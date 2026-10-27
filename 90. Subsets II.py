class Solution:
    def subsetsWithDup(self, nums: list[int]) -> list[list[int]]:
        ans, subset = [], []
        table = set()
        N = len(nums)
        nums = sorted(nums)
        
        def dfs(i):
            if i == N:
                s = tuple(subset)
                if s not in table:
                    table.add(s)
                    ans.append(list(s))
                return
            # no choose nums[i]
            dfs(i+1)
            # choose nums[i]
            subset.append(nums[i])
            dfs(i+1)
            subset.pop()
        
        dfs(0)
        return ans
"""
Comment:
I use the decision tree to represent the choosing subset. Because I sort the original list, so the subset sequence would be the same. Then I use DFS traverse the path and record the subset in the set in order to remove the duplicate subsets.
Then I could find the subsets without duplicate.
Time Complexity: Ｏ(nlogn + n * 2^n) = Ｏ(n * 2^n)
Space Complexity: Ｏ(n * 2^n)
"""
