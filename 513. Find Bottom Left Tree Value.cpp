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
    int findBottomLeftValue(TreeNode* root) {
        if(root->left == NULL && root->right == NULL)
            return root->val;
        queue<TreeNode*> q;
        q.push(root);
        int ans;
        while(!q.empty())
        {
            int qSize = q.size();
            for(int i=0; i < qSize; i++)
            {
                TreeNode* node = q.front();
                if(i == 0)
                    ans = node->val;
                if(node->left != NULL)
                    q.push(node->left);
                if(node->right != NULL)
                    q.push(node->right);
                q.pop();
            }
        }
        return ans;
    }
};
/*
Comment:
利用BFS。並紀錄更新每個level開頭的node。
時間複雜度：Ｏ(n)
空間複雜度：Ｏ(n)
*/
