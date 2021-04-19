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
    bool findTarget(TreeNode* root, int k) {
        Inorder(root);
        int i = 0;
        int j = v.size()-1;
        while(i < j)
        {
            if(v[i] + v[j] == k)
                return true;
            else if(v[i] + v[j] > k)
                j--;
            else
                i++;
        }
        return false;
    }
private:
    vector<int> v;
    void Inorder(TreeNode* root)
    {
        if(root == NULL)
            return ;
        Inorder(root->left);
        v.push_back(root->val);
        Inorder(root->right);
    }
};
/*
Comment:
利用利用DFS Inorder掃一遍，按照小到大順序存入vector，再以兩個pointer找目標即可。
*/

/*
Algo 1:
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        return DFS(root, k);
    }
private:
    unordered_set<int> set;
    bool DFS(TreeNode* root, int k)
    {
        if(root == NULL)
            return false;
        bool l = DFS(root->left, k);
        if(set.count(k - root->val))
            return true;
        else
            set.insert(root->val);
        bool r = DFS(root->right, k);
        return l || r;
    }
};


Comment:
利用DFS Inorder掃一遍，在hash table找到回傳true，沒找到把value存入hash table
時間複雜度：Ｏ(n)
空間複雜度：Ｏ(n)
*/
