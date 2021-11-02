class Solution {
public:
    int fun(vector<vector<int>>&v,int i,vector<int>&time,vector<int>&store)
    {
        if(store[i] != -1) return store[i];
        int ans = 0;
        for(int j=0;j<v[i].size();j++)
        {
            ans = max(ans,fun(v,v[i][j],time,store));
        }
        return store[i] = ans + time[i-1];
    }
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) 
    {
        vector<vector<int>>v((n+1));
        vector<int>vis(n+1);
        vector<int>store((n+1),-1);
        int ans = 0;
        for(int i=0;i<relations.size();i++)
        {
            vis[relations[i][0]]=1;
            v[relations[i][1]].push_back(relations[i][0]);
        }
        for(int i=1;i<=n;i++)
        {
            if(vis[i]) continue;
            ans = max(ans , fun(v,i,time,store));
        }
        return ans;
    }
};