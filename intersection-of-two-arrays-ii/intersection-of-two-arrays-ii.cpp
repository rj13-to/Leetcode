class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        int arr[1001]={0};
        int brr[1001]={0};
        for(int i=0;i<nums1.size();i++)
        {
            arr[nums1[i]]++;
        }
        for(int i=0;i<nums2.size();i++)
        {
            brr[nums2[i]]++;
        }
        vector<int>ans;
        for(int i=0;i<1001;i++)
        {
            while(arr[i] && brr[i])
            {
                arr[i]--;
                brr[i]--;
                ans.push_back(i);
            }
        }
        return ans;
    }
};