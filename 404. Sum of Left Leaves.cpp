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
    int sumOfLeftLeaves(TreeNode* root) {
        if(root == NULL)
            return 0;
        if(root->left == NULL)
            return sumOfLeftLeaves(root->right);
        if(root->left->left == NULL && root->left->right == NULL)
            return root->left->val + sumOfLeftLeaves(root->right);
        return sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
    }
};

/*
Comment:
Recursive。
root=NULL return 0;
root沒有左Node return sumOfLeftLeaves(root->right)
root的左右皆為leaf return 左Node值＋sumOfLeftLeaves(root->right)
都不是 return sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right)
時間複雜度：Ｏ(n)
空間複雜度：Ｏ(1)
*/
