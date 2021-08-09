class Solution {
public:
    int fun(int i,vector<int>&nums,int target,int sum)
    {
        if(i==0) return sum == target;
        else return fun(i-1,nums,target,sum-nums[i-1])+fun(i-1,nums,target,sum+nums[i-1]);
    }
    int findTargetSumWays(vector<int>& nums, int target) 
    {
        return fun(nums.size(),nums,target,0);
    }
};