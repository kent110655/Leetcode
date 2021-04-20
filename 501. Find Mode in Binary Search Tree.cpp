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
    vector<int> findMode(TreeNode* root) {
        if(root->left == NULL && root->right == NULL)
        {
            ans.push_back(root->val);
            return ans;
        }
        DFS(root);
        finalMax = maxCount;
        count = 0;
        cur = 0;
        DFS(root);
        return ans;
    }
private:
    int count = 0;
    int maxCount = INT_MIN;
    int finalMax;
    int cur = 0;
    vector<int> ans;
    void DFS(TreeNode* root)
    {
        if(root == NULL)
            return;
        DFS(root->left);
        visit(root->val);
        DFS(root->right);
    }
    
    void visit(int val)
    {
        if(count > 0 && val == cur)
        {
            count++;
        }
        else
        {
            count = 1;
            cur = val;
        }
        if(count > maxCount)
        {
            maxCount = count;
        }
        if(count == finalMax)
        {
            ans.push_back(val);
        }
    }
};
/*
Comment:
修改Algo 2的做法。
跑兩遍DFS，使空間複雜度降到Ｏ(1)。
第一遍DFS找出最終MaxCount。
第二遍DFS把count為MaxCount的val加入vector。
時間複雜度：Ｏ(n)
空間複雜度：Ｏ(1)
*/


/*
Algo 1:
class Solution {
public:
    vector<int> findMode(TreeNode* root) {
        DFS(root);
        vector<int> ans;
        int M = INT_MIN;
        for(auto u:map)
        {
            M = max(M, u.second);
        }
        for(auto u:map)
        {
            if(u.second == M)
                ans.push_back(u.first);
        }
        return ans;
    }
private:
    unordered_map<int, int> map;
    void DFS(TreeNode* root)
    {
        if(root == NULL)
            return;
        DFS(root->left);
        map[root->val]++;
        DFS(root->right);
    }
};
Comment:
利用DFS Inorder 掃一遍，存在hash table中，再從中找結果。
時間複雜度：Ｏ(n)
空間複雜度：Ｏ(n)
*/

/*
Algo 2:
class Solution {
public:
    vector<int> findMode(TreeNode* root) {
        if(root->left == NULL && root->right == NULL)
        {
            ans.push_back(root->val);
            return ans;
        }
        DFS(root);
        return ans;
    }
private:
    int count = 0;
    int maxCount = INT_MIN;
    int cur = 0;
    vector<int> ans;
    void DFS(TreeNode* root)
    {
        if(root == NULL)
            return;
        DFS(root->left);
        visit(root->val);
        DFS(root->right);
    }
    
    void visit(int val)
    {
        if(count > 0 && val == cur)
        {
            count++;
        }
        else
        {
            count = 1;
            cur = val;
        }
        if(count > maxCount)
        {
            maxCount = count;
            ans.clear();
        }
        if(count == maxCount)
        {
            ans.push_back(val);
        }
    }
};
Comment:
利用DFS Inorder順序由小到大掃一遍。
時間複雜度：Ｏ(n)
空間複雜度：Ｏ(n)
*/
