class Solution {
public:
    vector<vector<int>> ans;
    vector<int>v;
    string s = "000000";
    void fun(vector<int>& nums)
    {
        if(v.size() == nums.size()) 
        {
            ans.push_back(v);
            return;
        }
        else
        {
            for(int i=0;i<nums.size();i++)
            {
                if(s[i] == '0')
                {
                    v.push_back(nums[i]);
                    s[i] = '1';
                    fun(nums);
                    v.pop_back();
                    s[i] = '0';
                }
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) 
    {
        fun(nums);
        return ans ;
    }
};