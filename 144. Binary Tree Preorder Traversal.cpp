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
    vector<int> preorderTraversal(TreeNode* root) {
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
        ans.push_back(root->val);
        DFS(root->left);
        DFS(root->right);
    }
};
/*
Comment:
DFS。此做法利用Recursive實作。
*/

/*
Algo 1:
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(root == NULL)
            return ans;
        if(root->left == NULL && root->right == NULL)
        {
            ans.push_back(root->val);
            return ans;
        }
        stack<TreeNode*> s;
        s.push(root);
        while(!s.empty())
        {
            TreeNode* node = s.top();
            s.pop();
            if(node->right != NULL)
                s.push(node->right);
            if(node->left != NULL)
                s.push(node->left);
            ans.push_back(node->val);
        }
        return ans;
    }
};
Comment:
利用DFS。
此作法為iterator實作法。
*/
