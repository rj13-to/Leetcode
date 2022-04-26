class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& restrictions) 
    {
        sort(restrictions.begin(),restrictions.end());
        
        int prev = 0;
        int gap,height_diffrence ;
        if(restrictions.size()) restrictions[0][1] = min(restrictions[0][1],restrictions[0][0]-1);
        
        for(int i=1;i<restrictions.size();i++)
        {
            gap = restrictions[i][0]-restrictions[i-1][0];
            
            height_diffrence = abs(restrictions[i][1]-restrictions[i-1][1]);
            
            if(height_diffrence > gap && restrictions[i][1] > restrictions[i-1][1])
            {
                restrictions[i][1] = restrictions[i-1][1] + gap;
            }
        }
        for(int i = restrictions.size()-2;i>=0;i--)
        {
            gap = restrictions[i+1][0] - restrictions[i][0];
            
            height_diffrence = abs(restrictions[i][1]- restrictions[i+1][1]);
            
            if(height_diffrence > gap && restrictions[i][1] > restrictions[i+1][1])
            {
                restrictions[i][1] = restrictions[i+1][1] + gap;
            }
        }

        int ans = restrictions.size() ? (restrictions[0][0]-1+restrictions[0][1])/2:0;
        //cout<<ans<<endl;
        for(int i=1;i<restrictions.size();i++)
        {
            ans = max(ans, (restrictions[i][0]-restrictions[i-1][0]+restrictions[i][1]+restrictions[i-1][1])/2);
           // cout<<ans<<endl;
        }
        prev = restrictions.size()? restrictions.back()[1]-restrictions.back()[0]:-1;
        ans = max(ans,n+prev);
        //cout<<ans<<endl;
        return ans;
    }
};