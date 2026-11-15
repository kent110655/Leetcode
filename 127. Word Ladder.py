class Solution:
    def ladderLength(self, beginWord: str, endWord: str, wordList: list[str]) -> int:
        if endWord not in set(wordList):
            return 0
        N = len(beginWord)
        buckets = defaultdict(list)
        wordList.append(beginWord)
        wN = len(wordList)

        for w in wordList:
            for i in range(N):
                buckets[w[:i] + '*' + w[i+1:]].append(w)
        
        visited = set()
        q = deque()
        q.appendleft((wordList[wN-1], 1))
        visited.add(wordList[wN-1])
        while q:
            curW, d = q.pop()
            for j in range(N):
                bKey = curW[:j] + '*' + curW[j+1:]
                for word in buckets[bKey]: 
                    if word not in visited:
                        if word == endWord:
                            return d+1
                        visited.add(word)
                        q.appendleft((word,d+1))
        return 0
"""
Comment:
In this question, I decide to build a graph that each node connects their legal adjacent node which represent a string differ from one char. I use a dictionary to store all the possible string which differ from specific char. Then I use a BFS traversal to go through all the path from the beginWord and record the distance at the same time. When I go through the endWord Node, I can get the distance, and the distance would be the answer.
Time Complexity:Ｏ(ML^2),
    build graph: M (words) * L (different char) * L (build string) = ML^2
    BFS traversal: M (words) * L (different char) * L (build string) = ML^2
Space Complexity:Ｏ(ML^2)
    graph buckets: M (words) * L (different char) * L (string length)
    queue: M (words) * L (string length)
"""
