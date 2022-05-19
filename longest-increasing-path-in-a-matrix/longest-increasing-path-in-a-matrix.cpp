class Solution {
public:
    vector<vector<int>>v;
    int tot=0;
    int check(vector<vector<int>>&matrix,int i,int j,int pre)
    {
        if(i<0 || j<0 || i==matrix.size() || j==matrix[0].size()) return 0;
        if(pre>=matrix[i][j]) return 0;
        if(v[i][j]!=-1) return v[i][j];
        v[i][j]=max(check(matrix,i+1,j,matrix[i][j]),check(matrix,i-1,j,matrix[i][j]));
        int k=max(check(matrix,i,j+1,matrix[i][j]),check(matrix,i,j-1,matrix[i][j]));
        v[i][j]=max(v[i][j],k);
        v[i][j]++;
        return v[i][j];
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        v.resize(matrix.size(),vector<int>(matrix[0].size(),-1));
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[0].size();j++)
            {
                if(v[i][j]!=-1)
                {
                    tot=max(tot,v[i][j]);
                }
                else tot=max(tot,check(matrix,i,j,-1));
            }
        }
        return tot;
    }
};