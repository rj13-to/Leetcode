class Solution {
public:
    int numRescueBoats(vector<int>& nums, int limit) {
        sort(nums.begin(),nums.end());
        int l=0,r=nums.size()-1;
        int tot=0;
        while(l<r){
            if(nums[l]+nums[r]<=limit){
                l++;
                r--;
            }else r--;
            tot++;
        }
        if(l==r) tot++;
        return tot;
    }
};