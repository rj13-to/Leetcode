class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int crr=0,tot=INT_MIN;
        for(int i=0;i<nums.size();i++)
        {
            crr+=nums[i];
            if(tot<crr) tot=crr;
            if(crr<0) crr=0;
        }
        return tot;
    }
};