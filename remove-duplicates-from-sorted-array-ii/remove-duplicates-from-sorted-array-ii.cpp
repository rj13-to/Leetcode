class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        vector<int>v;int tot=0;
        for(int i=0;i<nums.size();i++){
            if(i==0){v.push_back(nums[i]);tot++;}
            else{
                if(nums[i]==nums[i-1]){
                    tot++;
                    if(tot<3) v.push_back(nums[i]);
                }
                else{v.push_back(nums[i]);tot=1;}
            }
        }
        nums=v;
        return nums.size();
    }
};