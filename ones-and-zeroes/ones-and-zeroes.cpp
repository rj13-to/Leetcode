class Solution {
public:
    int dp[601][101][101];
    int fun(vector<string>&strs,int m,int n,int i)
    {
        if(i==0) return 0;
        if(dp[i][m][n]!=-1) return dp[i][m][n];
        int a=0,b=0;
        for(int j=0;j<(int)strs[i-1].size();j++) if(strs[i-1][j]=='0') a++; else b++;
        if(a<=m && b<=n) dp[i][m][n]=max(1+fun(strs,m-a,n-b,i-1),fun(strs,m,n,i-1));
        else dp[i][m][n] = fun(strs,m,n,i-1);
        return dp[i][m][n];
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        memset(dp,-1,sizeof(dp));
        return fun(strs,m,n,strs.size());
    }
};