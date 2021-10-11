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
    int ma = 0;
    int fun(TreeNode* root)
    {
        if(root== nullptr) return 0;
        int a = fun(root->left);
        int b = fun(root->right);
        ma = max(ma,b+a);
        return max(b,a)+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        fun(root);
        return ma;
    }
};