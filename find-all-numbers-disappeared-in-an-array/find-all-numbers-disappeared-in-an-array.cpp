class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int>v;
        int i=0,j=1;
        sort(nums.begin(),nums.end());
        while(i<nums.size())
        {
            if(nums[i] == j) 
            {
                j++;i++;
            }
            else if(nums[i]>j)
            {
                v.push_back(j);
                j++;
            }
            else
            {
                i++;
            }
        }
        while(j <= nums.size()) 
        {
            v.push_back(j);
            j++;
        }
        return v;
    }
};