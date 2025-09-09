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
    int deepestNodeCnt = 0;
    int deepestDepth = -1;
    TreeNode* ancestor;
    bool isFirstAncestor = true;
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        UpdateDeepestCnt(root, -1);
        FindDeepestNodeCnt(root, -1);
        return ancestor;
    }

    void UpdateDeepestCnt(TreeNode* node, int depth)
    {
        if(node == nullptr)
            return;
        depth++;
        if(node->left == nullptr && node->right == nullptr)
        {
            if(depth > deepestDepth)
            {
                deepestDepth = depth;
                deepestNodeCnt = 1;
            }
            else if(depth == deepestDepth)
            {
                deepestNodeCnt += 1;
            }
        }
        UpdateDeepestCnt(node->left, depth);
        UpdateDeepestCnt(node->right, depth);
    }

    int FindDeepestNodeCnt(TreeNode* node, int depth)
    {
        if(node == nullptr)
            return 0;
        depth++;
        int nodeCnt = FindDeepestNodeCnt(node->left, depth) + FindDeepestNodeCnt(node->right, depth) + (depth == deepestDepth ? 1 : 0);
        if(nodeCnt == deepestNodeCnt && isFirstAncestor)
        {
            ancestor = node;
            isFirstAncestor = false;
        }
        if(node->left == nullptr && node->right == nullptr)
        {
            return depth == deepestDepth ? 1 : 0;
        }
        return nodeCnt;
    }
};

/*
Comment:
First, we use DFS to traverse all the nodes and record the deepest depth and the count of deepest nodes. So we can get the deepest depth and the count of deepest nodes. Then, we traverse all the nodes again and simultaneously calculate the count of deepest nodes in the subtree. The first node matched the count of deepest nodes is the lowest common ancestor.
Time Complexity: Ｏ(n)
Space Complexity: Ｏ(h) , h: tree height, worst: Ｏ(n), best/average:Ｏ(logn)
*/
