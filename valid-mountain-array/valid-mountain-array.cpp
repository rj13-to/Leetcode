class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        if(arr.size() < 3) return 0;
        if(arr[1] <= arr[0]) return 0;
        if(arr[arr.size()-2] <= arr.back()) return 0;
        bool ok = 1;
        for(int i= 1;i<arr.size();i++)
        {
            if(arr[i] == arr[i-1]) return 0;
            if(arr[i] <arr[i-1])
            {
                for(int j = i+1;j<arr.size();j++)
                {
                    if(arr[j] >= arr[j-1]) return 0;
                }
                return 1;
            }
        }
        return 0;
    }
};