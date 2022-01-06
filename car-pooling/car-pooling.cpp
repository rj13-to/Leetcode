class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int arr[1002]={0};
        int k(0);
        for(int i=0;i<trips.size();i++){
            arr[trips[i][1]]+=trips[i][0];
            arr[trips[i][2]]-=trips[i][0];
        }
        for(int i=0;i<1002;i++){
            k+=arr[i];
            if(k>capacity) return false;
        }
        return true;
    }
};