class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int>v(nums.size());
        int ans=0;
        for(int i=0;i<nums.size();i++)
        {
            for(int j=i-1;j>=0;j--) if(nums[i]>nums[j]) v[i]=max(v[i],v[j]);
            v[i]++;
            ans=max(ans,v[i]);
        }
        return ans;
    }
};