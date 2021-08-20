class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) 
    {
        int arr[10]={0};
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                if(board[i][j]=='.') continue;
                arr[board[i][j]-'0']++;
                if(arr[board[i][j]-'0'] == 2)
                {
                    return 0;
                }
            }
            memset(arr,0,sizeof(arr));
        }
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                if(board[j][i]=='.') continue;
                arr[board[j][i]-'0']++;
                if(arr[board[j][i]-'0'] == 2)
                {
                    return 0;
                }
            }
            memset(arr,0,sizeof(arr));
        }
        int row,col;
        for(int i=0;i<9;i+=3)
        {
            for(int j=0;j<9;j+=3)
            {
                for(row=i;row<i+3;row++)
                {
                    for(col=j;col<j+3;col++)
                    {
                        if(board[row][col]=='.') continue;
                        arr[board[row][col]-'0']++;
                        if(arr[board[row][col]-'0'] == 2)
                        {
                            return 0;
                        }
                    }   
                }
                memset(arr,0,sizeof(arr));
            }
        }
        return 1;
    }
};