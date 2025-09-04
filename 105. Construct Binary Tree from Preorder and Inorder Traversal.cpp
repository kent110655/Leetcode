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
    unordered_map<int,int> inorderHash;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i = 0 ; i < inorder.size() ; i++)
        {
            inorderHash[inorder[i]] = i;
        }
        TreeNode* root = new TreeNode();
        root = getSubTree(preorder, 0, preorder.size(), 0, inorder.size());
        return root;
    }

    TreeNode* getSubTree(vector<int>& preorder, int preBegin, int preEnd, int inBegin, int inEnd)
    {
        if(preBegin >= preEnd)
        {
            return nullptr;
        }
        auto rootIndex = inorderHash[preorder[preBegin]];
        auto leftNodeCnt = rootIndex - inBegin;
        auto leftNode = getSubTree(preorder, preBegin+1, preBegin+1 + leftNodeCnt, inBegin, rootIndex);
        auto rightNode = getSubTree(preorder, preBegin+1 + leftNodeCnt, preEnd, rootIndex+1, inEnd);
        TreeNode* root = new TreeNode(preorder[preBegin]);
        root->left = leftNode;
        root->right = rightNode;
        return root;
    }
};

/*
Comment:
We use a recursive algorithm to solve the problem. First, we should understand the properties of preorder and inorder traversal. The first element in preorder is always the root. And the same element in inorder divides the inorder to left subtree and right subtree. Based on the two properties, we can find the root node and divide the other node to left part and right part. Then we can recursively construct the left node and right node to a tree with root and two subtree.
Time Complexity:Ｏ(n)
Space Complexity:Ｏ(n)
*/
