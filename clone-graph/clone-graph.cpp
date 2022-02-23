class Solution {
public:
    unordered_map<int,Node*>mp;
    Node* fun(Node* node)
    {
        if(mp.find(node->val)!=mp.end())
        {
            return mp[node->val];
        }
        else
        {
            Node* now = new Node(node->val);
            mp[node->val]=now;
            for(int i=0;i<node->neighbors.size();i++)
            {
                now->neighbors.push_back(fun(node->neighbors[i]));
            }
            return now;
        }
    }
    Node* cloneGraph(Node* node) 
    {
        if(node == nullptr) return node;
        return fun(node);
    }
};