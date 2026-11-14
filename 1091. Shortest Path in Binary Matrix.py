class Solution:
    def shortestPathBinaryMatrix(self, grid: list[list[int]]) -> int:
        q = deque()
        visited = set()
        if grid[0][0] != 0 or grid[-1][-1] != 0:
            return -1
        q.appendleft((0,0,1))
        visited.add((0,0))

        while q:
            x,y,d = q.pop()
            if (x,y) == (len(grid[0])-1, len(grid)-1):
                return d
            direction = [(x+1,y), (x-1,y), (x,y+1), (x,y-1), (x+1,y+1), (x-1,y-1), (x+1,y-1), (x-1,y+1)]
            for nx,ny in direction:
                if 0<=nx<len(grid) and 0<=ny<len(grid[0]) and grid[nx][ny] == 0 and (nx,ny) not in visited:
                    q.appendleft((nx,ny,d+1))
                    visited.add((nx,ny))
        return -1
"""
Comment:
I use a BFS traversal to go through all the path. And if I go througn the bottom-right cell, it means the distance is the shortest distance in the path.
Time Complexity:Ｏ(n^2)
Space Comeplexity:Ｏ(n^2)
"""
