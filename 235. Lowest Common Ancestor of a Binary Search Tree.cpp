/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root->val > p->val && root->val > q->val)
            return lowestCommonAncestor(root->left, p, q);
        else if(root->val < p->val && root->val < q->val)
            return lowestCommonAncestor(root->right, p, q);
        return root;
    }
};
/*
Comment:
利用Recursive求解。
當p,q皆在當前Node的其中一子樹中，則此Node不可能為LCA
所以遞迴到下一個子樹的root即可。
當遞迴到 （p,q在Node的兩側子樹各一） or （Node即為p或q）
則此Node即為LCA
時間複雜度：Ｏ(n)
空間複雜度：Ｏ(1)
*/
