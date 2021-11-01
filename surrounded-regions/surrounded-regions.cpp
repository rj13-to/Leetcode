class Solution {
public:
    void dfs(vector<vector<char>>& v,int i,int j)
    {
        if(i<0 || j<0 || i==v.size() || j==v[0].size() || v[i][j]=='X' || v[i][j]=='L') return;
        v[i][j]='L';
        dfs(v,i+1,j);
        dfs(v,i-1,j);
        dfs(v,i,j-1);
        dfs(v,i,j+1);
    }
    void solve(vector<vector<char>>& board) {
        for(int i=0;i<board.size();i++){
            if(board[i][0]=='O'){
                dfs(board,i,0);
            }
            if(board[i][board[0].size()-1]=='O'){
                dfs(board,i,board[0].size()-1);
            }
        }
        for(int j=0;j<board[0].size();j++){
            if(board[0][j]=='O'){
                dfs(board,0,j);
            }
            if(board[board.size()-1][j]=='O'){
                dfs(board,board.size()-1,j);
            }
        }
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[0].size();j++)
                if(board[i][j]=='L') board[i][j]='O';
                else if(board[i][j]=='O') board[i][j]='X';
        }
    }
};