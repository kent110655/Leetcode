class Solution:
    def carFleet(self, target: int, position: list[int], speed: list[int]) -> int:
        d = {}
        for i in range(len(position)):
            time = (target - position[i]) / speed[i]
            d[position[i]] = (speed[i], time)
        
        sort = sorted(position)
        head = len(sort)-1
        fleetCnt = 1
        for j in range(len(sort)-2, -1, -1):
            if d[sort[j]][1] > d[sort[head]][1]:
                head = j
                fleetCnt += 1
        return fleetCnt

"""
Comment:
First, I calculate the arrived time for each car if there are no fleet rule. And sort the position to have the sequence in position. If the car that is closer to target have a bigger time value, it means the car would stuck the car which have smaller time value and is behind it. So I can use the rule to find the count of fleet.
Time Complexity:Ｏ(nlogn)
Space Complexity:Ｏ(n)
"""
