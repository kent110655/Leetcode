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
    int getMinimumDifference(TreeNode* root) {
        DFS(root);
        return diff;
    }
private:
    int diff = INT_MAX;
    TreeNode* pre = NULL;
    void DFS(TreeNode* root)
    {
        if(root == NULL)
            return;
        DFS(root->left);
        if(pre != NULL)
            diff = min(diff, abs(pre->val - root->val));
        pre = root;
        DFS(root->right);
    }
};

/*
Comment:
利用DFS Inorder從小掃到大，紀錄之間的差距取最小即可。
時間複雜度：Ｏ(n)
空間複雜度：Ｏ(h)
*/
