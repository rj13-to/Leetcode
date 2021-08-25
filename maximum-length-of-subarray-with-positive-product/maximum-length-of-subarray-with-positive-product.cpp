class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int cnt=0;
        int st=-1,ed=-1;
        int ans=0;
        int j=0,i;
        for(i=0;i<nums.size();i++)
        {
            if(nums[i]<0)
            {
                cnt++;
                if(cnt==1) st=i;
                ed=i;
            }
            else if(nums[i]==0)
            {
                if(cnt & 1)
                {
                    ans=max(ans,ed-j);
                    ans=max(ans,i-st-1);
                }
                else ans=max(ans,i-j);
                j=i+1;
                cnt=0;
            }
        }
        if(cnt & 1)
        {
            ans=max(ans,ed-j);
            ans=max(ans,i-st-1);
        }
        else ans=max(ans,i-j);
        return ans;
    }
};