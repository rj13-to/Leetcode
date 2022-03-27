class Solution {
public:
    int count(vector<int>&v)
    {
        int l = 0, h = v.size();
        int mid;
        while(l<h)
        {
            mid = (l+h)/2;
            
            if(v[mid] == 0) h = mid;
            else l = mid+1;
        }
        return h;
    }
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) 
    {
        priority_queue<pair<int,int>>pr;
        
        for(int i=0;i<mat.size();i++)
        {
            int cnt = count(mat[i]);
            
            pr.push({cnt,i});
            if(pr.size() > k) pr.pop();
        }
        
        vector<int>ans(k);
        while(k--)
        {
            ans[k] = pr.top().second;
            pr.pop();
        }
        return ans;
    }
};