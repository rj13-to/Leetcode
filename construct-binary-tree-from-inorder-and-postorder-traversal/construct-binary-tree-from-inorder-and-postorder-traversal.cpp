class Solution {
public:
    int f;
    TreeNode* tree(vector<int>& inorder,vector<int>& postorder,int st,int ed)
    {
        if(st>ed){
            f++;
            return nullptr;
        }
        TreeNode* root=new TreeNode(postorder[f]);
        for(int i=ed;i>=st;i--)
        {
            if(inorder[i]==postorder[f])
            {
                f--;
                root->right=tree(inorder,postorder,i+1,ed);
                f--;
                root->left=tree(inorder,postorder,st,i-1);
                break;
            }
        }
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        f=postorder.size()-1;
        return tree(inorder,postorder,0,f);
    }
};