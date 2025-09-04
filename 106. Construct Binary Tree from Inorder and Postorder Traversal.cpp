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
    vector<int> post;
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for(int i = 0; i < inorder.size(); i++)
        {
            inorderHash[inorder[i]] = i;
        }
        post = postorder;
        TreeNode* root = new TreeNode();
        root = getSubtree(0, inorder.size()-1, 0, postorder.size()-1);
        return root;
    }

    TreeNode* getSubtree(int inorderStart, int inorderEnd, int postStart, int postEnd)
    {
        if(postStart > postEnd || inorderStart > inorderEnd)
        {
            return nullptr;
        }
        int rootInorderIndex = inorderHash[post[postEnd]];
        auto rightNodeCnt = inorderEnd - rootInorderIndex;
        auto leftNodeCnt = rootInorderIndex - inorderStart;
        auto rightSubtree = getSubtree(rootInorderIndex+1, inorderEnd, postEnd-1 - rightNodeCnt + 1, postEnd-1);
        auto leftSubtree = getSubtree(inorderStart, rootInorderIndex-1, postStart, postStart + leftNodeCnt - 1);
        TreeNode* root = new TreeNode();
        root->val = post[postEnd];
        root->right = rightSubtree;
        root->left = leftSubtree;
        return root;
    }
};

/*
Comment:
Use recursive algorithm to solve the problem. Based on the properties of postorder and inorder, the last element in postorder must be the root. And the element divides the inorder traversal into left and right subtrees. So we can build the left and right subtrees and combine them with root to construct the tree.
Time Complexity:Ｏ(n)
Space Complexity:Ｏ(n)
*/
