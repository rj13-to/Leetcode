class Solution {
public:
    int findMaxLength(vector<int>& nums) 
    {
        unordered_map<int,int>mp;
        mp[0] = -1;
        int zero = 0,one = 0;
        int ans = 0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i] == 0) zero++;
            else one++;
            
            if(mp.find(one-zero) != mp.end())
            {
                ans = max(ans,i-mp[one-zero]);
            }
            else
            {
                mp[one-zero] = i;
            }
        }
        return ans;
    }
};