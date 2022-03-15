class Solution {
public:
    string minRemoveToMakeValid(string s) 
    {
        int cnt =0;
        string ans = "";
        for(int i=0;i<s.size();i++)
        {
            if(s[i] == '(')
            {
                cnt++;
                ans += s[i];
            }
            else if(s[i] == ')')
            {
                cnt--;
                if(cnt < 0)
                {
                    cnt = 0;
                }
                else
                {
                    ans += s[i];
                }
            }
            else ans += s[i];
        }
        int i = ans.size()-1;
        while(cnt > 0 && i>=0)
        {
            if(ans[i] == '(')
            {
                cnt--;
                ans[i] = '#';
            }
            i--;
        }
        s = "";
        for(int i=0;i<ans.size();i++) if(ans[i]!='#') s+= ans[i];
        return s;
    }
};