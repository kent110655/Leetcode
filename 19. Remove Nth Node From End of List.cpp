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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head->next == NULL)
            return NULL;
        ListNode* fast = head;
        ListNode* slow = head;
        while(n>0)
        {
            fast = fast->next;
            n--;
        }
        if(fast == NULL)
            return head->next;
        while(fast->next != NULL)
        {
            fast = fast->next;
            slow = slow->next;
        }
        slow->next = slow->next->next;
        return head;
    }
};

/*
Comment:
利用兩個pointer fast,slow。
1. fast先走n，slow留在head
2. fast,slow同速前進，直到fast走到最後一個，此時slow會在要刪Node的前一個。
（要刪元素是第L-n個Node）
時間複雜度：Ｏ(n)
空間複雜度：Ｏ(1)
*/

/*
Algo 1:
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head->next == NULL)
            return NULL;
        vector<ListNode*> v;
        ListNode* p = head;
        while(p != NULL)
        {
            v.push_back(p);
            p = p->next;
        }
        int delNum = v.size()-n;
        if(delNum == 0)
            return v[1];
        else if(delNum == v.size()-1)
        {
            v[delNum-1]->next = NULL;
        }
        else
            v[delNum-1]->next = v[delNum+1];
        return head;
    }
};
Comment:
把list的每個Node存在vector裡面，從而取得順序位置，再依n去刪除。
時間複雜度：Ｏ(n)
空間複雜度：Ｏ(n)
*/
