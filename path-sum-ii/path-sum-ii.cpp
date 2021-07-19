class Solution {
public:
    vector<vector<int>>ans;
    vector<int>v;
    void fun(TreeNode* root,int sum)
    {
        if(root==nullptr) return ;
        if(root->left == nullptr && root->right == nullptr)
        {
            if(root->val == sum)
            {
                v.push_back(sum);
                ans.push_back(v);
                v.pop_back();
            }
            return;
        }
        v.push_back(root->val);
        fun(root->left,sum-root->val);
        fun(root->right,sum-root->val);
        v.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        fun(root,sum);
        return ans;
    }
};