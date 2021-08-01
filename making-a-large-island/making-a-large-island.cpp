class Solution {
public:
    int ans=0;
    int tot=0;
    map<int,int>mp;
    bool check(int i,int j,int n)
    {
        if(i<0 || j<0 || i==n || j==n) return false;
        return true;
    }
    void fun(vector<vector<int>>&grid,int i,int j,int k)
    {
        if(i<0 || j<0 || i==grid.size() || j==grid.size() || grid[i][j]!=1) return ;
        grid[i][j]=k;
        tot++;
        fun(grid,i+1,j,k);
        fun(grid,i-1,j,k);
        fun(grid,i,j+1,k);
        fun(grid,i,j-1,k);
    }
    int largestIsland(vector<vector<int>>& grid) 
    {
        int k=2;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid.size();j++)
            {
                if(grid[i][j]==1)
                {
                    fun(grid,i,j,k);
                    mp[k]=tot;
                    ans=max(tot,ans);
                    tot=0;
                    k++;
                }
            }
        }
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid.size();j++)
            {
                if(grid[i][j]==0)
                {
                    set<int>se;
                    tot=1;
                    if(check(i+1,j,grid.size()))
                    {
                        if(se.find(grid[i+1][j])==se.end())  tot+=mp[grid[i+1][j]];
                        se.insert(grid[i+1][j]);
                    }
                    if(check(i-1,j,grid.size()))
                    {
                        if(se.find(grid[i-1][j])==se.end())  tot+=mp[grid[i-1][j]];
                        se.insert(grid[i-1][j]);
                    }
                    if(check(i,j+1,grid.size()))
                    {
                        if(se.find(grid[i][j+1])==se.end())  tot+=mp[grid[i][j+1]];
                        se.insert(grid[i][j+1]);
                    }
                   if(check(i,j-1,grid.size()))
                    {
                        if(se.find(grid[i][j-1])==se.end())  tot+=mp[grid[i][j-1]];
                       se.insert(grid[i][j-1]);
                    }
                    ans=max(tot,ans);
                }
            }
        }
        return ans;
    }
};