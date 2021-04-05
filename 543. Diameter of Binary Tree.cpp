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
    int result=INT_MIN;
    int height(TreeNode* root)
    {
        if(root==NULL)
            return 0;
        int RT = height(root->right);
        int LT = height(root->left);
        result = max(result , RT+LT);
        return max(RT,LT)+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        height(root);
        return result;
    }
};

/*
Comment:
利用Recursive。在遞迴height中計算每個Node的左右子樹高的和，並記錄下最大的和即為所求。
*/
