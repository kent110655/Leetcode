class Solution:
    def minCostConnectPoints(self, points: list[list[int]]) -> int:
        N = len(points)
        ans = 0
        visited = set()
        minHeap = [(0, 0)] # (distance, index)
        while len(visited) < N:
            d, i = heapq.heappop(minHeap)
            if i in visited:
                continue

            ans += d
            visited.add(i)
            for a in range(N):
                if a in visited:
                    continue
                distance = abs(points[i][0] - points[a][0]) + abs(points[i][1] - points[a][1])
                heapq.heappush(minHeap, (distance, a))
        return ans
"""
Comment:
The question is the minium spanning tree question. I use the Prim algo. to solve the question. I use a priority queue to store the (cost, point) in order to get the minium cost which point is not visited. Then update the total cost in ans. Finally, I would get the total minium cost.
Time Complexity:Ｏ(VlogV+ElogV)
Space Complexity:Ｏ(V+E), visited: Ｏ(V), pq:Ｏ(E)
"""
