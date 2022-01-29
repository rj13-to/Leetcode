class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<pair<int,int>>st;
        vector<int>v;
        for(int i=0;i<heights.size();i++){
            while(st.size() && st.top().first>=heights[i]) st.pop();
            if(st.size()) v.push_back(st.top().second);
            else v.push_back(-1);
            st.push({heights[i],i});
        }
        while(!st.empty()) st.pop();
        int tot=0;
        for(int i=heights.size()-1;i>=0;i--){
            while(st.size() && st.top().first>=heights[i]) st.pop();
            if(st.size()){
                tot=max(tot,(st.top().second-v[i]-1)*heights[i]);
            }
            else{
                tot=max(tot,(int)((heights.size()-v[i]-1)*heights[i]));
            }
            st.push({heights[i],i});
        }
        return tot;
    }
};