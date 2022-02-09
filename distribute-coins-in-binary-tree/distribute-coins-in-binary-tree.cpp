class Solution {
public:
    int ans = 0;
    int fun(TreeNode* root)
    {
        if(root == nullptr) return 0;
        int a = fun(root->left);
        int b = fun(root->right);
        ans += abs(a) + abs(b);
        int req;
        if(a > 0)
        {
            if(root->val == 0)
            {
                a--;
                root->val = 1;
            }
        }
        else if( a < 0)
        {
            if(root->val > 1)
            {
                req = min(root->val - 1, -a);
                root->val -= req;
                a += req;
            }
        }
        
        if(b > 0)
        {
            if(root->val == 0)
            {
                b--;
                root->val = 1;
            }
        }
        else if(b < 0 && root->val > 1)
        {
            req = min(root->val -1 , -b);
            
            root->val -= req;
            
            b += req;
        }
        
        return a+b+root->val-1;
    }
    int distributeCoins(TreeNode* root) 
    {
        fun(root);
        return ans;
    }
};