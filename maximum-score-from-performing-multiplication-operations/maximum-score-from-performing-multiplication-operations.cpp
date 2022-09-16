class Solution {
public:
    
    int dp[1005][1005];
    
    int helper(vector<int>&nums,vector<int>& multipliers, int i,int step)
    {
        if(step == multipliers.size()) return 0;
        
        if(dp[i][step] != INT_MAX) return dp[i][step];
        int j = nums.size()-1 - step +i;
        
        dp[i][step] = max(nums[i]*multipliers[step]+helper(nums,multipliers,i+1,step+1),nums[j]*multipliers[step]+helper(nums,multipliers,i,step+1));
        
        return dp[i][step];
        
    }
    int maximumScore(vector<int>& nums, vector<int>& multipliers) 
    {
        for(int i=0;i<1005;i++) for(int j =0;j<1005;j++) dp[i][j] = INT_MAX;
        
        return helper(nums,multipliers,0,0);
    }
};