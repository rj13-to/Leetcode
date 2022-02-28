class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        vector<int>ans(prices.size());
        int cur;
        
        for(int i=1;i<prices.size();i++)
        {
            for(int j=i-1;j>=0;j--)
            {
                cur = 0;
                if(prices[j] < prices[i])
                {
                    cur = prices[i]-prices[j];
                }
                if(j > 1) cur += ans[j-2];
                ans[i] = max({ans[i],cur});
            }
            ans[i] = max(ans[i],ans[i-1]);
        }
        return ans.back();
    }
};