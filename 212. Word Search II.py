class Solution:
    def findWords(self, board: list[list[str]], words: list[str]) -> list[str]:
        M = len(board)
        N = len(board[0])
        ans = []

        # make the trie with words
        root = {}
        for word in words:
            cur = root
            for c in word:
                if c not in cur:
                    cur[c] = {}
                cur = cur[c]
            cur['#'] = word

        def dfs(startX: int, startY: int, curNode) -> bool:
            if '#' in curNode:
                ans.append(curNode['#'])
                curNode.pop('#',None)

            direction = [(startX+1, startY), (startX-1, startY), (startX, startY+1), (startX, startY-1)]
            for dx, dy in direction:
                if 0<=dx<M and 0<=dy<N and board[dx][dy] != '@' and board[dx][dy] in curNode:
                    ori = board[dx][dy]
                    board[dx][dy] = '@'
                    preNode = curNode
                    curNode = curNode[ori]
                    dfs(dx, dy, curNode)
                    if not curNode:
                        preNode.pop(ori)
                    curNode = preNode
                    board[dx][dy] = ori
        
        for x in range(M):
            for y in range(N):
                curNode = root
                if board[x][y] in root:
                    pre = board[x][y]
                    curNode = curNode[board[x][y]]
                    board[x][y] = '@'
                    dfs(x,y,curNode)
                    board[x][y] = pre

        return ans

"""
Comment:
To speed up, I make a trie from the words. And use the Trie to check whether the DFS traversal is match the target. After a path was found in the target word, cut the word in the trie to avoid duplicate path. Then I use a dfs to traverse all the spot in the board to get the answer.
Time Complexity: Ｏ(S+MN*3^L)
    Trie: Ｏ(S), S: count of char
    DFS: Ｏ(M*N*3^L), max len of words
Space Complexity: Ｏ(S+L)
    Trie: Ｏ(S), S: count of char
    DFS: Ｏ(L), max len of words
"""


"""
DFS version TLE:

class Solution:
    def findWords(self, board: list[list[str]], words: list[str]) -> list[str]:
        M = len(board)
        N = len(board[0])
        ans = []

        h = defaultdict(list)
        for x in range(M):
            for y in range(N):
                h[board[x][y]].append((x,y))

        used = [[False] * N for _ in range(M)]
        target = words[0]

        def dfs(startX: int, startY: int, targetIndex: int) -> bool:
            if targetIndex == len(target):
                return True
            direction = [(startX+1, startY), (startX-1, startY), (startX, startY+1), (startX, startY-1)]
            for dx, dy in direction:
                if 0<=dx<M and 0<=dy<N and used[dx][dy] == False and board[dx][dy] == target[targetIndex]:
                    used[dx][dy] = True
                    if dfs(dx, dy, targetIndex+1):
                        return True
                    used[dx][dy] = False
            return False
        
        for i in range(len(words)):
            target = words[i]
            for x,y in h[target[0]]:
                used = [[False] * N for _ in range(M)]
                used[x][y] = True
                if dfs(x,y,1):
                    ans.append(target)
                    break
        return ans

"""
