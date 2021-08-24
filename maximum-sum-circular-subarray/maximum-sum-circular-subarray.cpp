class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int cnt1=0;
        int cnt2=0;
        int tot=0;
        int mim=nums[0];
        int mam=nums[0];
        for(int i=0;i<nums.size();i++)
        {
            cnt1+=nums[i];
            cnt2+=nums[i];
            tot+=nums[i];
            mim=min(mim,cnt1);
            mam=max(mam,cnt2);
            if(cnt1>0) cnt1=0;
            if(cnt2<0) cnt2=0;
        }
        if(mam<0) return mam;
        return max(mam,tot-mim);
    }
};