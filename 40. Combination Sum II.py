class Solution:
    def combinationSum2(self, candidates: list[int], target: int) -> list[list[int]]:
        ans, path = [], []
        N = len(candidates)
        candidates = sorted(candidates)

        def dfs(start, remain):
            if remain == 0:
                ans.append(path.copy())
                return
            
            for i in range(start, N):
                c = candidates[i]
                if c > remain:
                    break
                if i > start and c == candidates[i-1]:
                    continue
                path.append(c)
                dfs(i+1, remain-c)
                path.pop()
        dfs(0,target)
        return ans

"""
Comment:
Use decision tree, and every edge means choosing one of the candidate. And the duplicate candidate cannot be choosen in the same stage. Then I use dfs to traverse all the path and record the path I need, then return the answer.
Time Complexity:Ｏ(2^n)
Space Complexity:Ｏ(n)
"""
