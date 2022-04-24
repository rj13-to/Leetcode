class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        const int k = 1e6+5;
        int arr[k]={0};
        for(int i=0;i<nums.size();i++)
            arr[nums[i]]++;
        vector<int>ans;
        if(arr[0])
        {
            if(arr[0] == 1 && arr[1] == 0) ans.push_back(0);
        }
        for(int i=1;i<k-1;i++)
        {
            if(arr[i] == 1 && arr[i-1] == 0 && arr[i+1] == 0) ans.push_back(i);
        }
        return ans;
    }
};