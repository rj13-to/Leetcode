class Solution {
public:
    int numSquares(int n) 
    {
        vector<int>v;
        for(int i=1;i*i<=n;i++)
        {
            v.push_back(i*i);
        }
        vector<int>ans(n+1,n);
        ans[0]=0;
        for(int i=0;i<v.size();i++)
        {
            for(int j=v[i];j<=n;j++)
            {
                ans[j]=min(1+ans[j-v[i]],ans[j]);
            }
        }
        
        return ans.back();
    }
};