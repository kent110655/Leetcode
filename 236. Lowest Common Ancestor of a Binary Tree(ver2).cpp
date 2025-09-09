/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int pv = -1;
    int qv = -1;
    TreeNode* lca;
    bool firstMatch = true;
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        this->pv = p->val;
        this->qv = q->val;
        DFS(root);
        return lca;
    }
    bool DFS(TreeNode* node)
    {
        if(node == nullptr)
            return false;
        bool leftExist = DFS(node->left);
        bool rightExist = DFS(node->right);
        bool currentMatch = node->val == pv || node->val == qv;
        if((leftExist && rightExist) || (leftExist && currentMatch) || (rightExist && currentMatch) && firstMatch)
            lca = node;

        return leftExist || rightExist || currentMatch;
    }
};

/*
Comment:
We perform the DFS to traverse all the nodes. In the process, we check whether the value of each node is equal to target p or target q. Then we can return whether the subtree contains target. When a node has two matches among left subtree, right subtree, or itself, we can get the lowest common ancestor.
Time Complexity:Ｏ(n)
Space Complexity:Ｏ(h)
*/
