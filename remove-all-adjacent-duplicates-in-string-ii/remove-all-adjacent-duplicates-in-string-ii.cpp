class Solution {
public:
    string removeDuplicates(string s, int k) 
    {
        stack<pair<char,int>> st;
        for(int i=0;i<s.size();i++)
        {
            if(st.empty())
            {
                st.push({s[i],1});
            }
            else if(st.top().first == s[i])
            {
                st.top().second++;
                
                if(st.top().second == k) st.pop();
            }
            else
            {
                st.push({s[i],1});                
            }
        }
        s = "";
    
        while(st.size())
        {
            string cur(st.top().second,st.top().first);
            s += cur;
            st.pop();
        }
        reverse(s.begin(),s.end());
        return s;
    }
    
};