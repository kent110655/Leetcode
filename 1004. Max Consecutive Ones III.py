class Solution:
    def longestOnes(self, nums: list[int], k: int) -> int:
        left, right = 0, 0
        zeroCnt = 0
        maxCnt = 0
        while right < len(nums):
            if nums[right] == 0:
                zeroCnt += 1

            while zeroCnt > k:
                if nums[left] == 0:
                    zeroCnt -= 1
                left += 1
            
            maxCnt = max(maxCnt, right-left+1)
            right += 1
        return maxCnt

"""
Comment:
I use a sliding window to solve the problem. After the right pointer move forward, if the count of zero is bigger than k, left pointer would move forward until the count of zero is equal or smaller than k. In the proccess of the moving window, I record the maxium window size. Finally, the maxium window size is the answer.
Time Complexity:Ｏ(n)
Space Complexity:Ｏ(1)
"""
