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
    int tot=0;
    int ans(TreeNode* root){
        if(root==nullptr) return 0;
        int k=ans(root->left);
        int f=ans(root->right);
        tot+=abs(f-k);
        return root->val+f+k;
    }
    int findTilt(TreeNode* root) {
        tot=0;
        int f=ans(root);
        return tot;
    }
};