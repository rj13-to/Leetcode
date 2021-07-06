class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int,int>mp;
        for(int i=0;i<arr.size();i++)
        {
            mp[arr[i]]++;
        }
        int tot=arr.size();
        multiset<int>ms;
        for(auto it=mp.begin();it!=mp.end();it++)
        {
            ms.insert(-it->second);
        }
        int cnt=0;
        for(auto it=ms.begin();it!=ms.end();it++)
        {
            tot+=*it;
            cnt++;
            if(tot*2<=arr.size())  return cnt;
        }
        return cnt;
    }
};