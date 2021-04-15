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
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        if(root == NULL)
            return root;
        else if(root->val < low)
            return trimBST(root->right, low, high);
        if(root->val > high)
            return trimBST(root->left, low, high);
        root->left = trimBST(root->left, low, high);
        root->right = trimBST(root->right, low, high);
        return root;
    }
};

/*
Comment:
利用Recursive來遍尋實作。
比Algo 1 要來的簡短好看。
時間複雜度：Ｏ(n)
空間複雜度：Ｏ(1)
*/

/*
Algo 1:
class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        L = low;
        H = high;
        while(root->val > H || root->val < L)
        {
            if(root->val > H)
                root = root->left;
            else if(root->val < L)
                root = root->right;
            if(root == NULL)
                break;
        }
        DFS(root);
        return root;
    }
private:
    int L;
    int H;
    void DFS(TreeNode* root)
    {
        if(root == NULL)
            return;
        if(root->left!= NULL && root->left->val < L)
        {
            root->left = root->left->right;
            DFS(root);
        } 
        if(root->right != NULL && root->right->val > H)
        {
            root->right = root->right->left;
            DFS(root);
        }
        DFS(root->left);
        DFS(root->right);
    }
};
Comment:
先確認root是否符合範圍，如不符合則往下更改root直到符合為止。
利用DFS遍尋。
當前Node的左Node < L ，則當前Node的左端接上左Node的右Node。
當前Node的右Node > R ，則當前Node的右端接上右Node的左Node。
時間複雜度：Ｏ(n)
空間複雜度：Ｏ(1)
*/
