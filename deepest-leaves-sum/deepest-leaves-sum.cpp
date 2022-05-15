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
    
    void dfs(TreeNode* cur, int& depth, int height)
    {
        if(cur == nullptr) return;
        if(depth == height) 
        {
            ans += cur->val;
        }
        else if(depth < height)
        {
            depth = height;
            ans = cur->val;
        }
        
        dfs(cur->left, depth, height+1);
        dfs(cur->right, depth, height+1);
            
    }
    int deepestLeavesSum(TreeNode* root) {
        int depth = 0;
        dfs(root,depth,0);
        return ans;
    }
};