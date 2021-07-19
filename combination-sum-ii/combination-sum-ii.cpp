class Solution {
public:
    vector<vector<int>>ans;
    void fun(vector<int>&v,vector<int>&can,int target,int i)
    {
        if(target==0) ans.push_back(v);
        if(i==can.size() || can[i]>target)  return ;
        for(int j=i;j<can.size();j++)
        {
            if(can[j]>target) return ;
            if(j!=i && can[j]==can[j-1]) continue;
            v.push_back(can[j]);
            fun(v,can,target-can[j],j+1);
            v.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) 
    {
        sort(candidates.begin(),candidates.end());
        vector<int>v;
        for(int i=0;i<candidates.size();i++)
        {
            if(candidates[i]>target) break;
            if(i!=0 && candidates[i]==candidates[i-1]) continue;
            v.push_back(candidates[i]);
            fun(v,candidates,target-candidates[i],i+1);
            v.pop_back();
        }
        return ans;
    }
};