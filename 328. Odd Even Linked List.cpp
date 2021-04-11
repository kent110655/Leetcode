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
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL || head->next == NULL || head->next->next == NULL)
            return head;
        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* even_head = even;
        while(even != NULL && even->next != NULL)
        {
            odd->next = odd->next->next;
            odd = odd->next;
            even->next = even->next->next;
            even = even->next;
        }
        odd->next = even_head;
        return head;
    }
};

/*
Comment:
利用兩個pointer odd,even
分別從第一個、第二個開始以每次兩步的方式遍尋
把經過的點串連起來，最後把even list 接在odd list後面即可。
時間複雜度：Ｏ(n)
空間複雜度：Ｏ(1)
*/
