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
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if(s == NULL)
            return false;
        return equalTree(s,t) || isSubtree(s->left, t) || isSubtree(s->right, t);
    }
    
private:
    bool equalTree(TreeNode* s, TreeNode* t)
    {
        if(s == NULL && t == NULL)
            return true;
        if(s == NULL || t == NULL)
            return false;
        return (s->val == t->val) 
            && equalTree(s->left, t->left) 
            && equalTree(s->right, t->right);
    }
};
/*
Comment:
使用Recursive尋找s是否有子樹與t相同
時間複雜度：Ｏ(max(n,m))
空間複雜度：Ｏ(max(n,m))
*/
