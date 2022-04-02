class Solution {
public:
    bool check(string s,int st,int ed)
    {
        while(st<ed)
        {
            if(s[st] != s[ed]) return false;
            st++;
            ed--;
        }
        return true;
    }
    bool validPalindrome(string s) {
        int st= 0, ed = s.size()-1;
        
        while(st < ed)
        {
            if(s[st] == s[ed])
            {
                st++;
                ed--;
            }
            else 
            {
                return check(s,st,ed-1) || check(s,st+1,ed);
            }
        }
        return true;
    }
};