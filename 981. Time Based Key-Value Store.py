class TimeMap:
    def __init__(self):
        self.d = defaultdict(list)

    def set(self, key: str, value: str, timestamp: int) -> None:
        self.d[key].append((value, timestamp))

    def get(self, key: str, timestamp: int) -> str:
        dList = self.d[key]
        N = len(dList)
        # binary search
        left, right = -1, N
        while left+1 < right:
            mid = left+(right-left)//2
            if dList[mid][1] <= timestamp:
                left = mid
            else:
                right = mid
        if left == -1:
            return ""
        return dList[left][0]


# Your TimeMap object will be instantiated and called as such:
# obj = TimeMap()
# obj.set(key,value,timestamp)
# param_2 = obj.get(key,timestamp)

"""
Comment:
I use a dictionary to store the content. And the value of the dictionary is a tuple that store the value and timestamp. Then I use a binary search to find the value.
Time Complexity:Ｏ(logn)
Space Complexity:Ｏ(n)
"""
