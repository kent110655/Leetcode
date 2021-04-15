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
        int leftCount = countNode(root->left);
        if(leftCount == k-1)
            return root->val;
        else if(leftCount > k-1)
            return kthSmallest(root->left, k);
        else
            return kthSmallest(root->right, k - leftCount -1);
    }
private:
    int countNode(TreeNode* root)
    {
        if(root == NULL)
            return 0;
        return 1 + countNode(root->left) + countNode(root->right);
    }
};

/*
Comment:
利用Recursive實作。
時間複雜度：Ｏ(n)
空間複雜度：Ｏ(1)
*/
/*
Algo 1:
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
Comment:
利用DFS找Inorder，BST的Inorder即是大小排序。
時間複雜度：Ｏ(n)
空間複雜度：Ｏ(1)
*/
