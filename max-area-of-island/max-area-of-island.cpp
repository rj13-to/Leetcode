class Solution {
public:
    int n,m;
    int dfs(int i,int j,vector<vector<int>>&v){
        if(i<0 || j<0 || i==n || j==m || v[i][j]==0) return 0;
        v[i][j]=0;
        return 1+dfs(i+1,j,v)+dfs(i-1,j,v)+dfs(i,j+1,v)+dfs(i,j-1,v);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        n=grid.size();m=grid[0].size();
        int tot=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++){  
                tot=max(tot,dfs(i,j,grid));
            }
        }
        return tot;
    }
};