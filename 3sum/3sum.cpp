class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>v;
        int n=nums.size(),l,r;
        for(int i=0;i<n;i++){
            if(i!=0 && nums[i]==nums[i-1]) continue;
            l=i+1;
            r=n-1;
            while(l<r){
                if(nums[l]+nums[r]>-nums[i]) r--;
                else if(nums[l]+nums[r]<-nums[i]) l++;
                else{
                    v.push_back({nums[i],nums[l],nums[r]});
                    l++;r--;
                    while(l<r && nums[l]==nums[l-1]) l++;
                    while(l<r && nums[r]==nums[r+1]) r--;
                }
            }
        }
        return v;
    }
};