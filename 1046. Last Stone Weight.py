class Solution:
    def lastStoneWeight(self, stones: list[int]) -> int:
        negaStone = []
        for s in stones:
            negaStone.append((-1)*s)
        heapq.heapify(negaStone)
        while len(negaStone) > 1:
            x = heapq.heappop(negaStone)
            y = heapq.heappop(negaStone)
            if x == y:
                continue
            else:
                heapq.heappush(negaStone, abs(x-y)*(-1))
        if len(negaStone) == 0:
            return 0
        else:
            return negaStone[0] * (-1)

"""
Comment:
I use a priority queue to maintain the biggest element.
Time Complexity:Ｏ(nlogn)
Space Compelxity:Ｏ(n)
"""
