class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int arr[10001];
        memset(arr,-1,sizeof(arr));
        stack<int>st;
        for(int i=nums2.size()-1;i>=0;i--)
        {
            while(st.size() && st.top()< nums2[i]) st.pop();
            if(st.size()) arr[nums2[i]] = st.top();
            st.push(nums2[i]);
        }
        for(int i=0;i<nums1.size();i++) nums1[i] = arr[nums1[i]];
        return nums1;
    }
};