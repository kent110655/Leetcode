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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return Convert(nums,0,nums.size()-1);
    }
private:
    TreeNode* Convert(vector<int>& nums, int start, int end)
    {
        if(start > end)
        {
            return NULL;
        }
        else if(start == end)
        {
            TreeNode* root = new TreeNode(nums[start]);
            return root;
        }
        int mid = start + (end - start) / 2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = Convert(nums, start, mid-1);
        root->right = Convert(nums, mid+1, end);
        return root;
    }
};
/*
Comment:
找出sorted array的中點，設置中點Node為root Node。
利用中點把array分成兩部分，左部分為左子樹，右部分為右子樹。
再繼續Recursive直到所有Node皆配製成Tree。
時間複雜度：Ｏ(n)
空間複雜度：Ｏ(log(n)) (Recursive深度：log n)
*/
