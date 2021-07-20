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
    pair<int,TreeNode*> fun(TreeNode* root,int depth)
    {
        if(root==nullptr) return {0,nullptr};
        if(root->left==nullptr && root->right==nullptr) return {depth,root};
        pair<int,TreeNode*>left,right;
        left  = fun(root->left,depth+1);
        right = fun(root->right,depth+1);
        if(left.first == right.first) return {left.first,root};
        else if(left.first>right.first) return left;
        return right;
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        return fun(root,0).second;
    }
};
