class Solution {
public:
    string frequencySort(string s) {
        vector<pair<int,int>>pr(128);
        for(int i=0;i<128;i++) pr[i].second = i;
        for(int i=0;i<s.size();i++) pr[s[i]].first ++ ;
        sort(pr.begin(),pr.end());
        reverse(pr.begin(),pr.end());
        s.clear();
        for(int i=0;i<128;i++)
        {
            while(pr[i].first)
            {
                s+=pr[i].second;
                pr[i].first--;
            }
        }
        return s;
    }
};