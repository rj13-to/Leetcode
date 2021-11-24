class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& a, vector<vector<int>>& b) {
        int i=0,j=0;
        vector<vector<int>>v;
        while(i<a.size() && j<b.size()){
            if(a[i][1]<b[j][0] ) i++;
            else if(a[i][0]>b[j][1]) j++;
            else{
                v.push_back({max(a[i][0],b[j][0]),min(a[i][1],b[j][1])});
                if(a[i][1]<b[j][1]) i++;
                else j++;
            }   
        }return v;
    }
};