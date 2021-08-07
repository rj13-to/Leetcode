class Solution {
public:
    int minCut(string s) {
        int dp[2005][2005];
        memset(dp,0,sizeof(dp));
        int n=s.size(),j;
        for(int i=0;i<n;i++) dp[i][i]=1;
        for(int i=1;i<n;i++) if(s[i]==s[i-1]) dp[i-1][i]=1;
        for(int k=3;k<=n;k++)
        {
            for(int i=0;i<=n-k;i++)
            {
                j=i+k-1;
                if(dp[i+1][j-1] && s[i]==s[j]) dp[i][j]=1;
            }
        }
        vector<int>v(n+1);
        for(int i=0;i<=n;i++)
        {
            v[i]=i;
            for(int j=i-1;j>=0;j--)
            {
                if(j==0)
                {
                    if(dp[0][i-1]) v[i]=0;
                }
                else if(dp[j][i-1])
                {
                    v[i]=min(v[i],1+v[j]);
                }
            }
        }
        return v.back();
    }
};