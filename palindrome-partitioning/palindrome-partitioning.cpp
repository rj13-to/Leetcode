class Solution {
public:
    vector<vector<string>>ans;
    int dp[2005][2005];
    void fun(int i,int crr,vector<string>&v,string s)
    {
        //cout<<i<<" "<<crr<<endl;
        if(crr == s.size()-1)
        {
            if(dp[i][crr]) 
            {
                v.push_back(s.substr(i,crr-i+1));
                ans.push_back(v);
                v.pop_back();
            }
        }
        else
        {
            if(dp[i][crr])
            {
                v.push_back(s.substr(i,crr-i+1));
                fun(crr+1,crr+1,v,s);
                v.pop_back();
            }
            fun(i,crr+1,v,s);
        }
    }
    vector<vector<string>> partition(string s) {
        int n=s.size();
        memset(dp,0,sizeof(dp));
        for(int i=0;i<n;i++)
        {
            dp[i][i]=1;
        }
        for(int i=0;i<n-1;i++) if(s[i]==s[i+1]) dp[i][i+1]=1;
        int j;
        for(int k=3;k<=n;k++)
        {
            for(int i=0;i<=n-k;i++)
            {
                j=i+k-1;
                if(dp[i+1][j-1] && s[i]==s[j]) dp[i][j]=1;
            }
        }
        vector<string>v;
        fun(0,0,v,s);
        return ans;
    }
};