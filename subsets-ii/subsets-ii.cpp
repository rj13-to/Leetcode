class Solution {
public:
    vector<vector<int>>ans={{}};
    vector<int>v;
    void fun(int i,vector<int>&nums)
    {
        ans.push_back(v);
        for(int j=i;j<nums.size();j++)
        {
            if(j!=i && nums[j]==nums[j-1]) continue;
            v.push_back(nums[j]);
            fun(j+1,nums);
            v.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++)
        {
            if(i!=0 && nums[i]==nums[i-1]) continue;
            v.push_back(nums[i]);
            fun(i+1,nums);
            v.pop_back();
        }
        return ans;
    }
};