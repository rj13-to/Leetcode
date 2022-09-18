class Solution {
public:
    int trap(vector<int>& height) 
    {
        vector<pair<int,int>>v;
        deque<int>dq;
        for(int i=0;i<height.size();i++)
        {
            v.push_back({height[i],i});
        }
        sort(v.begin(),v.end());
        dq.push_back(v.back().second);
        for(int i=height.size()-2;i>=0;i--)
        {
            if(v[i].second>dq.back())
            {
                dq.push_back(v[i].second);
            }
            else if(v[i].second<dq.front())
            {
                dq.push_front(v[i].second);
            }
        }
        int ans=0;
        int k;
        for(int i=1;i<dq.size();i++)
        {
            k=min(height[dq[i]],height[dq[i-1]]);
            ans+=(dq[i]-dq[i-1]-1)*k;
            for(int j=dq[i-1]+1;j<dq[i];j++)
            {
                ans-=height[j];
            }
        }
        return ans;
    }
};