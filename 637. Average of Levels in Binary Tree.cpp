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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ans;
        if(root->left == NULL && root->right == NULL)
        {
            ans.push_back(root->val);
            return ans;
        }
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            int qSize = q.size();       //此level要排出幾個
            double sum = 0;
            for(int i = 0; i < qSize; i++)
            {
                q.front();
                if(q.front()->left != NULL)
                    q.push(q.front()->left);
                if(q.front()->right != NULL)
                    q.push(q.front()->right);
                sum += (double)q.front()->val;
                q.pop();
            }
            ans.push_back(sum/qSize);
        }
        return ans;
    }
};
/*
Comment:
利用BFS求解，使用Queue來實現BFS。
使用queue的size()來得知這一level有幾個Node。
由此可知接下來幾個Node屬於同一個level，才可算Average。
時間複雜度：Ｏ(n)
空間複雜度：Ｏ(n)
*/
