class Solution {
public:
    int numDecodings(string s) {
        int n=s.size();
        long long dp[100005]={0};
        long long mod=1e9+7;
        dp[n]=1;
        for(int i=n-1;i>=0;i--)
        {
            if(i==n-1)
            {
                if(s[i]=='*') dp[i]=9;
                else if(s[i]=='0') dp[i]=0;
                else dp[i]=1;
            }
            else
            {
                if(s[i]=='*')
                {
                    if(s[i+1]=='*')
                    {
                        dp[i] = 15*dp[i+2];
                        dp[i] += 9*dp[i+1];
                    }
                    else if(s[i+1]=='0')
                    {
                        dp[i]=2*dp[i+2];
                    }
                    else
                    {
                        dp[i] += 9*dp[i+1];
                        if(s[i+1]<'7') dp[i] +=2*dp[i+2];
                        else dp[i] +=dp[i+2];
                    }
                }
                else if(s[i]=='0') dp[i]=0;
                else{
                    if(s[i+1]=='*')
                    {
                        if(s[i]=='1') dp[i]=9*dp[i+2];
                        else if(s[i]=='2') dp[i]=6*dp[i+2];
                        dp[i]+=dp[i+1];
                    }
                    else if(s[i+1]=='0')
                    {
                        if(s[i]<'3') dp[i]+=dp[i+2];
                    }
                    else
                    {
                        dp[i] += dp[i+1];
                        if(s[i]=='1') dp[i]+=dp[i+2];
                        else if(s[i]=='2' && s[i+1]<'7') dp[i]+=dp[i+2];
                    }
                }
            }
            dp[i]%=mod;
        }
        return dp[0];
    }
};