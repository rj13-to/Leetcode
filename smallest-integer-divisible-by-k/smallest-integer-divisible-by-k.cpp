class Solution {
public:
    int smallestRepunitDivByK(int k) 
    {
        set<int>se;
        int l = 1;
        int ans = 1;
        while(true)
        {
            l %= k;
            if(l == 0) return ans;
            else if(se.count(l)) return -1;
            se.insert(l);
            ans++;
            l*=10;
            l++;
            
        }
        return -1;
    }
};