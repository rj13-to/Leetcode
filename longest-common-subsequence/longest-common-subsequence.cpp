class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size();
        int m=text2.size();
        vector<int> arr[128];
        int fre[128]={0};
        for(int i=0;i<n;i++)
        {
            fre[text1[i]]=1;
        }
        for(int i=m-1;i>=0;i--){
            if(fre[text2[i]])
            {
                arr[text2[i]].push_back(i);
            }
        }
        vector<int>nums;
        for(int i=0;i<n;i++)
        {
            if(arr[text1[i]].size()){
                nums.insert(nums.end(),arr[text1[i]].begin(),arr[text1[i]].end());
            }
        }
        vector<int>z;
        for(int i=0;i<nums.size();i++){
            auto it=lower_bound(z.begin(),z.end(),nums[i]);
            if(it==z.end()) z.push_back(nums[i]);
            else *it=nums[i];
        }
        return z.size();
    }
};