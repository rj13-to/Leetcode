class Solution {
public:
    string reverseWords(string s) {
        int i=0,st,ed;
        while(i<s.size())
        {
            st=i;
            while(i<s.size() && s[i]!=' ')
            {
                i++;
            }
            ed=i-1;
            while(st<ed)
            {
                swap(s[st],s[ed]);
                st++;
                ed--;
            }
            i++;
        }
        return s;
    }
};