class Solution {
public:
    int arr[71][71][71];
    int fun(int i,int j1,int j2, vector<vector<int>>& grid)
    {
        
        if(j1 < 0 || j2 < 0 || j1 == grid[0].size() || j2 == grid[0].size()) return 0;
        if(i == grid.size()-1)
        {
            if(j2 == j1)
            {
                return grid[i][j1];
            }
            else return grid[i][j1] + grid[i][j2];
        }
        if(arr[i][j1][j2] != -1) return arr[i][j1][j2];
        arr[i][j1][j2] = grid[i][j1];
        if(j1 != j2) arr[i][j1][j2] += grid[i][j2];
        
        int k = 0;
        for(int add = -1; add< 2 ; add++)
        {
            for(int add2 = -1; add2 < 2 ; add2++)
            {
                k = max(k, fun(i+1,j1+add,j2+add2,grid));
            }
        }
        arr[i][j1][j2] += k;
        return arr[i][j1][j2];
    }
    int cherryPickup(vector<vector<int>>& grid) 
    {
        memset(arr,-1,sizeof(arr));
        return fun(0,0,grid[0].size()-1,grid);          
    }
};