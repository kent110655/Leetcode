class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        def hashMatch(h1,h2) -> bool:
            for i1,v1 in enumerate(h1):
                if h1.get(v1, 0) != h2.get(v1, 0):
                    return False
            return True
        
        N1 = len(s1)
        N2 = len(s2)
        if N1 > N2:
            return False
        h1 = {}
        h2 = {}
        for c in s1:
            h1[c] = h1.get(c,0) + 1
        for i in range(0, N1):
            h2[s2[i]] = h2.get(s2[i], 0) + 1
        if hashMatch(h1,h2):
            return True

        left, right = 0, N1-1
        while right < N2-1:
            right += 1
            h2[s2[right]] = h2.get(s2[right], 0) + 1
            h2[s2[left]] = h2.get(s2[left], 0) - 1
            left += 1
            if hashMatch(h1,h2):
                return True
        return False

"""
Comment:
Use a sliding window which has the same length to s1. Use a hash table to record the element count in this window. When hash table match the s1 element count, it can return True.
Time Complexity: Ｏ(n)
Space Complexity: Ｏ(1), lowercase letters only has 26
"""
