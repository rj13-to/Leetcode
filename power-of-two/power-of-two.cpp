class Solution {
public:
    bool isPowerOfTwo(int n) {
        return (n!=0) && (floor(log2(n))==ceil(log2(n)));
    }
};