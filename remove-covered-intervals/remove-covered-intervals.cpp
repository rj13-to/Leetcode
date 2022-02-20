class Solution {
public:
    static bool compare(vector<int>&a,vector<int>&b)
    {
        if(a[0] != b[0]) return a[0]<b[0];
        return a[1] > b[1];
    }
    int removeCoveredIntervals(vector<vector<int>>& intervals) 
    {
        sort(intervals.begin(),intervals.end(),compare);
        int st = intervals[0][0];
        int ed = intervals[0][1];
        
        int count = 0;
        
        for(int i=1;i < intervals.size();i++)
        {
            if(intervals[i][1] > ed)
            {
                ed = intervals[i][1];
                st = intervals[i][0];
            }
            else 
            {
                count++;
            }
        }
        return intervals.size() - count;
    }
};