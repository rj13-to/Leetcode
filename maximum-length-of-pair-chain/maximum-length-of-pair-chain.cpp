class Solution {
public:
    
    static bool compare(vector<int>&a,vector<int>&b)
    {
        return a[1] < b[1];
    }
    int findLongestChain(vector<vector<int>>& pairs) 
    {
        sort(pairs.begin(),pairs.end(),compare);
        int ans = 1;
        int end = pairs[0][1];
        
        for(int i=1;i<pairs.size();i++)
        {
            if(end < pairs[i][0])
            {
                ans++;
                end = pairs[i][1];
            }
        }
        return ans;
    }
};