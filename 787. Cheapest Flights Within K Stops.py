# Bellman-Ford
class Solution:
    def findCheapestPrice(self, n: int, flights: list[list[int]], src: int, dst: int, k: int) -> int:
        dist = [float("inf")]*n
        dist[src] = 0

        for _ in range(k+1):
            update = False
            lastDist = dist.copy()
            for start, target, price in flights:
                if lastDist[start] + price < dist[target]:
                    dist[target] = lastDist[start] + price
                    update = True
            if update == False:
                break
        return dist[dst] if dist[dst] != float("inf") else -1
                
"""
Comment:
I use the Bellman-Ford algo. to find the single source shortest path solution. Because the question is limited in step, and the Bellman-Ford has the similar step too. So I choose the Bellman-Ford algo. I do a k+1 times to relax all the edge and update the dist that the minium price can be. Specially, to make the step count correct, I need to read the price of the same dist which is from last step so I copied the dist when I started a new step. After k+1 times of relax, I can get the final minium price.
Time Complexity:Ｏ(k*(V+E))
Space Complexity:Ｏ(V)
"""



""" BFS+dictionary
class Solution:
    def findCheapestPrice(self, n: int, flights: list[list[int]], src: int, dst: int, k: int) -> int:
        adj = defaultdict(list)
        for f in flights:
            adj[f[0]].append((f[1],f[2]))
        
        minDist = [float("inf")] * n
        minDist[src] = 0
        q = deque()
        q.append((src, 0, -1)) # start node, total price, stop
        while q:
            start, price, stop = q.popleft()
            if start == dst:
                continue
            if stop == k:
                continue
            for a in adj[start]:
                if price+a[1] < minDist[a[0]]:
                    minDist[a[0]] = price+a[1]
                    q.append((a[0], price + a[1], stop+1))
        
        return minDist[dst] if minDist[dst] != float("inf") else -1

"""
"""
Comment:
I use a BFS to traverse all the path which at most stop k node. At the same time, to do a pruning, I maintain a dictionary to store the minium price that the node should spend. If the node I go through has a bigger price than the minium price in the dictionary, I can dispose the path directly. After I go through all the legal path, I can get the minium price to every node. And the price of the destination is the answer.
Time Complexity:Ｏ(k*E)
Space Complexity:Ｏ(n+E), adj:E, minDist:n
"""
