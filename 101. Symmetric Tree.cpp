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
    bool isSymmetric(TreeNode* root) {
        return mirrorEqual(root->left, root->right);
    }
    
private:
    bool mirrorEqual(TreeNode* left, TreeNode* right)
    {
        if(left == NULL && right == NULL)
            return true;
        if(left == NULL || right == NULL)
            return false;
        return (left->val == right->val) 
            && mirrorEqual(left->left, right->right) 
            && mirrorEqual(left->right, right->left);
    }
};

/*
Comment:
利用Recursive求解。
因為是鏡像，所以左右子樹要互換比較。
時間複雜度：Ｏ(n)
空間複雜度：Ｏ(1)
*/
