class Solution:
    def combinationSum(self, candidates: list[int], target: int) -> list[list[int]]:
        ans, cur = [], []
        N = len(candidates)
        def dfs(start, remainTarget):
            if remainTarget == 0:
                ans.append(cur[:])
                return
            elif remainTarget < 0 or start == N:
                return
            for ci in range(start, N):
                cur.append(candidates[ci])
                dfs(ci, remainTarget-candidates[ci])
                cur.pop()
        
        dfs(0, target)
        return ans

"""
comment:
Use decision tree to represent the choosing situation. Then use DFS to traverser the path and record the path and remain target. If remain target is equal to zero, it means the current path is tha onne of the answer. And use start to limit that the candidate cannot be use after another candidate.

Time Complexity:Ｏ(n^(T/M)), 
Space Complexity:Ｏ(T/M)
n: candidates, T: target, M: min candidate
"""
