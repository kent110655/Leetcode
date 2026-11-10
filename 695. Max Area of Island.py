class Solution:
    def maxAreaOfIsland(self, grid: list[list[int]]) -> int:
        maxI = 0

        def dfs(i,j):
            nonlocal cur
            if grid[i][j] == 0:
                return
            
            cur += 1
            grid[i][j] = 0
            if i+1 < len(grid):
                dfs(i+1, j)
            if i-1 >= 0:
                dfs(i-1, j)
            if j+1 < len(grid[0]):
                dfs(i, j+1)
            if j-1 >= 0:
                dfs(i, j-1)
            return

        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j] == 1:
                    cur = 0
                    dfs(i,j)
                    maxI = max(maxI, cur)
        return maxI

"""
Comment:
I use a loop to find all the island element. Every time I find an island element, I would traverse the island by dfs and count the area of this island and change the element 1 to 0 after I traverse the element. After completing an island, I would update the max area of whole island. Finally, I would get the answer maxI.
Time Complexity:Ｏ(M*N)
Space Complexity:Ｏ(M*N), worst stack depth would be M*N (all element is island)
"""
