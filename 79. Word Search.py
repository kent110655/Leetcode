class Solution:
    def exist(self, board: list[list[str]], word: str) -> bool:
        lenX, lenY = len(board), len(board[0])
        
        def dfs(x, y, wordIndex) -> bool:
            if wordIndex == len(word):
                return True
            if x<0 or y<0 or x>=lenX or y>=lenY or board[x][y] != word[wordIndex]:
                return False
            
            origin = board[x][y]
            board[x][y] = '*'
            result = dfs(x+1,y,wordIndex+1) or dfs(x-1,y,wordIndex+1) or dfs(x,y+1,wordIndex+1) or dfs(x,y-1,wordIndex+1)
            board[x][y] = origin

            return result
        
        for x in range(lenX):
            for y in range(lenY):
                if dfs(x,y,0):
                    return True
        return False
            
"""
Comment:
First, I find all the char which is the same as the first char in 'word' in the board. Then I use decision tree to represent the choosing next node. Then I use DFS traverse all the path and check whether there is a path complete the word I wanted.

Time Complexity:Ｏ(m*n*3^L)
One search tree would be Ｏ(3^L) because every step has three option(direction) to choose, it means it has three subnode in each node. And the height is L.  So it is Ｏ(3^L). And there can be m*n start point so the total time would be Ｏ(m*n*3^L)

Space Complexity:Ｏ(L), L: length of word(stack depth)
"""
