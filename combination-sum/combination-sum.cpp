class Solution {
public:
   vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<vector<int>>> dp(target+1);
    sort(candidates.begin(), candidates.end());
    dp[0].push_back({});
    for(int i=0; i<target; ++i){
        for(auto n: candidates){
            if(i+n>target) break;
            for(auto v: dp[i]){
                if(v.empty() || v.back()<=n){
                    v.push_back(n);
                    dp[i+n].push_back(v);
                }
            }
        }
    }
    return dp[target];
}
};