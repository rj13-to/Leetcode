class Solution {
public:
    bool wordPattern(string pattern, string s) 
    {
        vector<string>v(26,"");
        int i = 0,j=0,k=0;
        map<string,char>mp;
        while(i<pattern.size() && j<s.size())
        {
            while(k < s.size() && s[k] != ' ')
            {
                k++;
            }
           
            string str = s.substr(j,k-j);
            if(mp.count(str) && mp[str] != pattern[i] )
            {
                return 0;
            }
            else
            {
                mp[str] = pattern[i];
            }
            if(v[pattern[i]-'a'] == "")
            {
                v[pattern[i]-'a'] = str;
            }
            else if(v[pattern[i]-'a'] != str) return 0;
            i++;
            k++;
            j = k;
        }
        
        if(i != pattern.size() || j < s.size()) return 0;
        return 1;
    }
};