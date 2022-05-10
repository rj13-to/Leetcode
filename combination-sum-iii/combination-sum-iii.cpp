class Solution {
public:
    vector<vector<int>>ans;
    void fun(int k,int n,int cur,vector<int>& v)
    {
        if(k == 0)
        {
            if(n == 0) ans.push_back(v);
            return;
        }
        if(cur == 10 || cur > n) return;
        
        fun(k,n,cur+1,v);
        v.push_back(cur);
        fun(k-1,n-cur,cur+1,v);
        v.pop_back();
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> v;
        fun(k,n,1,v);
        return ans;
    }
};