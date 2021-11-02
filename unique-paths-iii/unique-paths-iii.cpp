class Solution {
public:
    int ax,ay,bx,by;
    vector<vector<int>>arr;
    int rj13(int i,int j,vector<vector<int>>vis){
        if(i<0 || j<0 || i==arr.size() || j==arr[0].size()) return 0;
        if(arr[i][j]==-1 || vis[i][j]==1) return 0;
        if(arr[i][j]==2){
            for(int i=0;i<arr.size();i++){
                for(int j=0;j<arr[0].size();j++){
                    if(arr[i][j]==0 && vis[i][j]!=1) return 0;
                }
            }return 1;
        }
        vis[i][j]=1;
        return rj13(i+1,j,vis) + rj13(i-1,j,vis) + rj13(i,j-1,vis) +rj13(i,j+1,vis);
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        arr=grid;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){ax=i;ay=j;}
                if(grid[i][j]==2){bx=i;by=j;}
            }
        }
        vector<vector<int>>l(n,vector<int>(m,0));
        return rj13(ax,ay,l);
    }
};