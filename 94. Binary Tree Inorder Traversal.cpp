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
    vector<int> inorderTraversal(TreeNode* root) {
        if(root == NULL)
            return ans;
        if(root->left == NULL && root->right == NULL)
        {
            ans.push_back(root->val);
            return ans;
        }
        DFS(root);
        return ans;
    }
private:
    vector<int> ans;
    void DFS(TreeNode* root)
    {
        if(root == NULL)
            return;
        DFS(root->left);
        ans.push_back(root->val);
        DFS(root->right);
    }
};
/*
Comment:
DFS。此做法利用Recursive實作。
*/
