class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if(!numRows) return {};
        vector<vector<int>>v(numRows);
        v[0].push_back(1);int s;
        for(int i=1;i<numRows;i++){
            s=i+1;
            v[i].push_back(1);
            if(s & 1){
                for(int j=1;j<=s/2;j++){
                    v[i].push_back(v[i][j-1]*(s-j)/(j));
                }
                for(int j=s/2-1;j>=0;j--){
                    v[i].push_back(v[i][j]);
                }
            }
            else{
                for(int j=1;j<s/2;j++){
                    v[i].push_back(v[i][j-1]*(s-j)/(j));
                }
                for(int j=s/2-1;j>=0;j--){
                    v[i].push_back(v[i][j]);
                }
            }
        }
        return v;
    }
};