class Solution {
public:
    int countSpecialSubsequences(vector<int>& nums) 
    {
        long long zero = 0, one = 0, two = 0;
        long long mod = 1e9+7;
         for(int i=nums.size()-1;i>=0;i--)
         {
             if(nums[i] == 2)
             {
                 two = 2*two + 1;
                 two %= mod;
             }
             else if(nums[i] == 1)
             {
                 one += one + two;
                 one %= mod;
             }
             else
             {
                 zero += zero + one;
                 zero %= mod;
             }
         }
        return zero;
    }
};