class Solution {
public:
    long long minimalKSum(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int prev = 0;
        
        long long ans = 0;
        for(int i=0;i<nums.size();i++)
        {
            long long gap = nums[i]-prev-1;
            if(gap == -1) continue;
            else if(gap < k)
            {
                ans +=  ((long long)(gap)*((long long)(prev+1)+(long long)(nums[i]-1)))/2;
                k -= gap;
            }
            else
            {
                ans += ((long long)k * ((long long)(prev+1) + (long long)(prev + k)))/2;
                k = 0;
            }
            if(k == 0) return ans;
            prev = nums[i];
        }
        ans += ((long long)k * ((long long)(prev +1 ) + (long long)(prev + k)))/2;
        return ans;
    }
};