class Solution:
    def minEatingSpeed(self, piles: list[int], h: int) -> int:
        maxB = 0
        for b in piles:
            maxB = max(maxB, b)
        
        def costHour(speed):
            cnt = 0
            for p in piles:
                cnt += p//speed
                if p%speed != 0:
                    cnt += 1
            return cnt
        
        left, right = 0, maxB+1
        while left+1 < right:
            mid = left + (right-left)//2
            hour = costHour(mid)
            if hour <= h:
                right = mid
            else:
                left = mid
        return right

"""
Comment:
I use binary search to find the proper minium speed.
Time Complexity:Ｏ(nlogn), costHour: n, binary search:logn
Space Complexity:Ｏ(1)
"""
