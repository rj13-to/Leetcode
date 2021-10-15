class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        if (prices.size() < 2)
            return 0;
        int i, sz = prices.size();
        int ret = 0;
        vector<int> buy(sz, 0);
        vector<int> sell(sz, 0);
        buy[0] = -prices[0];
        for (i = 1; i < sz; ++i)
        {
            sell[i] = max(buy[i - 1] + prices[i], sell[i - 1] - prices[i - 1] + prices[i]);
            if (ret < sell[i]) //record the max sell[i]
                ret = sell[i];
            if (1 == i)
                buy[i] = buy[0] + prices[0] - prices[1];
            else
                buy[i] = max(sell[i - 2] - prices[i], buy[i - 1] + prices[i - 1] - prices[i]);
        }
        return ret;
    }
};