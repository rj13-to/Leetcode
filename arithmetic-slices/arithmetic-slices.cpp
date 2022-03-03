class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        int ans = 0, tot = 2;
        for(int i = 1; i < n-1; i++)
        {
            if(nums[i]-nums[i-1] == nums[i+1]-nums[i])
            {
                tot++;
            }
            else
            {
                int here = (tot*(tot+1))/2;
                here -= 2*tot-1;
                ans += here;
                tot = 2;
            }
        }
        int here = (tot*(tot+1))/2;
        here -= 2*tot-1;
        ans += here;
        return ans;
    }
};