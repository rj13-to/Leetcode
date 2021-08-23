class Solution {
public:
    void rec(vector<char>& s, int st ,int ed){
        if(st>=ed) return;
        swap(s[st++],s[ed--]);
        rec(s,st,ed);
    }
    void reverseString(vector<char>& s) {
        rec(s,0,s.size()-1);
    }
};