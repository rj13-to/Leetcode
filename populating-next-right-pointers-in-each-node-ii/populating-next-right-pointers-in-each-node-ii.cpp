/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        queue<Node*> q;
        
        if(root != nullptr) q.push(root);
        
        int k =q.size();
        while(k)
        {
            while(k > 1)
            {
                Node* cur = q.front();
                q.pop();

                cur->next = q.front();
                if(cur->left)q.push(cur->left);
                if(cur->right)q.push(cur->right);
                k--;
            }
            if(q.front()->left) q.push(q.front()->left);
            if(q.front()->right) q.push(q.front()->right);
            q.pop();
            k = q.size();
        }
        return root;
    }
};