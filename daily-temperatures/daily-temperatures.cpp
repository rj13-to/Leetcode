class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        stack<pair<int,int>>st;
        int k;
        for(int i=temp.size()-1;i>=0;i--){
            k=i;
            while(st.size() && st.top().first<=temp[i]) st.pop();
            if(st.size())
            {
                k=st.top().second;
            }
            st.push({temp[i],i});
            temp[i]=k-i;
        }
        return temp;
    }
};