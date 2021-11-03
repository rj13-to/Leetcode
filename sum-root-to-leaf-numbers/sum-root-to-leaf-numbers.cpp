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
    int sumNumbers(TreeNode* root) {
        if(root == nullptr)
        {
            ans*=10;
            return 0;
        }
        ans = ans*10+root->val;
        if(root->left == nullptr && root->right == nullptr) return ans;
        int left = sumNumbers(root->left);
        ans/=10;
        int right = sumNumbers(root->right);
        ans/=10;
        return left+right;
    }
};