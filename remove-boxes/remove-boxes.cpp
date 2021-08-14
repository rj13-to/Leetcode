class Solution {
public:
    long long dp[105][105][105];
    long long fun(vector<int>&boxes,int i,int j,int k)
    {
        if(i>j) return 0;
        if(dp[i][j][k]!=-1) return dp[i][j][k];
        dp[i][j][k]=(k+1)*(k+1)+fun(boxes,i+1,j,0);
        for(int l=i+1;l<=j;l++)
        {
            if(boxes[i] == boxes[l]) 
                dp[i][j][k]=max(dp[i][j][k],fun(boxes,i+1,l-1,0)+fun(boxes,l,j,k+1));
        }
        return dp[i][j][k];
    }
    int removeBoxes(vector<int>& boxes) {
        memset(dp,-1,sizeof(dp));
        return fun(boxes,0,boxes.size()-1,0);
    }
};