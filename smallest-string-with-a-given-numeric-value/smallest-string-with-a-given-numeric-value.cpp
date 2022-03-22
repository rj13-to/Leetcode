class Solution {
public:
    string getSmallestString(int n, int k) 
    {
        string ans = "";
        
        for(int i=1;i<=n;i++)
        {
            int left = k-(n-i)*26;
            
            if(left < 1)
            {
                ans += 'a';
                k--;
            }
            else
            {
                ans += 'a'+left-1;
                k -= left;
            }
        }
        return ans;
    }
};