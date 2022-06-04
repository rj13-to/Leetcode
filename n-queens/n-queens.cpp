class Solution {
public:
    vector<vector<string>>ans;
    void queen(int i,int n,vector<string>v){
        if(i==n){
            ans.push_back(v);
            return ;
        }
        for(int j=0;j<n;j++){
            if(v[i][j]=='.'){
                vector<string>vv=v;
                vv[i][j]='Q';
                for(int k=0;k<n;k++){
                    if(vv[i][k]=='.') vv[i][k]='O';
                    if(vv[k][j]=='.') vv[k][j]='O';
                }
                int x=i-1,y=j-1;
                while(x>=0 && y>=0){
                    if(vv[x][y]=='.')  vv[x][y]='O';
                    x--;y--;
                }
                x=i+1;y=j+1;
                while(x<n && y<n){
                    if(vv[x][y]=='.')  vv[x][y]='O';
                    x++;y++;
                }
                x=i+1;y=j-1;
                while(x<n && y>=0){
                    if(vv[x][y]=='.')  vv[x][y]='O';
                    x++;y--;
                }
                x=i-1;y=j+1;
                while(x>=0 && y<n){
                    if(vv[x][y]=='.')  vv[x][y]='O';
                    x--;y++;
                }
                queen(i+1,n,vv);
                vv.clear();
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string>v;
        string s(n,'.');
        for(int i=0;i<n;i++){
           v.push_back(s);
        }
        queen(0,n,v);
        for(int i=0;i<ans.size();i++){
            for(int j=0;j<n;j++){
                for(int k=0;k<n;k++){
                    if(ans[i][j][k]=='O') ans[i][j][k]='.';
                }
            }
        }
        return ans;
    }
};