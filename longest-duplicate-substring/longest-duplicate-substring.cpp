class Solution {
public:
    string longestDupSubstring(string S) {
        int n = S.length();
        string res;
        unordered_set<string_view>set;
        int l = 1, r = n;
        
        while (l <= r) {
            int m = l + ((r-l)>>1);
            bool found = false;
            for (int i = 0; i+m <= n; i++) {
                auto [it, inserted] = set.emplace(S.data()+i, m);
                if (!inserted) {
                    found = true;
                    res = move(*it);
                    break;
                }
            }
            
            if (found)
                l = m+1;
            else
                r = m-1;
        }
        
        return res;
    }
};