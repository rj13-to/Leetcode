class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        sort(nums.begin(),nums.end());// nlog(n)
        
        vector<vector<int>>ans;
        for(int i=0;i<nums.size();i++)
        {
            if(i != 0 && nums[i] == nums[i-1]) continue;
            int st = i+1;
            int ed = nums.size()-1;
            while(st < ed)
            {
                if(-nums[i] < nums[st]+nums[ed]) 
                {
                    ed--;
                }
                else if(-nums[i] > nums[st]+nums[ed]) 
                {
                    st++;
                }
                else
                {
                    ans.push_back({nums[i],nums[st],nums[ed]});
                    st++;
                    ed--;
                    while(st<ed && nums[st] == nums[st-1]) 
                    {
                        st++;
                    }
                    while(ed>st && nums[ed] == nums[ed+1]) ed--;
                        
                }
            }
        }
        return ans;
    }
};











