class Solution:
    def leastInterval(self, tasks: list[str], n: int) -> int:
        h = {}
        for t in tasks:
            h[t] = h.get(t,0) - 1
        pq = []
        for key, value in h.items():
            heapq.heappush(pq, (value,key))
        
        approveTime = {}
        curTime = 0
        while pq:
            tempt = []
            while pq:
                cnt, task = heapq.heappop(pq)
                if approveTime.get(task, -1) <= curTime:
                    approveTime[task] = curTime + n + 1
                    if cnt < (-1):
                        heapq.heappush(pq, (cnt+1, task))
                    break
                else:
                    tempt.append((cnt,task))
            while tempt:
                heapq.heappush(pq, tempt.pop())
            curTime += 1
        return curTime

"""
Comment:
I use a max heap to find the max count remaining task, and I would maintain a hash table to store the time that the letter can be used. So I take the max count remaining task from max heap and check whether the task can be used by checking the hash table. If the task cannot be used, I would take the next element in the max heap until finding the task can be used. Then I use the letter. If there is no task can be used, just pass the time. At the end, the time I used is the answer.
Time Complexity:Ｏ(T * ULOGU), T: total time, U: U type of task = 26 , so Ｏ(T)
Space Complexity:Ｏ(U)
"""
