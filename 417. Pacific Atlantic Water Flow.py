class Solution:
    def pacificAtlantic(self, heights: list[list[int]]) -> list[list[int]]:
        M, N = len(heights), len(heights[0])
        p = set()
        a = set()

        def dfs(i, j, t):
            if t == 1:
                s = p
            else:
                s = a
            stack = [(i,j)]
            while stack:
                cur = stack.pop()
                ci, cj = cur[0], cur[1]
                
                s.add((ci,cj))

                for (ni,nj) in [(ci+1,cj), (ci-1,cj), (ci,cj+1), (ci,cj-1)]:
                    if 0 <= ni < M and 0 <= nj < N and heights[ni][nj]>=heights[ci][cj] and (ni,nj) not in s:
                        stack.append((ni,nj))

        for j in range(N):
            dfs(0, j, 1)
            dfs(M-1, j, 2)
        for i in range(M):
            dfs(i, 0, 1)
            dfs(i, N-1, 2)
        
        return [[x,y] for x,y in p & a]

"""
Comment:
Because starting from every node to the edge is too complicated, so I choose to reverse the direction. I start from the edge to each node and record all the node which arrived in a set. Two ocean build two set. Then I can get the answer in the intersection of two set.
Time Complexity:Ｏ(M*N), go through all node
Space Complexity:Ｏ(M*N), the worst case in stack
"""
