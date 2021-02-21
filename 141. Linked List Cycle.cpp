/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* fast=head;
        ListNode* slow=head;
        while(fast!=NULL && fast->next!=NULL)   //fast不到尾端的時候
        {
            fast=fast->next->next;
            slow=slow->next;
            if(fast == slow)
            {
                return true;
            }
        }
        return false;
    }
};

/*
comment:
利用fast pointer與slow pointer走遍整個linklist
如果有cycle，則fast pointer必追上slow pointer。
如果沒有cycle，fast pointer必先抵達尾端最後一個Node。
所以當fast pointer抵達tail Node時還沒遇上slow pointer，則沒有cycle。
時間複雜度：O(n) -->pointer走完整個linklist即可判別cycle。
*/
