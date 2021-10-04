class Solution {
public:
    int check(int i,int j,vector<vector<int>>&grid)
    {
        if(i<0 || j<0 || i == grid.size() || j == grid[0].size() || grid[i][j] == 0) return 1;
        return 0;
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        int cnt =0 ;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j])
                {
                    cnt+=check(i+1,j,grid);
                    cnt+=check(i-1,j,grid);
                    cnt+=check(i,j+1,grid);
                    cnt+=check(i,j-1,grid);
                }
            }
        }
        return cnt;
    }
};