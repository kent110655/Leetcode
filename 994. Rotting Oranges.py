class Solution:
    def orangesRotting(self, grid: list[list[int]]) -> int:
        q = deque()
        minute = 0

        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j] == 2:
                    q.appendleft((minute, (i, j)))
        
        while q:
            cur = q.pop()
            ni, nj = cur[1][0], cur[1][1]
            curMinute = cur[0]
            minute = max(minute, curMinute)

            dirList = [(ni+1,nj), (ni-1,nj), (ni,nj+1), (ni,nj-1)]
            for x,y in dirList:
                if 0<=x<len(grid) and 0<=y<len(grid[0]) and grid[x][y] == 1:
                    grid[x][y] = 2
                    q.appendleft((curMinute+1, (x,y)))
                    
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j] == 1:
                    return -1
                    
        return minute

"""
Comment:
I use a queue to implement a BFS traversal. I record the minute and the index in the queue. After the BFS traversal, I can get the minute in the final time or there is some orange is still fresh.
Time Complexity:Ｏ(M*N)
Space Complexity:Ｏ(M*N)
"""
