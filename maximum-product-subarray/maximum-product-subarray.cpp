class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans=INT_MIN,neg=1,pos=1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<0)
            {
                swap(pos,neg);
            }
            pos=max(pos*nums[i],nums[i]);
            neg=min(neg*nums[i],nums[i]);
            ans=max(ans,pos);
        }
        return ans;
    }
};