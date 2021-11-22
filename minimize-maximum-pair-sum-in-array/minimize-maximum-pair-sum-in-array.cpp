class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int arr[100005]={0};
        for(int i=0;i<nums.size();i++) arr[nums[i]]++;
        int i=0,j=100000;
        int tot = 0;
        int n = nums.size()/2;
        while(n--)
        {
            while(i< 100003 && arr[i] == 0) i++;
            while(j> -1 && arr[j] == 0) j--;
            tot = max(tot,i+j);
            arr[i]--;
            arr[j]--;
        
        }
        return tot;
    }
};