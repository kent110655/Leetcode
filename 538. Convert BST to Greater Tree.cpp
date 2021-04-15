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
    TreeNode* convertBST(TreeNode* root) {
        if(root == NULL)
            return root;
        DFS(root);
        return root;
    }
private:
    int sum = 0;
    void DFS(TreeNode* root)
    {
        if(root == NULL)
            return;
        DFS(root->right);
        sum += root->val;
        root->val = sum;
        DFS(root->left);
    }
};

/*
Comment:
利用DFS遍尋找Inorder的反順序(左右子樹遞迴相反順序即可)
用反Inorder順序更新累加的key。
時間複雜度：Ｏ(n)
空間複雜度：Ｏ(1)
*/
