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
    vector<int> nextLargerNodes(ListNode* head) {
        ListNode* p = head;
        int cnt = 0;
        while(p != nullptr)
        {
            cnt++;
            p = p->next;
        }
        stack<pair<int, int>> s;
        vector<int> result(cnt);
        int index = 0;
        while(head != nullptr)
        {
            if(s.empty() || s.top().second > head->val)
            {
                s.push({index, head->val});
            }
            else
            {
                while(!s.empty() && s.top().second < head->val)
                {
                    result[s.top().first] = head->val;
                    s.pop();
                }
                s.push({index, head->val});
            }
            head = head->next;
            index++;
        }
        return result;
    }
};

/*
Comment:
We use a stack to store the elements which doesn't find the next greater value. To update the result vector, we also store the index in the stack. Then we compare the top of the element in the stack to the current value. If current value is greater than the element in stack, it means the next greater value of the element is the current value. So we update the result vector with index. Then we push the current value into the stack because the current value not yet find the answer. In the end, the element in the stack all not find the next greater value, and their answer of the element are all 0.
Time Complexity: Ｏ(n)
Space Complexity: Ｏ(n)
*/
