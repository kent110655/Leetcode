class Solution:
    def solve(self, board: list[list[str]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        def dfs(i, j):
            if board[i][j] == "X":
                return
            stack = []
            stack.append((i,j))
            while stack:
                cur = stack.pop()
                ni,nj = cur[0], cur[1]
                board[ni][nj] = "K"
                dirList = [(ni+1,nj), (ni-1,nj), (ni,nj+1), (ni,nj-1)]
                for x,y in dirList:
                    if 0<=x<len(board) and 0<=y<len(board[0]) and board[x][y] != "X" and board[x][y] != "K":
                        stack.append((x,y))
        
        for p in range(len(board)):
            dfs(p,0)
            dfs(p,len(board[0])-1)
        for k in range(len(board[0])):
            dfs(0,k)
            dfs(len(board)-1,k)

        for w in range(len(board)):
            for t in range(len(board[0])):
                if board[w][t] != "K":
                    board[w][t] = "X"
                else:
                    board[w][t] = "O"
"""
Comment:
I use a dfs to traverse all the path which begin from edge. And I change all the element in the path from "O" to "K" to record the element which don't need to be change. Then I would get the correct graph of answer.
Time Complexity:Ｏ(M*N), worst case is going through all element
Space Complexity:Ｏ(M*N), worst case is full element in stack
"""
