class Solution:
    def evalRPN(self, tokens: list[str]) -> int:
        stack = []
        operator = ['+', '-', '*', '/']
        for t in tokens:
            if t in operator:
                v2 = stack.pop()
                v1 = stack.pop()
                if t == '+':
                    r = v1+v2
                elif t == '-':
                    r = v1-v2
                elif t == '*':
                    r = v1*v2
                else:
                    r = int(v1/v2)
                stack.append(r)
            else:
                stack.append(int(t))
        return stack.pop()
"""
use a stack to represent the notation sequence.
Time Complexity:Ｏ(n)
Space Complexity:Ｏ(n)
"""
