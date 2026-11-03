class Solution:
    def letterCombinations(self, digits: str) -> list[str]:
        mapping = {}
        for index in range(2,7):
            mapping[str(index)] = [chr(ord('a')+((index-2)*3)), chr(ord('b')+((index-2)*3)), chr(ord('c')+((index-2)*3))]
        mapping["7"] = ['p', 'q','r', 's']
        mapping["8"] = ['t', 'u','v']
        mapping["9"] = ['w', 'x','y', 'z']
        ans, path = [], []
        N = len(digits)
        def dfs(i):
            if i >= N:
                ans.append("".join(path))
                return
            for c in mapping[digits[i]]:
                path.append(c)
                dfs(i+1)
                path.pop()
        dfs(0)
        return ans

"""
Comment:
I use a decision tree to repesent theh choosing char in every digits. Then use DFS to traverse all the path and record it. when the traversal arrived the leaf, I would append the path into the ans list. After traversing all the path, ans list would be the answer.
Time Complexity: Ｏ(4^n * n), 4^n(leaf cnt) * n(height)
Space Complexity: Ｏ(n), height
"""
