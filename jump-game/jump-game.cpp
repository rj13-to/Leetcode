class Solution {
public:
    bool canJump(vector<int>& nums) {
        int ma=nums[0];
        for(int i=0;i<nums.size()-1;i++)
        {
            if(ma<i+nums[i]) ma=i+nums[i];
            if(ma==i) return false ;
        }
        return true;
    }
};