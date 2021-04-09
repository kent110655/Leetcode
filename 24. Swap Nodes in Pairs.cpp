/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return head;
        ListNode* NewHead = head->next;
        ListNode* p = swapPairs(head->next->next);
        head->next->next = head;
        head->next = p;
        return NewHead;
    }
};

/*
Comment:
利用Recursive。
時間複雜度：Ｏ(n)
空間複雜度：Ｏ(1)
*/
