class Solution {
public:
    string findLongestWord(string s, vector<string>& dictionary) 
    {
        int i = 0;
        vector<int>ptr(dictionary.size());
        while(i<s.size())
        {
            for(int j=0;j<dictionary.size();j++)
            {
                if(ptr[j] == dictionary[j].size()) continue;
                if(dictionary[j][ptr[j]] == s[i]) ptr[j]++;
            }
            i++;
        }
        string ans = "";
        for(int i=0;i<dictionary.size();i++)
        {
            if(ptr[i] != dictionary[i].size()) continue;
            if(ans.size()>ptr[i]) continue;
            else if(ans.size()<ptr[i]) ans = dictionary[i];
            else ans = min(ans,dictionary[i]);
        }
        return ans;
    }
};

