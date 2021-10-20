class Solution {
public:
    string reverseWords(string s) {
        int i=s.size()-1,j=s.size()-1;
        string ans ="";
        while(i>=0)
        {
            while(i>=0 && s[i]!=' ') i--;
            if(i != j)
            {
                ans+= s.substr(i+1,j-i);
                if( i>= 0) ans+=" ";
            }
            i--;
            j=i;
        }
        j=ans.size()-1;
        while(j>=0 && ans[j] == ' ') j--;
        ans = ans.substr(0,j+1);
        return ans;
    }
};