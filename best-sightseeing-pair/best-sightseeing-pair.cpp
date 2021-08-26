class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) 
    {
        int ans=INT_MIN;
        values.back()-=values.size()-1;
        for(int i=values.size()-2;i>=0;i--)
        {
            ans=max(ans,values[i]+i+values[i+1]);
            values[i]=max(values[i]-i,values[i+1]);
        }
        return ans;
    }
};