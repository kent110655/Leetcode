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
    int rob(TreeNode* root) {
        int l = 0;
        int r = 0;
        return solveRob(root, l, r);
    }
private:
    int solveRob(TreeNode* root, int& l, int& r)
    {
        if(root == NULL)
            return 0;
        int ll = 0;
        int lr = 0;
        int rl = 0;
        int rr = 0;
        l = solveRob(root->left, ll, lr);
        r = solveRob(root->right, rl, rr);
        return max(root->val + ll + lr + rl + rr, l + r);
    }
};

/*
Comment:
改進Algo 1。
把Recursive中算出的l,r用reference方式傳遞上去，避免重複計算。
時間複雜度：Ｏ(n)
空間複雜度：Ｏ(n)
*/

/*
Algo 1:
class Solution {
public:
    int rob(TreeNode* root) {
        if(root == NULL)
            return 0;
        if(root->left == NULL && root->right == NULL)
            return root->val;
        int val1 = root->val;
        if(root->left != NULL)
            val1 += rob(root->left->left) + rob(root->left->right);
        if(root->right != NULL)
            val1 += rob(root->right->left) + rob(root->right->right);
        int val2 = rob(root->left) + rob(root->right);
        return max(val1, val2);
    }
};
Comment:
利用Recursive。
回傳 max(root+rob(ll) + rob(lr) + rob(rl) + rob(rr), rob(l) + rob(r))
時間複雜度：Ｏ(n^2)
空間複雜度：Ｏ(n)
TLE
*/
