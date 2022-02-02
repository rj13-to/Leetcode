class Solution {
public:
    vector<int> findAnagrams(string s, string p) 
    {
        if(p.size() > s.size()) return {};
        int req[26] = {0};
        for(int i=0;i<p.size();i++)
        {
            req[p[i]-'a']++;
        }
        int arr[26]={0};
        int match = 0;
        for(int i=0;i<26;i++) if(req[i] == 0) match++;
        
        vector<int>v;
        for(int i=0;i<p.size();i++)
        {
            arr[s[i]-'a']++;
            if(arr[s[i]-'a'] == req[s[i]-'a']) match++;
            else if(arr[s[i]-'a'] == req[s[i]-'a'] + 1) match--;
        }
        
        for(int i = p.size(); i < s.size(); i++)
        {
            if(match == 26) v.push_back(i-p.size());
            arr[s[i-p.size()] - 'a']--; 
            if(arr[s[i-p.size()] - 'a'] == req[s[i-p.size()]-'a']) match++;
            else if(arr[s[i-p.size()]-'a'] == req[s[i-p.size()]-'a'] - 1) match--;
            
            arr[s[i]-'a']++;
            if(arr[s[i]-'a'] == req[s[i]-'a']) match++;
            else if(arr[s[i]-'a'] == req[s[i]-'a'] + 1) match--;
            
        }
        if(match == 26) v.push_back(s.size()-p.size());
        return  v;
    }
};