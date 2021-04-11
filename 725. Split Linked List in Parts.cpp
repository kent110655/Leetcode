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
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        vector<ListNode*> v(k,NULL);
        int i = 0;
        if(k == 1)
        {
            v[i] = root;
            return v;
        }
        ListNode* p = root;
        int len = 0;
        while(p != NULL)
        {
            p = p->next;
            len++;
        }
        int groupSize = (len / k != 0) ? len / k : 1;
        int extraCount = (len / k != 0) ? len % k : 0;
        p = root;
        int exCount=extraCount;
        while(exCount)
        {
            int count = groupSize+1;
            ListNode* head = p;
            for(int t = 0; t<count-1 ; count--)
                p = p->next;
            ListNode* next = p->next;
            p->next = NULL;
            v[i++] = head;
            p = next;
            exCount--;
        }
        int remain = k - extraCount;
        while(remain)
        {
            int count = groupSize;
            ListNode* head = p;
            if(head == NULL)
                v[i++] = NULL;
            else
            {
                for(int t = 0; t<count-1 ; count--)
                    p = p->next;
                ListNode* next = p->next;
                p->next = NULL;
                v[i++] = head;
                p = next;
            }
            remain--;
        }
        return v;
    }
};

/*
Comment:
先尋訪一遍List，得到List的len。
求得每part有幾個元素以及多一個的part有幾個。
從list開頭開始依照上面所得的資訊開始分段，並放入vector。
時間複雜度：Ｏ(n)
空間複雜度：Ｏ(k)
*/
