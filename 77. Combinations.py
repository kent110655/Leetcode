class Solution:
    def combine(self, n: int, k: int) -> list[list[int]]:
        ans = []
        pick = []

        def dfs(start):
            if len(pick) == k:
                ans.append(pick.copy())
                return
            if n-start+1 < k - len(pick):
                return
            for i in range(start, n+1):
                pick.append(i)
                dfs(i+1)
                pick.pop()
            return
        
        dfs(1)
        return ans
               
"""
Comment:
I use a decision tree to represent the combination question. First, I use a DFS traversal to go through all the path, and I record the path in the ans list when path list already contains k element.
Time Complexity:Ｏ(k * C(n,k))
    leaf count: C(n,k), tree height: k
    -> Ｏ(k * C(n,k))
Space Complexity:Ｏ(k), stack depth = k
"""
