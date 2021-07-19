class Solution {
public:
    int ans=0;
    void fun(int i,vector<int>&nums,int crr)
    {
        ans+=crr;
       
        for(int j=i;j<nums.size();j++)
        {
            crr^=nums[j];
            fun(j+1,nums,crr);
            crr^=nums[j];
        }
    }
    int subsetXORSum(vector<int>& nums) {
        fun(0,nums,0);
        return ans;
    }
};