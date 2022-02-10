class Solution {
public:
    int eatenApples(vector<int>& apples, vector<int>& days) {
        map<int,int>mp;
        
        int ans = 0;
        for(int i=0; i<apples.size(); i++)
        {
            if(apples[i] != 0) mp[days[i] + i] += apples[i];
            
            while(mp.size() && mp.begin()->first <= i) mp.erase(mp.begin());
            
            if(mp.size())
            {
                mp.begin()->second--;
                if(mp.begin()->second == 0) mp.erase(mp.begin());
                ans++;
            }
        }
        
        int cur_day = apples.size();
        
        for(auto it= mp.begin();it!=mp.end();it++)
        {
            if(cur_day >= it->first)
            {
                continue;
            }
            ans += min(it->second,it->first-cur_day);
            
            cur_day += min(it->second,it->first-cur_day);
        }
       return ans;
    }
};