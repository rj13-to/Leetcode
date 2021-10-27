class Solution {
public:
    void sortColors(vector<int>& nums) {
        int st = 0,ed=nums.size()-1,crr=0;
        while(crr <= ed)
        {
            while(st<nums.size() && nums[st] == 0) st++;
            while(ed >= crr && nums[ed] == 2) ed--;
            if(crr < st) crr = st;
            if(st == nums.size() || ed < crr) break;
            if(nums[crr] == 0 )
            {
                swap(nums[crr],nums[st]);
                st++;
            }
            else if(nums[crr] == 2)
            {
                swap(nums[crr],nums[ed]);
                ed--;
            }
            else crr++;
        }
    }
};