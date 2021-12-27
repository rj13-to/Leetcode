class Solution {
public:
    int findComplement(int num) {
                
long long f = floor(log2(num))+1,z=1;
        for(int i=0;i<f;i++) z*=2;
        z--;
        return z^num;
    }
};