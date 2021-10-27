class Solution {
public:
    set<vector<string>>set;
    bool isSafe(vector<string>board,int n, int cols, int row){
        int ROW=row;
        int COL=cols;
        while(cols>=0){
            if(board[row][cols]=='Q') return false;
            cols--;
        }
        row=ROW;
        cols=COL;
        while(row>=0 and cols>=0){
            if(board[row][cols]=='Q') return false;
            row--; cols--;
        }
        row=ROW;
        cols=COL;
        while(row<n and cols>=0){
            if(board[row][cols]=='Q') return false;
            row++; cols--;
        }
        return true;
    }
    void solve(vector<string>&board, int n, int cols){
        if(cols==n){
            set.insert(board);
            return;
        } 
        for(int row=0; row<n; row++)
        {
            if(isSafe(board,n,cols,row))
            {
                board[row][cols]='Q';
                solve(board,n,cols+1);
                board[row][cols]='.';
            }
        }
    }
    int totalNQueens(int n) {
        string s(n,'.');
        vector<string>board(n,s);
        // for(int i=0; i<n; i++)
        //     board[i]=s;
        solve(board,n,0);
        //vector<vector<string>> ans;
        return set.size();
        
    }
};