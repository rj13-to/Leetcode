class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) 
    {
        map<int,int>mp;
        int ans = 0;
        for(int i=0;i<time.size();i++)
        {
            time[i] %= 60;
            ans += mp[(60-time[i])%60];
            mp[time[i]]++;
        }
        return ans;
    }
};