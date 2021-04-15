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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL || root == p || root == q)
            return root;
        TreeNode* l = lowestCommonAncestor(root->left, p, q);
        TreeNode* r = lowestCommonAncestor(root->right, p ,q);
        if(l && r)
            return root;
        return (l != NULL) ? l : r;
    }
};
/*
Comment:
以Postorder遍尋。
Case 1:
當Node為目標時，回傳目標。
此有兩種情況：
1. 找到目標回傳上去
2. 此目標是另一個目標的Ancestor，另一個目標在此Node的子樹中

Case 2:
當Node為NULL時，回傳NULL。
(掃到tail還沒找到目標)

若Case 1,2不成立，則繼續向下遞迴。
遞迴中分為左右子樹遞迴l,r。

Case 3:
當l,r皆有回傳值(皆非NULL)，則此Node即為LCA，回傳Node上去。
(代表p,q各在兩個子樹中)

Case 4:
當l,r一個有回傳值、另一個回傳NULL，回傳有回傳值的那個。
(代表另一個目標不在此Node子樹之中，回傳找到的一個目標)

Case 5:
當l,r皆為NULL，回傳NULL。
(代表兩個目標皆不在此Node子樹之中，回傳NULL)

Case 6:
目標是另一個目標的Ancestor，此目標即為LCA (Case1的情況2)
會一路遞迴到root的Case4，並且回傳Ancestor的那個目標。

時間複雜度：Ｏ(n)
空間複雜度：Ｏ(h)
*/
