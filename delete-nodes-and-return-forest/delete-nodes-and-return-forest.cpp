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
    vector<TreeNode*> ans;
    void dfs(TreeNode*& root,vector<int>& to_delete)
    {
        if(root == nullptr) return;
        dfs(root->left,to_delete);
        dfs(root->right,to_delete);
        
        if(binary_search(to_delete.begin(),to_delete.end(),root->val))
        {
            if(root->left) ans.push_back(root->left);
            if(root->right) ans.push_back(root->right);
            
            root = nullptr;
        }
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) 
    {
        sort(to_delete.begin(),to_delete.end());
        dfs(root,to_delete);
        if(root != nullptr) ans.push_back(root);
        return ans;
    }
};