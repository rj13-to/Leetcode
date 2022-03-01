class Solution {
public:
    vector<int> countBits(int n) {
        if(n==0) return {0};
        vector<int>arr(n+1);
        arr[0]=0;arr[1]=1;
        int k=1;
        for(int i=2;i<=n;i++)
        {
            if(i==2*k)
            {
                k=i;
                arr[i]=1;
            }
            else
            {
                arr[i]=arr[k]+arr[i-k];
            }
        }
        return arr;
    }
};