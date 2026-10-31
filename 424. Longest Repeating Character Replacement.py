class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        h = {}
        maxC = 0
        left = 0
        for right in range(len(s)):
            h[s[right]] = h.get(s[right],0) + 1
            maxC = max(maxC, h[s[right]])

            if (right-left+1) - maxC > k:
                h[s[left]] = h.get(s[left],0) - 1
                left += 1
        return right-left+1

"""
Comment:
Use sliding windows to maintain a longest window. Follow the rule that every time expand the window is legal substring. If window is not legal, just move forward by moving left and right pointer. Then there would be the longest size of window after window arrived the end of the array.
Time Complexity: Ｏ(n)
Space Complexity: Ｏ(1), only 26 type of char
"""
