class Solution {
public:
    int countSubstrings(string s) 
    {
        int tot=0;
        int dp[1005][1005];
        memset(dp,0,sizeof(dp));
        int n=s.size(),j;
        for(int i=0;i<n;i++) 
        {
            dp[i][i]=1;
            tot++;
        }
        for(int i=1;i<n;i++)
        {
            if(s[i]==s[i-1])
            {
                dp[i-1][i]=1;
                tot++;
            }
        }
        for(int k=3;k<=n;k++)
        {
            for(int i=0;i<=n-k;i++)
            {
                j=i+k-1;
                if(dp[i+1][j-1] && s[i]==s[j]) 
                {
                    dp[i][j]=1;
                    tot++;
                }
            }
        }
        return tot;
    }
};