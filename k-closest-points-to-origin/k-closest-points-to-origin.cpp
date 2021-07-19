class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& arr, int k) {
        priority_queue<pair<int,int>>pq;
        for(int i=0;i<arr.size();i++){
            pq.push({-arr[i][0]*arr[i][0]-arr[i][1]*arr[i][1],i});
        }
        vector<vector<int>>v;
        while(k--)
        {
            v.push_back(arr[pq.top().second]);
            pq.pop();
        }
        return v;
    }
};