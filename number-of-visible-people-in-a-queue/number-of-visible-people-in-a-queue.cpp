class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) 
    {
        int n = heights.size();
        stack<int>st;
        vector<int>ans(n);
        for(int i = n-1;i>=0;i--)
        {
            int cnt = 0;
            while(st.size())
            {
                cnt++;
                if(st.top() > heights[i])
                {
                    break;
                }
                st.pop();
            }
            ans[i] = cnt;
            st.push(heights[i]);
        }
        return ans;
    }
};