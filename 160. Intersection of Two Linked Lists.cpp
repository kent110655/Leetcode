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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA==NULL || headB==NULL)
            return NULL;
        ListNode* p1 = headA;
        ListNode* p2 = headB;
        while(p1 != p2)
        {
            p1 = (p1 == NULL) ? headB : p1->next;
            p2 = (p2 == NULL) ? headA : p2->next;
        }
        return p1;
    }
};

/*
Comment:
設置ListA的獨立段長度 = a
設置ListB的獨立段長度 = b
ListA與ListB共同段的長度 = c
可得知 a+c +b = b+c +a
所以
pointer p1 跑完ListA後跑ListB
pointer p2 跑完ListB後跑ListA
-> 若有交點，p1,p2會在交點重合。
-> 若沒有交點，則p1,p2會同時抵達NULL。(a+c + b+c == b+c + a+c)
時間複雜度：Ｏ(n)
空間複雜度：Ｏ(1)
*/

/*
Algo 1:
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* p1 = new ListNode();
        ListNode* p2 = new ListNode();
        unordered_map<ListNode*,int> umap;
        p1 = headA;
        p2 = headB;
        while(p1!=NULL)
        {
            umap[p1]++;
            p1 = p1->next;
        }
        while(p2!=NULL)
        {
            if(umap[p2])
            {
                return p2;
            }
            p2 = p2->next;
        }
        return NULL;
    }
};
Comment:
先掃一遍listA，並把listA所有Node紀錄在hash table。
掃一遍listB，把掃過的listB中的Node去hash table尋找是否存在，存在即交點，不存在即沒交點。
時間複雜度：Ｏ(n)
空間複雜度：Ｏ(n)
*/
