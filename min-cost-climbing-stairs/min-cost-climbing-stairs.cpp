class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n= cost.size();
        int dp[n];
        dp[0]=0;dp[1]=0;
        for(int i=2;i<n;i++){
            if(dp[i-1]+cost[i-1] > dp[i-2]+cost[i-2]){
                dp[i]=dp[i-2]+cost[i-2];
            }
            else{
                dp[i]=dp[i-1]+cost[i-1];
            }
        }
        return dp[n-1]+cost[n-1]>dp[n-2]+cost[n-2]?dp[n-2]+cost[n-2]:dp[n-1]+cost[n-1];
    }
};