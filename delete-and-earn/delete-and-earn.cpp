class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int arr[10005]={0};
        for(int i=0;i<nums.size();i++)
        {
            arr[nums[i]]++;
        }
        int a=0,b=0;
        for(int i=1;i<10001;i++)
        {
            if(i & 1)
            {
                b=max(a,b+arr[i]*i);
            }
            else
            {
                a=max(b,a+arr[i]*i);
            }
        }
        return  max(a,b);
    }
};