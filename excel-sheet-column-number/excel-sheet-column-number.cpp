class Solution {
public:
    int titleToNumber(string columnTitle) 
    {
        long long st = 1;
        int ans = 0;
        for(int i= columnTitle.size()-1;i>=0;i--)
        {
            ans += st*(columnTitle[i]-'A'+1);
            st*=26;
        }
        return ans;
    }
};