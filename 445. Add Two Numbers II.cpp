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
private:
    stack<int>* buildStack(ListNode* head)
    {
        stack<int>* s = new stack<int>();
        while(head != NULL)
        {
            s->push(head->val);
            head = head->next;
        }
        return s;
    }
    
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int>* s1 = buildStack(l1);
        stack<int>* s2 = buildStack(l2);
        int carry = 0;
        ListNode* head = new ListNode(-1);
        while(!s1->empty() || !s2->empty() || carry != 0)
        {
            int n1 = (s1->empty()) ? 0 : s1->top();
            int n2 = (s2->empty()) ? 0 : s2->top();
            if(!s1->empty())
                s1->pop();
            if(!s2->empty())
                s2->pop();
            int sum = n1 + n2 + carry;
            ListNode* t = new ListNode(sum % 10);
            carry = sum / 10;
            t->next = head->next;
            head->next = t;
        }
        return head->next;
    }
};

/*
Comment:
利用兩個Stack分別來裝兩個linkedlist中的值。
再依序取出即可得反序數字。若stack空了就輸出0。
並且設置carry紀錄進位數。每一位數 sum = n1 + n2 + carry。
得出sum以後創一個新的Node接上新List直到所有位數完成為止。
時間複雜度：Ｏ(n)
空間複雜度：Ｏ(n)
*/
