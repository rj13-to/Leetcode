class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        priority_queue<pair<int,int>>pq;
        int j;
        for(int i=0;i<nums.size();)
        {
            j=i+1;
            while(j<nums.size() && nums[j]==nums[i]) j++;
            pq.push({j-i,nums[i]});
            i=j;
        }
        vector<int>v;
        while(k--)
        {
            v.push_back(pq.top().second);
            pq.pop();
        }
        return v;
    }
};