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
    bool fun(TreeNode* root)
    {
        if(root == nullptr) return 0;
        bool ok = fun(root->left);
        if(!ok) root->left=nullptr;
        bool okk = fun(root->right);
        if(!okk) root->right = nullptr;
        return ok || okk || root->val;
    }
    TreeNode* pruneTree(TreeNode* root) {
        if(fun(root)) return root;
        else return nullptr;
    }
};