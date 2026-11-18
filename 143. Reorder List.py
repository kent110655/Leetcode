# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reorderList(self, head: ListNode | None) -> None:
        """
        Do not return anything, modify head in-place instead.
        """
        fast, slow = head, head
        while fast != None and fast.next != None:
            fast = fast.next.next
            slow = slow.next
        reverseHead = slow.next
        slow.next = None
        
        # reverse the part2 list
        pre = None
        cur = reverseHead
        while cur != None:
            nextNode = cur.next
            cur.next = pre
            pre, cur = cur, nextNode
        head2 = pre
        
        # insert the part2 list into part1 list
        p = head
        q = head2
        while q != None:
            n1 = p.next
            n2 = q.next
            p.next = q
            q.next = n1
            p = n1
            q = n2
        return head

"""
Comment:
First, I use slow pointer and fast pointer to find the middle of the linked list. Second, I reverse the part2 linked list. Third, I insert the part2 linked list to the part1 linked list one by one.
Time Complexity:Ｏ(n)
Space Complexity:Ｏ(1)
"""
