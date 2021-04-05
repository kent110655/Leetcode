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
    int treeHeight(TreeNode* root)
    {
        if(root == NULL)
            return 0;
        int RT = treeHeight(root->right);
        int LT = treeHeight(root->left);
        return max(RT,LT)+1;
    }
    
    bool isBalanced(TreeNode* root) {
        if(root==NULL)
            return true;
        int Rt = treeHeight(root->right);
        int Lt = treeHeight(root->left);
        if(max(Rt,Lt)-min(Rt,Lt)<2)
            return true && isBalanced(root->right) && isBalanced(root->left);
        else
            return false;
    }
};

/*
Comment:
利用Recursive。把左右子樹是否Balance的結果遞迴上去得出結果。
*/

/*
Algo 1:
class Solution {
public:
    bool result = true;
    int treeHeight(TreeNode* root)
    {
        if(root == NULL)
            return 0;
        int RT = treeHeight(root->right);
        int LT = treeHeight(root->left);
        if((RT-LT)<-1 || (RT-LT)>1)
            result = false;
        return max(RT,LT)+1;
    }
    bool isBalanced(TreeNode* root) {
        if(root==NULL)
            return true;
        treeHeight(root);
        return result;
    }
};
Comment:
利用Recursive求出每個Node的Height，並在其中確認左右子樹高度差是否balance。
*/
