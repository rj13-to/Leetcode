class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int tot=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==0) continue;
            for(int j=i+1;j<nums.size();j++)
            {
                tot+=(lower_bound(nums.begin(),nums.end(),nums[i]+nums[j])-nums.begin())-j-1;
            }
        }
        return tot;
    }
};