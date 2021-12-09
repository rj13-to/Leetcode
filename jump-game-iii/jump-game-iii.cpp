class Solution {
public:
    bool fun(vector<int>& arr, int crr,vector<int>&vis)
    {
        if(crr < 0 || crr >= arr.size() || vis[crr]) return false;
        if(arr[crr] == 0) return 1;
        vis[crr] = 1;
        return fun(arr,crr+arr[crr],vis) || fun(arr,crr-arr[crr],vis);
    }
    bool canReach(vector<int>& arr, int start) {
        vector<int>vis(arr.size());
        return fun(arr,start,vis);
    }
};