class Solution {
public:
    
    static bool cmp(pair<int,int>a,pair<int,int>b)
    {
        if(a.first != b.first) return a.first < b.first;
        return a.second > b.second;
    }
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        
        multiset<int>st;
        vector<pair<int,int>>pr;
        for(int i=0;i<buildings.size();i++)
        {
            pr.push_back({buildings[i][0],buildings[i][2]});
            pr.push_back({buildings[i][1],-buildings[i][2]});
        }
        sort(pr.begin(),pr.end(),cmp);
        vector<vector<int>> ans;
        
        int cur = -1;
        for(auto &it : pr)
        {
            if(it.second < 0)
            {
                st.erase(st.lower_bound(-it.second));
            }
            else
            {
                st.insert(it.second);
            }
            
            if(st.size() == 0)
            {
                ans.push_back({it.first,0});
                cur = -1;
            }
            else if(*st.rbegin() != cur)
            {
                cur = *st.rbegin();
                ans.push_back({it.first,cur});
            }
        }
        return ans;
    }
};