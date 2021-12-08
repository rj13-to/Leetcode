class Solution {
public:
    int subarraySum(vector<int>& nums, int k) 
    {
        map<int,int>mp;
        int cnt =0;
        mp[0] = 1;
        int ans =0;
        for(int i=0;i<nums.size();i++)
        {
            cnt+= nums[i];
            
            ans += mp[cnt-k];
            mp[cnt]++;
        }
        return ans;
    }
};

    
