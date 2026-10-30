class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        p1,p2 = 0, 0
        ans = 0
        N = len(s)
        h = {}
        if N == 0 or N == 1:
            return N
        h[s[0]] = 1
        p2 += 1
        while p2 < N:
            h[s[p2]] = h.get(s[p2], 0) + 1

            while h[s[p2]] > 1 and p1 != p2:
                h[s[p1]] -= 1
                p1 += 1
            
            ans = max(ans, p2-p1+1)
            p2 += 1
        return ans

"""
Comment:
I use sliding window ,ethod to solve the problem. Use two pointer to maintain a window and let the element in the window are never be duplicate. Then move the window legally and record the maxium length of window and get the answer.
Time Complexity: Ｏ(n)
Space Complexity: Ｏ(n)
"""
