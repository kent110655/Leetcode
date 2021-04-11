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
    bool isPalindrome(ListNode* head) {
        if(head->next == NULL)
            return true;
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast != NULL && fast->next != NULL)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        if(fast != NULL)
            slow = slow->next;
        ListNode* tail = InverseList(slow);
        while(tail != NULL)
        {
            if(head->val != tail->val)
                return false;
            head = head->next;
            tail = tail->next;
        }
        return true;
    }
    
    ListNode* InverseList(ListNode* start)
    {
        ListNode* pre = NULL;
        ListNode* cur = start;
        ListNode* next = start;
        while(cur != NULL)
        {
            next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        return pre;
    }
};

/*
Comment:
改動：
利用快慢兩個pointer求終點。
fast一次走兩步，slow一次走一步，當fast走到末端的時候slow即為中點。
*/

/*
Algo 1:
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(head->next == NULL)
            return true;
        ListNode* p = head;
        int size = 0;
        while(p != NULL)
        {
            p = p->next;
            size++;
        }
        bool midpoint = (size % 2 == 0) ? 0 : 1;
        int halfSize = (size % 2 == 0) ? size/2 : (size-1)/2;
        
        p = head;
        int count = halfSize;
        while(count)
        {
            p = p->next;
            count--;
        }
        if(midpoint)
            p = p->next;
        ListNode* tail = InverseList(p);
        count = halfSize;
        while(count)
        {
            if(head->val != tail->val)
                return false;
            head = head->next;
            tail = tail->next;
            count--;
        }
        return true;
    }
    
    ListNode* InverseList(ListNode* start)
    {
        ListNode* pre = NULL;
        ListNode* cur = start;
        ListNode* next = start;
        while(cur != NULL)
        {
            next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        return pre;
    }
};

Comment:
走訪一遍list得知長度及中點。
把後半段的list反轉，再把前半段與後半段list比較val是否相同即可。
*/
