class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        if(r*c!=mat[0].size()*mat.size()) return mat;
        vector<vector<int>>v(r,vector<int>(c));
        int ii=0,jj=0;
        for(int i=0;i<mat.size();i++)
        {
            for(int j=0;j<mat[0].size();j++)
            {
                v[ii][jj]=mat[i][j];
                jj++;
                if(jj==c){ii++;jj=0;}
            }
        }return v;
    }
};