class Solution {
public:
    vector<vector<int>>v;
    void subrec(vector<int>& nums,int i,vector<int>ans){
        if(i==nums.size()){
            v.push_back(ans);
            return ;
        }
        subrec(nums,i+1,ans);
        ans.push_back(nums[i]);
        subrec(nums,i+1,ans);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        subrec(nums,0,{});
        return v;
    }
};