class Solution:
    def generateParenthesis(self, n: int) -> list[str]:
        ans = []

        def dfs(lc,rc,s):
            if lc > rc or lc < 0 or rc < 0:
                return
            if lc == 0 and rc == 0:
                ans.append(''.join(s))
                return

            # choose left
            s.append('(')
            dfs(lc-1,rc,s)
            s.pop()

            #choose right
            s.append(')')
            dfs(lc,rc-1,s)
            s.pop()
        
        dfs(n,n,[])
        return ans
"""
I use a decision tree to represent the possible for the combination. And use a dfs to traverse all the path. At the same time, I pruned the bad-formed path and record the well-formed path that completed. After going through all the path, I can get all the possible answer which are well-formed.
Time Complexity:Ｏ(4^n), level node: 2^(2n) = 4^n
Space Complexity:Ｏ(n), tree height:2n
"""
