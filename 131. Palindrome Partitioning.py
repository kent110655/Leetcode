class Solution:
    def partition(self, s: str) -> list[list[str]]:
        ans = []
        path = []

        def isPalindrome(ss) -> bool:
            left, right = 0, len(ss)-1
            while left < right:
                if ss[left] == ss[right]:
                    left += 1
                    right -= 1
                else:
                    return False
            return True

        def dfs(cutIndex, remainStartIndex):
            if remainStartIndex == len(s):
                ans.append(path.copy())
                return
            if cutIndex == len(s)-1 and not isPalindrome(s[remainStartIndex:]):
                return
            if cutIndex >= len(s):
                return
            
            # not to cut
            dfs(cutIndex+1, remainStartIndex)

            # cut
            subS = s[remainStartIndex:cutIndex+1]
            if isPalindrome(subS):
                path.append(subS)
                dfs(cutIndex+1, cutIndex+1)
                path.pop()

        dfs(0, 0)
        return ans

"""
Comment:
Use a decision tree to represent the choosing to cut or not to
cut. Then use dfs to traverse the tree. If the substring which is cut is not palindrome, I would cut the path and continue to try another path. When the path complete and arrive at the leaf, the path would be the one of answer, and I would append the path into the answer list. After traversing whole the tree, I can get the answer list which contains all the legal path.
Time Complexity: Ｏ(n*2^n), tree height=n, level node: 2^n
Space Complexity: Ｏ(n)
"""
