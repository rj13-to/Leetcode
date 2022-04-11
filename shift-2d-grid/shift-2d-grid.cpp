class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        vector<int>extra;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                extra.push_back(grid[i][j]);
            }
        }
        int tot = extra.size();
        k%=tot;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                int cur = i*grid[0].size()+j;
          
                cur-=k;
                
                if(cur < 0) cur = tot+cur;
                
                grid[i][j] = extra[cur];
            }
        }
        return grid;
    }
};