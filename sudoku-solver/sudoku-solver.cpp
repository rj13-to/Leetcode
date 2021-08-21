class Solution {
public:
    int row[9][10];
    int col[9][10];
    int box[9][10];
    bool fun(vector<vector<char>>& board,int i,int j,int empty)
    {
        if(j==9)
        {
            j=0;
            i++;
        }
        if(i == 9 ) return empty == 0;
        if(board[i][j]!='.') return fun(board,i,j+1,empty);
        for(int k=1;k<10;k++)
        {
            if(row[i][k] || col[j][k] || box[(i/3)*3+j/3][k]) continue;
            row[i][k] = col[j][k] = box[(i/3)*3+j/3][k]=1;
            empty--;
            board[i][j]='0'+k;
            if(fun(board,i,j+1,empty)) return 1;
            board[i][j]='.';
            empty++;
            row[i][k] = col[j][k] = box[(i/3)*3+j/3][k]=0;
        }
        return 0;
    }
    void solveSudoku(vector<vector<char>>& board) 
    {
        memset(row,0,sizeof(row));
        memset(col,0,sizeof(col));
        memset(box,0,sizeof(box));
        int empty=0;
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                if(board[i][j]=='.') continue;
                empty++;
                row[i][board[i][j]-'0']++;
                col[j][board[i][j]-'0']++;
                box[(i/3)*3+j/3][board[i][j]-'0']++;
            }
        }
        empty=81-empty;
        fun(board,0,0,empty);
    }
};