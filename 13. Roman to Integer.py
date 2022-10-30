class Solution(object):
    def romanToInt(self, s):
        """
        :type s: str
        :rtype: int
        """
        lastnum = 0
        result = 0
        Rdict = {"I":1, "V":5, "X":10, "L":50, "C":100, "D":500, "M":1000}
        for i in s[::-1]:
            if Rdict[i] >= lastnum:
                result += Rdict[i]
            else:
                result -= Rdict[i]
            lastnum = Rdict[i]
        return result

"""
Comment:
倒序判斷相鄰element大小決定正負
時間複雜度：Ｏ(15) = Ｏ(1)
空間複雜度：Ｏ(1)
"""
