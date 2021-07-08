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
    void dfs(TreeNode* root,int val)
    {
        if(root->val>val){
            if(root->left==nullptr) root->left=new TreeNode(val);
            else dfs(root->left,val);
        }
        else if(root->right==nullptr) root->right=new TreeNode(val);
        else dfs(root->right,val);
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode* root=new TreeNode(preorder[0]);
        for(int i=1;i<preorder.size();i++)
        {
            dfs(root,preorder[i]);
        }
        return root;
    }
};