class Solution {
public:
    int findKthNumber(int m, int n, int k) 
    {
        int st =1,ed=m*n,mid;
        while(st<ed)
        {
            mid = (st+ed)/2;
            int cnt = 0;
            for(int i=1;i<=m;i++) 
            {
                cnt += min(mid/i,n);
            }
            if(cnt< k) st =mid+1;
            else ed=mid;
        }
        return st;
    }
};