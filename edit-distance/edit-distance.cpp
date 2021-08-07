class Solution {
public:
    int minDistance(string s1, string s2) {
        int tot=0,n=s1.size(),m=s2.size();
        int v[2][501];
        v[0][0]=0;
        for(int j=1;j<=m;j++)
        {
            v[0][j]=j;
        }
        for(int i=1;i<=n;i++)
        {
            v[i%2][0]=i;
            for(int j=1;j<=m;j++)
            {
                if(s1[i-1]==s2[j-1])
                {
                    v[i%2][j]=v[(i-1)%2][j-1];
                }
                else
                {
                    v[i%2][j]=1+min(v[(i-1)%2][j],min(v[i%2][j-1],v[(i-1)%2][j-1]));
                }
            }
        }
        return v[n%2][m];
    }
};