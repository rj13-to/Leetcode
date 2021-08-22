class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        int tot=0;
        int a=nums[0];
        int b=0;
        for(int i=1;i<nums.size()-1;i++)
        {
            if(i & 1)
            {
                b=max(a,b+nums[i]);   
            }
            else
            {
                a=max(b,a+nums[i]);
            }
        }
        tot=max(a,b);
        int cnt=0;
        a=nums[1];
        b=0;
        for(int i=2;i<nums.size();i++)
        {
            if(i & 1)
            {
                a=max(b,a+nums[i]);
            }
            else
            {
                b=max(a,b+nums[i]);
            }
        }
        cnt=max(a,b);
        return max(cnt,tot);
    }
};