class Solution {
public:
    vector<int> neighbors {-1, 0, 1};
    bool isSafe(int r1, int c1, int rows, int cols)
    {
        if(r1 >=0 and c1 >= 0 and r1 < rows and c1 < cols)
            return true;
        return false;
    }
    void gameOfLife(vector<vector<int>>& board) {
        int rows = board.size();
        if(!rows)
            return;
        int cols = board[0].size();
        
        for(int i = 0; i < rows; i++)
            for(int j = 0; j < cols; j++)
            {
                int cnt(0);
                for(int r: neighbors)
                    for(int c: neighbors)
                    {
                        int r1 = r + i;
                        int c1 = c + j;
                        if(isSafe(r1,c1,rows,cols) and abs(board[r1][c1]) == 1)
                            cnt++;
                    }
                if(board[i][j])
                    cnt--;
                if((board[i][j] == 1) and (cnt < 2 or cnt > 3))
                    board[i][j] = -1;
                 if (board[i][j] == 0 and cnt == 3)
                    board[i][j] = 2;
            }
        
         for(int i = 0; i < rows; i++)
            for(int j = 0; j < cols; j++)
                if(board[i][j] > 0)
                    board[i][j] = 1;
                else
                    board[i][j] = 0;
        
        return;
    }
};