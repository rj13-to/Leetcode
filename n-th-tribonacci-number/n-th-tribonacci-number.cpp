class Solution {
public:
    int tribonacci(int n) {
        if(n==0) return 0;
        else if(n<3) return 1;
        int a=0,b=1,c=1;
        int k=3;
        while(k<=n)
        {
            c+=b+a;
            b+=a;
            a=b-a;
            b=c-b;
            k++;
        }
        return c;
    }
};