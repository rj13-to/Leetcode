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
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        return fun(root,0).second;
    }
};