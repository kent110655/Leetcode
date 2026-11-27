class Solution:
    def kClosest(self, points: list[list[int]], k: int) -> list[list[int]]:
        ans = []
        pq = []
        for p in points:
            pq.append((pow(p[0], 2) + pow(p[1], 2), p))
        heapq.heapify(pq)
        for _ in range(k):
            point = heapq.heappop(pq)
            ans.append(point[1])
        return ans
"""
Comment:
I use a priority queue to store the tuple that is (distance, point), then I just pop the min distance k times to get the answer.
Time Complexity:Ｏ(n + klogn)
Space Complexity:Ｏ(n)
"""
