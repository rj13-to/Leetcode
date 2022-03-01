class Solution {
public:
    
    static bool compare(pair<int,int>a,pair<int,int>b)
    {
       return a.second>b.second;
    }
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        vector<pair<int,int>>pr;
        for(int i=0;i<plantTime.size();i++)
        {
            pr.push_back({plantTime[i],growTime[i]});
        }
        sort(pr.begin(),pr.end(),compare);
        int day = 0;
        int time = 0;
        for(int i=0;i<pr.size();i++)
        {
            
            day += pr[i].first;
            
            time = max(time,day+pr[i].second);
        }
        return time;
    }
};