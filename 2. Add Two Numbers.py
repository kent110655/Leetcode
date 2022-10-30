# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        carry = 0
        current = l1
        while True:
            num = (current.val + l2.val + carry) % 10 
            carry = (current.val + l2.val + carry) // 10
            current.val = num
            
            if current.next == None and l2.next == None:
                if carry != 0:
                    current.next = ListNode()
                    current.next.val = carry
                break
            elif current.next != None and l2.next == None:
                l2.next = ListNode()
                l2.next.val = 0
            elif current.next == None and l2.next != None:
                current.next = ListNode()
                current.next.val = 0
            current = current.next
            l2 = l2.next
        return l1
"""
comment:
分四種情況分別處理
1. l1短於l2
2. l2短於l1
3. l1,l2等長(但不進位)
4. l1,l2等長(需進位)
直接修改l1 -> Space Complexity = Ｏ(1)

時間複雜度：Ｏ(n)
空間複雜度：Ｏ(1)
"""

# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        carry = 0
        resultHead = cur = ListNode()

        while l1  or l2  or carry :
            cur.next = ListNode()
            cur = cur.next

            if l1 :
                carry += l1.val
                l1 = l1.next
            if l2 :
                carry += l2.val
                l2 = l2.next
            
            num = carry % 10 
            carry //= 10
            cur.val = num

        return resultHead.next
"""
comment:
另外創建一個List，判別l1,l2兩個是否有Node，依情況創建下一個Node

時間複雜度：Ｏ(n)
空間複雜度：Ｏ(n)
"""

