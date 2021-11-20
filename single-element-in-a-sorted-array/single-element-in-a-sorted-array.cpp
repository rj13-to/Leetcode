class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int x=0;
        int i=0;
        while(i<nums.size())
        {
            x^=nums[i];
            i++;
        }
        return x;
    }
};