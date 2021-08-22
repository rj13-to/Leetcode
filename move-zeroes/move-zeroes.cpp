class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int st=0,n=nums.size();
        int j=0;
        for(int i=0;i<n;i++){
            if(nums[i]) nums[j++]=nums[i];
        }
        while(j<nums.size())
        {
            nums[j]=0;
            j++;
        }
    }
};