class Solution {
public:
    vector<vector<int>>vis;
    bool fun(vector<vector<char>>&board,string word,int i,int r,int c)
    {
        if(i == word.size()) return true;
        if(r<0 || c<0 || r==board.size() || c==board[0].size() || vis[r][c] || board[r][c]!=word[i]) return false;
        vis[r][c]=1;
        i++;
        bool ok = (fun(board,word,i,r+1,c) || fun(board,word,i,r-1,c) || fun(board,word,i,r,c+1) || fun(board,word,i,r,c-1));
        vis[r][c]=0;
        return ok;
    }
    bool exist(vector<vector<char>>& board, string word) {
        vis.resize(board.size(),vector<int>(board[0].size()));
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[0].size();j++)
            {
                if(fun(board,word,0,i,j)) return true;
            }
        }
        return false;
    }
};