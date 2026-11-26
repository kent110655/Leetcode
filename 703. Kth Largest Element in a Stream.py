class KthLargest:
    
    def __init__(self, k: int, nums: list[int]):
        self.pq = nums
        heapq.heapify(self.pq)
        while len(self.pq) > k:
            heapq.heappop(self.pq)
        self.k = k

    def add(self, val: int) -> int:
        heapq.heappush(self.pq,val)
        if len(self.pq) > self.k:
            heapq.heappop(self.pq)
        return self.pq[0]


# Your KthLargest object will be instantiated and called as such:
# obj = KthLargest(k, nums)
# param_1 = obj.add(val)

"""
Comment:
Use a priority queue to maintain the k th largest element.
Time Complexity:
    Initial: Ｏ(n)
    Add: Ｏ(logn)
Space Complexity:Ｏ(k)
"""
