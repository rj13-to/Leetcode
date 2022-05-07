class Solution {
public:
    
    bool find132pattern(vector<int>& nums) {
        multiset<int>st;
        for(int i=1;i<nums.size();i++)
        {
            st.insert(nums[i]);
        }
        
        int small = nums[0];
        for(int i=1;i<nums.size();i++)
        {
            st.erase(st.lower_bound(nums[i]));
            
            auto it = st.lower_bound(nums[i]);
            
            if(it != st.begin() && *prev(it) > small)
            {
                return true;
            }
            small = min(small, nums[i]);
        }
        return false;
    }
};