class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int>mp;
        int p=0,k=0,in=0;
        for(int i=0;s[i];i++){
            if(mp.find(s[i])!=mp.end()){
                if(mp[s[i]]>=in){
                    k=k>i-in?k:i-in;
                    in=mp[s[i]]+1;
                    mp[s[i]]=i;
                }
                else mp[s[i]]=i;
            }
            else mp[s[i]]=i;
        }
        return k>(s.size()-in)?k:(s.size()-in);
    }
};