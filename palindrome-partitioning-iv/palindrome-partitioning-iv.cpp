class Solution {
public:
    bool checkPartitioning(string s) 
    {
        int dp[2005][2005];
        memset(dp,0,sizeof(dp));
        int n=s.size(),j;

        for(int i=0;i<n;i++) dp[i][i]=1;
        for(int i=1;i<n;i++) 
        {
            if(s[i] == s[i-1]) 
            {
                dp[i-1][i]=1;
                
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
                    
                }
            }
        }
        for(int i=0;i<n-1;i++)
        {
            if(dp[0][i])
            {
                for(int j=i+1;j<n-1;j++)
                {
                    if(dp[i+1][j] && dp[j+1][n-1]) return 1;
                }
            }
        }
        return 0;
    }
};
