class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>>v;
        sort(nums.begin(),nums.end());
        int l,h,need;
        for(int i=0;i<nums.size();)
        {
            for(int j=i+1;j<nums.size();)
            {
                l=j+1;
                h=nums.size()-1;
                need=target-nums[i]-nums[j];
                while(l<h)
                {
                    if(need>nums[l]+nums[h])
                    {
                        l++;
                    }
                    else if(need<nums[l]+nums[h])
                    {
                        h--;
                    }
                    else
                    {
                        v.push_back({nums[i],nums[j],nums[l],nums[h]});
                        l++;h--;
                        while(l<h && nums[l]==nums[l-1]) l++;
                        while(h>l && nums[h]==nums[h+1]) h--;
                    }
                }
                j++;
                while(j<nums.size() && nums[j]==nums[j-1]) j++;
            }
            i++;
            while(i<nums.size() && nums[i]==nums[i-1]) i++;
        }
        return v;
    }
};