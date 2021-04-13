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
    int longestUnivaluePath(TreeNode* root) {
        if(root == NULL)
            return 0;
        longestPath(root);
        return ans;
    }
private:
    int ans = 0;
    int longestPath(TreeNode* root)
    {
        if(root == NULL)
            return 0;
        int left,right;
        if(root->left == NULL)
            left = 0;
        else
        {
            int leftPath = longestPath(root->left);
            left = (root->val == root->left->val) ? leftPath + 1 : 0;
        }
        if(root->right == NULL)
            right = 0;
        else
        {
            int rightPath = longestPath(root->right);
            right = (root->val == root->right->val) ? rightPath + 1 : 0;
        }
        ans = max(ans, left + right);
        return max(left , right);
    }
};

/*
Comment:
設計一個function：
Step1:
Recursive取得必經過root的最大path（左子樹＋右子樹＋root）
並更新global variable ans紀錄下最大path長度
Step2:
return 結尾為root的最大path（(左子樹 or 右子樹) ＋ root）
（只可用其中一個子樹來算path）
時間複雜度：Ｏ(n)
空間複雜度：Ｏ(1)
*/
