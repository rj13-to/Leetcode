class Solution {
public:
    void find(vector<vector<int>>& ans,vector<vector<int>>&graph,int crr,int end,vector<int>&v)
    {
        if(crr==end)
        {
            v.push_back(end);
            ans.push_back(v);
            v.pop_back();
            return;
        }
        v.push_back(crr);
        for(int i=0;i<graph[crr].size();i++)
        {
            find(ans,graph,graph[crr][i],end,v);
        }
        v.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) 
    {
        vector<vector<int>>ans;
        vector<int>v;
        find(ans,graph,0,graph.size()-1,v);
        return ans;
    }
};