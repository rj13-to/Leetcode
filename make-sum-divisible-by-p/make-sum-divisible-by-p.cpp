class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        long long tot=0;
        map<long long,long long>mp;
        for(int i=0;i<nums.size();i++){
            tot+=nums[i];
        }
        long long mod=tot%(long long)p;
        if(mod==0) return 0;
        long long cnt=0;
        mp[0]=-1;
        cnt=nums.size();
        tot=0;
        for(int i=0;i<nums.size();i++)
        {
            tot+=nums[i];
            tot%=p;
            if(mp.find((tot-mod+p)%p)!=mp.end())
            {
                cnt=min(cnt,i-mp[(tot-mod+p)%p]);
            }
            mp[tot]=i;
            
        }
       
        return cnt==nums.size()?-1:cnt;
    }
};