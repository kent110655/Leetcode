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
    int findSecondMinimumValue(TreeNode* root) {
        if(root->left == NULL)
            return -1;
        findBigSub(root);
        if(renew == 0)
            return -1;
        return second;
    }
private:
    int second = INT_MAX;
    bool renew = 0;
    void findBigSub(TreeNode* root)
    {
        if(root->left == NULL)
            return ;
        if(root->left->val < root->right->val)
        {
            second = min(second, root->right->val);
            findBigSub(root->left);
            renew = 1;
        }
        else if(root->left->val > root->right->val)
        {
            second = min(second, root->left->val);
            findBigSub(root->right);
            renew = 1;
        }
        else
        {
            findBigSub(root->left);
            findBigSub(root->right);
        }
    }
};

/*
Comment:
Recursive求解。
把所有Node的左右SubNode較大者拿出來比較，其中最小者即為所求。
利用global variable second來更新。
利用一個bool renew來判斷是否有更新過(若所有點都一樣->沒更新過)
時間複雜度：Ｏ(n)
空間複雜度：Ｏ(1)
*/
