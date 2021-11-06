class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) 
    {
        set<int>se;
        for(int i=0;i<nums.size();i++)
        {
            if(se.count(nums[i])) se.erase(nums[i]);
            else se.insert(nums[i]);
        }
        return {*se.begin(),*se.rbegin()};
    }
};