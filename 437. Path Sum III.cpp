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
private:
    unordered_map<int,int> umap;
public:
    int pathNum(TreeNode* root, int cur, int sum)
    {
        if(root == NULL)
            return 0;
        cur += root->val;
        int res = umap[cur - sum];
        umap[cur]++;
        res += pathNum(root->left, cur, sum) + pathNum(root->right, cur, sum);
        umap[cur]--;
        return res;
    }
    
    int pathSum(TreeNode* root, int sum) 
    {
        if(root == NULL)
            return 0;
        umap[0]=1;
        return pathNum(root, 0, sum);
    }
};

/*
Comment:
利用hash table紀錄已走過的連續累積和
當走到新的Node，尋找hash table中是否有(cur-sum)存在。
若有，這代表走過的路徑中有一段連續段扣掉後即為sum。
當遞迴回去的時候需要把hash table中退回去的路徑紀錄刪掉。
時間複雜度：Ｏ(n)
空間複雜度：Ｏ(h)
說明：
https://www.youtube.com/watch?v=uZzvivFkgtM
*/

/*
Algo 1:
class Solution {
public:
    int NumPath(TreeNode* root, int sum)
    {
        if(root==NULL)
            return 0;
        sum -= root->val;
        return (sum == 0 ? 1:0) + NumPath(root->left, sum) + NumPath(root->right, sum);
    }
    
    int pathSum(TreeNode* root, int sum) {
        if(root==NULL)
            return 0;
        return NumPath(root, sum) + pathSum(root->left, sum) + pathSum(root->right, sum);
    }
};
Comment:
利用Recursive。
NumPath的遞迴代表同一個出發點的所有路徑。
pathSum的遞迴代表不同出發點的所有路徑。
時間複雜度：Ｏ(n^2)
空間複雜度：Ｏ(n)
*/
