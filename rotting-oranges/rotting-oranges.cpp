class Solution {
public:
    bool valid(int i,int j,int a,int b,vector<vector<int>>&v)
    {
        if(i==a || j==b || i<0 || j<0 ) return 0;
        return v[i][j]==1;
    }
    int orangesRotting(vector<vector<int>>& grid) 
    {
        queue<pair<int,int>>q;
        pair<int,int>pr;
        vector<pair<int,int>>arr={make_pair(-1,0),make_pair(1,0),make_pair(0,-1),make_pair(0,1)};
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j] == 2)
                {
                    for(int k=0;k<4;k++)
                    {
                        if(valid(i+arr[k].first,j+arr[k].second,grid.size(),grid[0].size(),grid))
                        {
                            grid[i+arr[k].first][j+arr[k].second]=-1;
                            q.push({i+arr[k].first,j+arr[k].second});
                            
                        }
                    }
                }
            }
        }
        while(q.size())
        {
            pr=q.front();
            for(int k=0;k<4;k++)
            {
                if(valid(pr.first+arr[k].first,pr.second+arr[k].second,grid.size(),grid[0].size(),grid))
                {
                  
                    grid[pr.first+arr[k].first][pr.second+arr[k].second]=-1+grid[pr.first][pr.second];
                    q.push({pr.first+arr[k].first,pr.second+arr[k].second});
                   
                }
            }
            q.pop();
        }
        int k=0;
        for(int i=0;i<grid.size();i++)
         {
            for(int j=0;j<grid[0].size();j++)
            {
               
                if(grid[i][j]==1) return -1;
                else k=min(k,grid[i][j]);
            }
           
         }
        return -k;
    }
};