class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.rbegin(),nums.rend());
        vector<int>v(nums.size());
        int tot=0,in;
        for(int i=0;i<nums.size();i++)
        {
            for(int j=i-1;j>=0;j--){
                if(nums[j]%nums[i]==0){
                    v[i]=max(v[i],v[j]);
                }
            }
            v[i]++;
            if(tot<v[i])
            {
                tot=v[i];
                in=i;
            }
        }
        vector<int>ans;
        ans.push_back(nums[in]);
        tot--;
        for(int i=in-1;i>=0;i--)
        {
            if(nums[i]%nums[in]==0 && tot==v[i])
            {
                in=i;
                tot--;
                ans.push_back(nums[in]);
            }
        }
        return ans;
    }
};