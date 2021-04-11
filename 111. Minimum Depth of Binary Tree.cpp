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
    int minDepth(TreeNode* root) {
        if(root == NULL)
            return 0;
        if(root->left == NULL && root->right == NULL)
            return 1;
        if(root->left == NULL || root->right == NULL)
            return (root->left == NULL) ? minDepth(root->right)+1 : minDepth(root->left)+1;
        return min(minDepth(root->left), minDepth(root->right))+1;
    }
};

/*
Comment:
利用Recursive求解。
左右子樹皆為NULL的時候即為leaf。
若其一子樹為NULL，則繼續遞迴另一個子樹。
若兩子樹皆有，則取其中遞迴出來小的。
時間複雜度：Ｏ(n)
空間複雜度：Ｏ(1)
*/
