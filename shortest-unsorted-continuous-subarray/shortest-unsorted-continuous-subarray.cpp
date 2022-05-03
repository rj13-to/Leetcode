class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int>v=nums;
        sort(v.begin(),v.end());
        int st=nums.size(),ed=-1;
        for(int i=0;i<nums.size();i++) if(nums[i]!=v[i]){st=i;break;}
        for(int i=nums.size()-1;i>=0;i--) if(nums[i]!=v[i]){ed=i;break;}
        if(st>ed) return 0;
        else return ed-st+1;
    }
};