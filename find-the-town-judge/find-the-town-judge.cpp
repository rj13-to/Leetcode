class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int>v(n+1),g(n+1);
        for(int i=0;i<trust.size();i++){
            v[trust[i][0]]++;
            g[trust[i][1]]++;
        }
        for(int i=1;i<=n;i++){
            if(g[i]==n-1 && v[i]==0) return i;
        }return -1;
    }
};