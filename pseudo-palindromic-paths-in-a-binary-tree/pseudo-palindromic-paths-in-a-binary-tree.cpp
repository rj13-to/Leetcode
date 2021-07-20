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
    int v[10]={0};
    int cnt=0;
    int fun(TreeNode* root)
    {
        if(root==nullptr) return 0;
        v[root->val]=1-v[root->val];
        if(root->left == nullptr && root->right == nullptr)
        {
            cnt=0;
            for(int i=1;i<10;i++) if(v[i]) cnt++;
            v[root->val]=1-v[root->val];
            return cnt<2;
        }
        int temp=fun(root->left)+fun(root->right);
        v[root->val]=1-v[root->val];
        return temp;
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        return fun(root);
    }
};