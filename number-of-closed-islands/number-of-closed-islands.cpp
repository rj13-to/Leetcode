class Solution {
public:
    bool dfs(vector<vector<int>>& grid,int i, int j)
    {
        if(i < 0 || j< 0 || i == grid.size() || j == grid[0].size() ) return false;
        
        if(grid[i][j]) return 1;
        else 
        {
            grid[i][j] = 1;
            bool ok1 = dfs(grid,i,j+1);
            bool ok2 = dfs(grid,i,j-1);
            bool ok3 = dfs(grid,i-1,j);
            bool ok4 = dfs(grid,i+1,j);
            return ok1 && ok2 && ok3 && ok4;
        }
    }
    int closedIsland(vector<vector<int>>& grid) 
    {
        int ans = 0;
        for(int i=0;i<grid.size(); i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j] == 0) ans += dfs(grid,i,j);
            }
        }
        return ans;
    }
};