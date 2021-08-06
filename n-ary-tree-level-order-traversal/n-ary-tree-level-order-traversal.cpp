/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>>v;
    void fun(int j,Node* root)
    {
        if(root == nullptr) return;
        if(j==v.size()) v.push_back({root->val});
        else v[j].push_back(root->val);
        for(int i=0;i<root->children.size();i++)
        {
            fun(j+1,root->children[i]);
        }
    }
    vector<vector<int>> levelOrder(Node* root) {
        fun(0,root);
        return v;
    }
};