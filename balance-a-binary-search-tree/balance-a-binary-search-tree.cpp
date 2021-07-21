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
    vector<int>v;
    void fun(TreeNode* root)
    {
        if(root==nullptr) return;
        v.push_back(root->val);
        fun(root->left);
        fun(root->right);
    }
    TreeNode* makeTree(int st,int ed)
    {
        if(st >= ed) return nullptr;
        int mid = (st+ed)/2;
        TreeNode* f = new TreeNode(v[mid]);
        f->left = makeTree(st,mid);
        f->right= makeTree(mid+1,ed);
        return f;
    }
    TreeNode* balanceBST(TreeNode* root) 
    {
        fun(root);
        sort(v.begin(),v.end());
        return makeTree(0,v.size());
    }
};