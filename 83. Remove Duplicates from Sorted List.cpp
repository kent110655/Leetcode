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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return head;
        head->next = deleteDuplicates(head->next);
        return (head->val == head->next->val) ? head->next : head;
    }
};

/*
Comment:
利用Recursive。
時間複雜度：Ｏ(n)
空間複雜度：Ｏ(1)
*/

/*
Algo 1:
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL)
            return NULL;
        ListNode* cur = head;
        ListNode* pre = NULL;
        ListNode* next = cur->next;
        while(cur != NULL && next != NULL)
        {
            while(next != NULL && cur->val == next->val )
            {
                next = next->next;
            }
            cur->next = next;
            if(next == NULL)
                break;
            cur = cur->next;
            next = next->next;
        }
        return head;
    }
};

Comment:
利用兩個pointer cur,next紀錄現在的Node與下一個Node。
時間複雜度：Ｏ(n)
空間複雜度：Ｏ(1)
*/
