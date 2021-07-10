class Solution {
public:
    int numDecodings(string A) {
            vector<long long> dp(A.size()+1);
            long long mod=1e9+7;
            dp[A.size()]=1;
            for(int i=A.size()-1;i>=0;i--)
            {
                if(i==A.size()-1)
                {
                    if(A[i]=='0') dp[i]=0;
                    else dp[i]=1;
                }
                else if(A[i]=='0')
                {
                    dp[i]=0;
                }
                else if(A[i]=='1')
                {
                    dp[i]=dp[i+1];
                    if(A[i+1]=='0') dp[i]=dp[i+2];
                    else dp[i]+=dp[i+2];
                    
                }
                else if(A[i]=='2')
                {
                    dp[i]=dp[i+1];
                    if(A[i+1]=='0') dp[i]=dp[i+2];
                    else if(A[i+1]<'7') dp[i]+=dp[i+2];
                }
                else dp[i]=dp[i+1];   
                //dp[i]%=mod;
            }
            return dp[0];
    }
};