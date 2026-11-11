class Solution:
    def findCircleNum(self, isConnected: List[List[int]]) -> int:
        cnt = 0
        unvisited = set()
        for i in range(len(isConnected)):
            unvisited.add(i)
        
        def dfs(i):
            if i not in unvisited:
                return
            unvisited.remove(i)
            for c in range(len(isConnected)):
                if isConnected[c][i] == 1:
                    isConnected[c][i] = 0
                    isConnected[i][c] = 0
                    dfs(c)

        while unvisited:
            cur = unvisited.pop()
            unvisited.add(cur)
            dfs(cur)
            cnt+=1
        return cnt
"""
Comment:
I use a dfs to traverse the node and count the number of connected conponent.
Time Complexity:Ｏ(n^2), each node may go through all n , so n * n
Space Complexity:Ｏ(n)
"""
