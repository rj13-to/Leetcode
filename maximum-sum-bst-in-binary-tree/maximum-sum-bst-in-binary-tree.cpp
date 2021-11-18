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
    int ans = 0;
    vector<int> fun(TreeNode* root)
    {
        if(root == nullptr) return {0,50000,-50000,1};
        vector<int>left = fun(root->left);
        vector<int>right = fun(root->right);
        if(left[3]*right[3] !=0 && (left[2]<root->val && root->val < right[1]))
        {
            vector<int>r(4);
            r[3] = 1;
            r[2] = right[2];
            r[1] = left[1];
            r[0] = left[0]+right[0]+root->val;
            if(r[1] == 50000) r[1] = root->val;
            if(r[2] == -50000) r[2] = root->val;
            ans = max(ans,r[0]);
            return r;
        }
        else
        {
            return {0,0,0,0};
        }
    }
    int maxSumBST(TreeNode* root) 
    {
        fun(root);
        return ans;
    }
};