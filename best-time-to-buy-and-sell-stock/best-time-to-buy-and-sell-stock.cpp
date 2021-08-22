class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int tot=0,crr=INT_MAX;
        for(int i=0;i<prices.size();i++)
        {
            if(crr>prices[i])
            {
                crr=prices[i];
            }
            else if(prices[i]-crr>tot)
            {
                tot=prices[i]-crr;
            }
        }
        return tot;
    }
};