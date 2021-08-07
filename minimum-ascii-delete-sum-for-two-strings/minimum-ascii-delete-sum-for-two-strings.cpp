class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int tot=0,n=s1.size(),m=s2.size();
        vector<vector<int>>v((n+1),vector<int>(m+1));
        for(int i=1;i<=n;i++)
        {
            v[i][0]+=s1[i-1]+v[i-1][0];
        }
        for(int j=1;j<=m;j++)
        {
            v[0][j]+=s2[j-1]+v[0][j-1];
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(s1[i-1]==s2[j-1])
                {
                    v[i][j]=v[i-1][j-1];
                }
                else
                {
                    v[i][j]=min(s1[i-1]+v[i-1][j],s2[j-1]+v[i][j-1]);
                }
            }
        }
        return v[n][m];
    }
};