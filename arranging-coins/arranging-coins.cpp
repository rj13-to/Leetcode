class Solution {
public:
    int arrangeCoins(int n) 
    {
        return (-1+(long long)sqrt(1+(long long)8*(long long)(n)))/2;
    }
};