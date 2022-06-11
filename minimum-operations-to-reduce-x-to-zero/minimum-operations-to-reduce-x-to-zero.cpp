class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int per[100001],suf[100001];
        per[0]=0;suf[0]=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            per[i+1]=per[i]+nums[i];
        }
        for(int i=n-1;i>=0;i--){
            suf[n-i]=suf[n-i-1]+nums[i];
        }
        int tot=n+1,st=0,ed=n,mid,target;
        for(int i=0;i<=n;i++){
            st=0;ed=n;
            target=x-per[i];
            while(st<=ed){
                mid=st+(ed-st)/2;
                if(suf[mid]==target) break;
                else if(suf[mid]>target) ed=mid-1;
                else st=mid+1;
            }
            if(mid+i<=n && per[i]+suf[mid]==x) tot=min(tot,mid+i);
        }
        if(tot>n) return -1;
        else return tot;
    }
};