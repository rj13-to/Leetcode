class Solution {
public:
    int dfs(int cur,vector<int>& manager, vector<int>& informTime, vector<int>& reachTime)
    {
        if(manager[cur] == -1) 
        {
            return reachTime[cur] = 0;
        }
        else if(reachTime[manager[cur]] != -1) 
        {
            return reachTime[cur] = informTime[manager[cur]] + reachTime[manager[cur]];
        }
        else
        {
            return reachTime[cur] = informTime[manager[cur]] + dfs(manager[cur],manager,informTime,reachTime);
        }
        
    }
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) 
    {
        vector<int>reachTime(n,-1);
        int ans = 0;
        for(int i=0;i<manager.size();i++)
        {
            if(reachTime[i] == -1) dfs(i,manager,informTime,reachTime);
            ans = max(ans,reachTime[i]);
        }
        return ans;
    }
};