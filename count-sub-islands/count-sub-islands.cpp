class Solution {
public:
    bool dfs(vector<vector<int>>& grid1, vector<vector<int>>& grid2, int i, int j)
    {
        if(i < 0 || j< 0 || i == grid1.size() || j == grid2[0].size() || grid2[i][j] == 0 ) return true;
        
        if(grid1[i][j] != grid2[i][j] ) return false;
        
        grid2[i][j] = 0;
        
        bool ok = dfs(grid1,grid2,i+1,j);
        ok = dfs(grid1,grid2,i-1,j) & ok;
        ok = dfs(grid1,grid2,i,j+1) & ok;
        ok = dfs(grid1,grid2,i,j-1) & ok;
        
        return ok;
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) 
    {
        int ans = 0;
        for(int i=0;i<grid1.size();i++)
        {
            for(int j=0;j<grid1[0].size();j++)
            {
                if(grid2[i][j]) ans += dfs(grid1,grid2,i,j);
            }
        }
        return ans;
    }
};