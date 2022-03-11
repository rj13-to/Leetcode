class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int ans =0, prev =0;
        
        int cnt;
        for(int i=0;i<bank.size();i++)
        {
            cnt =0;
            for(int j=0;j<bank[0].size();j++)
            {
                if(bank[i][j] == '1') cnt++;
            }
            if(cnt == 0) continue;
            ans += prev*cnt;
            prev = cnt;
        }
        return ans;
    }
};