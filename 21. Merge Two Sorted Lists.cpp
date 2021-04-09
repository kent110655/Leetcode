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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == NULL || l2 == NULL)
            return (l1 == NULL) ? l2:l1;
        if(l1->val < l2->val)
        {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        }
        else
        {
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == NULL || l2 == NULL)
            return (l1 == NULL) ? l2:l1;
        ListNode* p1 = l1;
        ListNode* p2 = l2;
        ListNode* result = new ListNode();
        ListNode* p3 = result;
        while(p1!=NULL && p2!=NULL)
        {
            if(p1->val > p2->val)
            {
                p3->next = p2;
                p2 = p2->next;
                p3 = p3->next;
            }
            else
            {
                p3->next = p1;
                p1 = p1->next;
                p3 = p3->next;
            }
        }
        if(p1 == NULL)
            p3->next = p2;
        else
            p3->next = p1;
        return result->next;
    }
};

Comment:
創建另一個list，分別比較兩個list，小的放入新創list。
時間複雜度：Ｏ(n)
空間複雜度：Ｏ(n)
*/
