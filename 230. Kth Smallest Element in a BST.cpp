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
    int kthSmallest(TreeNode* root, int k) {
        count = k;
        DFS(root);
        return ans;
    }
private:
    int count;
    int ans;
    void DFS(TreeNode* root)
    {
        if(root == NULL)
            return;
        DFS(root->left);
        count--;
        if(count == 0)
        {
            ans = root->val;
            return;
        }
        DFS(root->right);
    }
};
/*
Comment:
利用DFS找Inorder，BST的Inorder即是大小排序。
時間複雜度：Ｏ(n)
空間複雜度：Ｏ(1)
*/
