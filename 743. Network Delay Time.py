class Solution:
    def networkDelayTime(self, times: list[list[int]], n: int, k: int) -> int:
        graph = defaultdict(list)
        for s, t, d in times:
            graph[s].append((t,d))
        
        pq = [(0,k)] # edge list
        minDist = [float("inf")] * (n+1)
        minDist[k]=0

        while pq:
            startDis, start = heapq.heappop(pq)
            for target, dis in graph[start]:
                if startDis + dis < minDist[target]:
                    minDist[target] = startDis + dis
                    heapq.heappush(pq,(minDist[target], target))
        ans = max(minDist[1:])
        return ans if ans != float("inf") else -1

"""
Comment:
I use the Dijstra algo. to find the single point shortest path. Priority queue contains the message which should be considered. And get the minium weight edge from priority queue and compare it whether can be a shorter path. If it is a shorter path, just update the minDist record and add the new edge of new node to the priority queue. After processing all the edge in the prority queue, I can get a final record minDist to represent the shortest path. And the maxium distance in this record would be the answer.
Time Complexity:Ｏ(V+ElogV)
    build graph: Ｏ(E)
    initialize minDist: Ｏ(V)
    priority queue push+pop: Ｏ(logE * E) = Ｏ(ElogV)
Space Complexity:Ｏ(V+E)
    graph: Ｏ(V+E)
    priority queue: Ｏ(E)
    minDist: Ｏ(V)
"""
