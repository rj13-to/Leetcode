class Solution {
public:
    int dfs(TreeNode* root,int ma,int  mi)
    {
        int k;
        if(!root) return 0;
        k=max(abs(root->val-ma),abs(root->val-mi));
        if(ma<root->val) ma=root->val;
        if(mi>root->val) mi=root->val;
        return max(k,max(dfs(root->left,ma,mi),dfs(root->right,ma,mi)));
    }
    int maxAncestorDiff(TreeNode* root) {
        return dfs(root,root->val,root->val);
    }
};