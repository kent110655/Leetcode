class Solution(object):
    def longestCommonPrefix(self, strs):
        """
        :type strs: List[str]
        :rtype: str
        """
        result = ""
        firstStr = strs[0]
        for i in range(0,len(firstStr)):
            for s in strs:
                if i > len(s)-1 or firstStr[i] != s[i]:
                    return result
            result += firstStr[i]

        return result

"""
Comment:
隨機以一個string當作標竿，依序確認其餘string是否有相同的char
時間複雜度：Ｏ(m*n)
空間複雜度：Ｏ(M), M = 最短str
"""
