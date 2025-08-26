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
    int maxSum = INT_MIN;
    int maxPathSum(TreeNode* root) {
        getMaxSumPath(root);
        return maxSum;
    }
private:
    int getMaxSumPath(TreeNode* node)
    {
        if(node == NULL) // leaf
            return 0;
        auto leftMaxSum = max(getMaxSumPath(node->left), 0);
        auto rightMaxSum = max(getMaxSumPath(node->right), 0);
        maxSum = max(maxSum, leftMaxSum + rightMaxSum + node->val);
        return max(leftMaxSum, rightMaxSum) + node->val;
    }
};

/*
Comment:
We use DFS to traverse all the nodes and record the max sum in the traversal. In the process of the traversal, we should consider two situations. One is choosing the left subtree path and the right subtree path without path to root, and the other one is choosing the bigger one between left subtree and right subtree for path to root. Record the bigger one between first situation and maxSum. And then return the second situation sum to next recursive.
Time Complexity:Ｏ(n)
Space Complexity:Ｏ(n)
*/
