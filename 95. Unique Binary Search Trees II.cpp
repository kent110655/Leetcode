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
	vector<TreeNode*> generateTrees(int n) {
		if (n == 0) return{};
		vector<vector<TreeNode*>> dp(n + 1);
		dp[0] = vector<TreeNode*>{ nullptr };
		dp[1] = vector<TreeNode*>{ new TreeNode(1) };
		for (int i = 2; i <= n; ++i) {
			for (int j = 0; j < i; ++j) {
				for (TreeNode* nodel : dp[j]) {
					for (TreeNode* noder : dp[i - j - 1]) {
						TreeNode* node = new TreeNode(j + 1);
						node->left = nodel;
						node->right = clone(noder, j + 1);
						dp[i].push_back(node);
					}
				}
			}
		}
		return dp.back();
	}
private:
	TreeNode* clone(TreeNode* root, int offset) {
		if (!root) return nullptr;
		TreeNode* tmp = new TreeNode(root->val + offset);
		tmp->left = clone(root->left, offset);
		tmp->right = clone(root->right, offset);
		return tmp;
	}
};
/*
Algo 2:DP
Comment:
對於比j小的元素，共用了結點，對於比他大的，重新申請了空間，在申請空間的時候加上偏移量。
clone():處理位移offset。
右子樹需要考慮root的數值，所以會有一個 offset = root的value。clone內部的遞迴都要有offset。

以n=3為例：
dp[0] = {}
dp[1] = 1
dp[2] = 1        2
         \      /
          2    1

dp[3]:(i=3)

(j=0) dp[0],dp[2]:
1           1
 \           \
  2           3
   \         / 
    3       2

(j=1) dp[1],dp[1]:
   2
  / \
 1   3

(j=2) dp[2],dp[0]:
      3        3
     /        /
    2        1
   /          \ 
  1            2


*/

/*
algo 1:
class Solution {
public:
    vector<TreeNode*> generateSubtree(int n1,int n2)
    {
        vector<TreeNode*> tree;
        if(n1>n2)
        {
            tree.push_back(NULL);
            return tree;
        }
        else if(n1==n2)
        {
            TreeNode* root = new TreeNode(n1);
            tree.push_back(root);
            return tree;
        }
        for(int i=n1;i<=n2;i++)
        {
            vector<TreeNode*> leftTree = generateSubtree(n1,i-1);
            vector<TreeNode*> rightTree = generateSubtree(i+1,n2);
            for(auto leftT:leftTree)
            {
                for(auto rightT:rightTree)
                {
                    TreeNode* root = new TreeNode(i,leftT,rightT);
                    tree.push_back(root);
                }
            }
        }
        return tree;
    }
    
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> ans;
        if(n<1)
            return ans;
        return generateSubtree(1,n);
    }
};
Comment:
利用Recursion依序把可能的SubTree做出，並把所有可能性列出。
generateSubtree(int n1,int n2)：回傳由Node n1 到 Node n2 組成的tree
P.S. vector需要push_back(NULL)！
*/
