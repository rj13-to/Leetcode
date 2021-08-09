class Solution {
public:
    int dp[205][10005];
    bool fun(vector<int>&nums,int i,int tot)
    {
        if(i==0) return !tot;
        if(dp[i][tot]!=-1) return dp[i][tot];
        if(tot>=nums[i-1]) dp[i][tot]= fun(nums,i-1,tot-nums[i-1]) || fun(nums,i-1,tot);
        else dp[i][tot]= fun(nums,i-1,tot);
        return dp[i][tot];
    }
    bool canPartition(vector<int>& nums) {
        int tot=0;
        for(int i=0;i<nums.size();i++)
        {
            tot+=nums[i];
        }
        if(tot & 1) return 0;
        tot/=2;
        // int arr[nums.size()+1][tot+1];
        // memset(arr,0,sizeof(arr));
        // for(int i=0;i<=nums.size();i++)
        // {
        //     arr[i][0]=1;
        // }
        // for(int i=1;i<=tot;i++)
        // {
        //     arr[0][i]=0;
        // }
        // for(int i=1;i<=nums.size();i++)
        // {
        //     for(int j=nums[i-1];j<=tot;j++)
        //     {
        //         //cout<<i<<" "<<j<<endl;
        //         arr[i][j]|=arr[i][j-nums[i-1]]| arr[i-1][j]; 
        //     }
        // }
        // //cout<<"yes"<<endl;
        // for(int i=0;i<=nums.size();i++)
        // {
        //     for(int j=0;j<=tot;j++)
        //     {
        //         cout<<arr[i][j]<<" ";
        //     }cout<<endl;
        // }
        memset(dp,-1,sizeof(dp));
        return fun(nums,nums.size(),tot);
        //return arr[nums.size()][tot];
    }
};