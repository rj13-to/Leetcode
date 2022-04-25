class Solution {
public:
    int dp[35][35][35];
    bool split(string& s1, string& s2,int i,int j,int len)
    {
        if(len == 1) return s1[i] == s2[j];
        if(dp[len][i][j] != -1) return dp[len][i][j];
        
        int n = s2.size();
        bool cur = false;
        for(int k = 1;k<len;k++)
        {
            cur |= ( split(s1,s2,i,j,k) && split(s1,s2,i+k,j+k,len-k) ) || (split(s1,s2,i,j+len-k,k) && split(s1,s2,i+k,j,len-k));
        }
        return dp[len][i][j] = cur;
    }
    bool isScramble(string s1, string s2) 
    {
        memset(dp,-1,sizeof(dp));
        return split(s1,s2,0,0,s1.size());
        
    }
};