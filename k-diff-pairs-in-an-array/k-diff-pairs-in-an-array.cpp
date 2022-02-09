class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        
        int cnt = 0;
        
        for(int i=0;i<nums.size();i++)
        {
            if(i != 0 && nums[i] == nums[i-1]) continue;
            
            if(k !=0 )
            {
                if(binary_search(nums.begin(),nums.end(),nums[i]+k)) cnt++;
            }
            else
            {
                if(upper_bound(nums.begin(),nums.end(),nums[i]+k) - lower_bound(nums.begin(),nums.end(),nums[i] + k) > 1) cnt++;
            }
        }
        return cnt;
    }
};