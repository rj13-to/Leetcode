class Solution {
public:
    int rob(vector<int>& nums) {
        int a=nums[0];
        if(nums.size()==1) return a;
        int b=0;
        for(int i=1;i<nums.size();i++)
        {
            if(i & 1)
            {
                b = max(a,b+nums[i]);
            }
            else
            {
                a=max(b,a+nums[i]);
            }
        }
        return max(a,b);
    }
};