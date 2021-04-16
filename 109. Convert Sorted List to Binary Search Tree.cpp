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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if(head == NULL)
            return NULL;
        else if(head->next == NULL)
            return new TreeNode(head->val);
        ListNode* p = head;
        int len = 0;
        while(p != NULL)
        {
            len++;
            p = p->next;
        }
        return buildBST(head, 0, len-1);
    }
private:
    TreeNode* buildBST(ListNode* & head, int start, int end)
    {
        if(start > end)
            return NULL;
        int mid = start + (end - start)/2;
        TreeNode* left = buildBST(head, start, mid-1);
        TreeNode* root = new TreeNode(head->val);
        head = head->next;
        root->left = left;
        TreeNode* right = buildBST(head, mid+1, end);
        root->right = right;
        return root;
    }
};
/*
Comment:
利用Inorder遍尋的方式建構BST。
head pointer利用&的方式傳遞在Recursive之中，同時只會有一種head值
Inorder遍尋，當left遞迴結束到right遞迴要開始的時候，創建目前head指向的Node，並把head pointer指向下一個將要創建Node的目標，並且把遞迴回來的left子樹接上Node，，再接著遞迴right子樹的部分，等right子樹遞迴回來後再接上Node，最後在回傳Node即可。
此種做法只需掃一遍linkedList即可完成：
T(n) = 2T(n/2) + Ｏ(1) -> Ｏ(n)
時間複雜度：Ｏ(n)
空間複雜度：Ｏ(log(n))
*/

/*
Algo 1:
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if(head == NULL)
            return NULL;
        else if(head->next == NULL)
            return new TreeNode(head->val);
        return buildBST(head);
    }
private:
    TreeNode* buildBST(ListNode* head)
    {
        if(head == NULL)
            return NULL;
        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* pre = head;
        while(fast != NULL && fast->next != NULL)
        {
            fast = fast->next->next;
            pre = slow;
            slow = slow->next;
        }
        if(slow == head)
        {
            TreeNode* root = new TreeNode(slow->val);
            return root;
        }
        pre->next = NULL;
        TreeNode* root = new TreeNode(slow->val);
        root->left = buildBST(head);
        root->right = buildBST(slow->next);
        return root;
    }
};

Comment:
利用兩個pointer slow,fast找出中點，設置中點Node為root Node。
利用pointer pre來紀錄中點前的Node，以便斷開LinkedList。
利用中點把array分成兩部分，左部分為左子樹，右部分為右子樹。
再繼續Recursive直到所有Node皆配製成Tree。
此做法每個Recursion中皆要花Ｏ(n)去找中點：
T(n) = 2T(n/2) + Ｏ(n) -> Ｏ(nlog(n))
時間複雜度：Ｏ(nlog(n))
空間複雜度：Ｏ(log(n))
*/


