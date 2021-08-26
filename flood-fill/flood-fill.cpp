class Solution {
public:
    void dfs(vector<vector<int>>& image,int i,int j,int req)
    {
        if(i<0 || j<0 || i==image.size() || j==image[0].size() || req !=image[i][j]) return ;
        image[i][j]=-1;
        dfs(image,i+1,j,req);
        dfs(image,i-1,j,req);
        dfs(image,i,j+1,req);
        dfs(image,i,j-1,req);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) 
    {
        dfs(image,sr,sc,image[sr][sc]);
        for(int i=0;i<image.size();i++)
        {
            for(int j=0;j<image[0].size();j++) if(image[i][j]<0) image[i][j]=newColor;
        }
        return image;
    }
};