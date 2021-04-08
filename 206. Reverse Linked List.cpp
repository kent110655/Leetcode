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
    ListNode* reverseList(ListNode* head) {
        if(head == NULL)
            return NULL;
        ListNode* pre = NULL;       //紀錄前一個Node
        ListNode* cur = head;       //紀錄目前操作的Node
        ListNode* next = cur->next; //紀錄下一輪要操作的Node
        while(cur != NULL)
        {
            next = cur->next;   //更新cur到新位置(前移指向下輪要操作的Node)
            cur->next = pre;    //cur指向前一個Node (反轉)
            pre = cur;          //更新pre到新位置(向前移到cur的位置)
            cur = next;         //更新cur到新位置(向前移到next的位置)
        }
        return pre;
    }
};

/*
Comment:
https://www.youtube.com/watch?v=QuWBvSx9DeI
利用三個pointer:pre, cur, next去紀錄 前一個,正在操作,下一個將要操作 的Node。
時間複雜度：Ｏ(n)
空間複雜度：Ｏ(1)
*/
