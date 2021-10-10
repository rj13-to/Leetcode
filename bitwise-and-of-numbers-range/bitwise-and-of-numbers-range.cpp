class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        long long ans = 0;
        for(long long i=0;i<=30;i++){
            long long a = (1LL<<i);
            long long l = left - a,p = l/(a*2);
            long long l1 = p*a*2 + a,r1 = l1 + a - 1;
            if(left>=l1 and right<=r1)
                ans+=a;
        }
        return (int)ans;
    }
};