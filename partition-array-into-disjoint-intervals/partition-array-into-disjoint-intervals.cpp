class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        vector<int>arr;
        arr.push_back(nums.back());
        for(int i=nums.size()-2;i>=0;i--)
        {
            arr.push_back(min(arr.back(),nums[i]));
        }
        reverse(arr.begin(),arr.end());
        int ma=nums[0];
        int tot=0;
        for(int i=1;i<nums.size();i++)
        {
            if(ma<=arr[i]) return i;
            ma=max(nums[i],ma);
        }
        return 0;
    }
};