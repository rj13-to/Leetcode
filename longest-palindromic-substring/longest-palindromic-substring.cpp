class Solution {
public:
    string longestPalindrome(string s)
    {
        int n=s.size();
        vector<vector<int>>dp((n),vector<int>(n));
        for(int i=0;i<n;i++)
        {
            dp[i][i]=1;
        }
        int ans=1,index=0;
        for(int i=1;i<n;i++)
        {
            if(s[i]==s[i-1])
            {
                dp[i-1][i]=1;
                ans=2;
                index=i-1;
            }
        }
        for(int k=3;k<=n;k++)
        {
            for(int i=0;i<=n-k;i++)
            {
                int j = i+k-1;
                if(s[i]==s[j] && dp[i+1][j-1]) 
                {
                    dp[i][j]=1;
                    ans=k;
                    index=i;
                }
            }
        }
        return s.substr(index,ans);
    }
};