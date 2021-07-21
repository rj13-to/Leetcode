class Solution {
public:
    vector<int>v;
    void dfs(TreeNode* root)
    {
        if(root==nullptr) return ;
        v.push_back(root->val);
        dfs(root->left);
        dfs(root->right);
    }
    bool search(TreeNode* root, int target)
    {
        if(root==nullptr) return 0;
        if(root->val==target) return 1;
        else if(root->val>target) return search(root->left,target);
        else return search(root->right,target);
    }
    bool isValidBST(TreeNode* root) {
        dfs(root);
        sort(v.begin(),v.end());
        for(int i=0;i<v.size();i++)
        {
            if(i!=0 && v[i]==v[i-1]) return false;
            if(!search(root,v[i])) return false;
        }
        return true;
    }
};