class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        M = len(grid)
        N = len(grid[0])
        cnt = 0
        stack = []
        for x in range(M):
            for y in range(N):
                if grid[x][y] == "1":
                    stack.append((x,y))
                    while stack:
                        cur = stack.pop()
                        i, j = cur[0], cur[1]
                        
                        if grid[i][j] == "0":
                            continue
                            
                        grid[i][j] = "0"
                        for ni, nj in ((i+1,j), (i-1,j), (i,j+1), (i,j-1)):
                            if 0 <= ni < M and 0 <= nj < N and grid[ni][nj] == "1":
                                stack.append((ni,nj))
                    cnt += 1
        return cnt

"""
Comment:
I use the DFS to traverse all the path in the grid. And I let the land become water after I go through the spot. At the same time, I count the count of island to get the answer.
Time Complexity: Ｏ(MN)
Space Complexity: Ｏ(MN)
"""      
