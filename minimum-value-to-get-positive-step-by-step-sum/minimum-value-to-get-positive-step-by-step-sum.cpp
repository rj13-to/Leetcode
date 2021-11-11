class Solution {
public:
    int minStartValue(vector<int>& nums) 
    {
        int mi = 0;
        int crr =0;
        for(int i=0;i<nums.size();i++)
        {
            crr += nums[i];
            mi = min(crr,mi);
        }
        if(mi > 0) return 0;
        return -mi+1;
        
    }
};