class Solution {
public:
    void fun(TreeNode*& root,int target)
    {
        if(root == nullptr) return ;
        fun(root->left,target);
        fun(root->right,target);
        if(root->val==target && root->left==nullptr && root->right==nullptr)  root=nullptr;
    }
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        fun(root,target);
        return root;
    }
};