class Solution {
public:
    int longestStrChain(vector<string>& words) {
        vector<vector<string>>v(17);
        for(int i=0;i<words.size();i++){
            v[words[i].size()].push_back(words[i]);
        }
        int tot=0,cnt=0,a=0,b=0;
        vector<vector<int>>dp(17,vector<int>(1000));
        for(int i=15;i>0;i--){
            for(int k=0;k<v[i].size();k++){
                for(int j=0;j<v[i+1].size();j++){
                    a=0;b=0;
                    while(a<v[i+1][j].size()){
                        if(v[i][k][b]==v[i+1][j][a]){a++;b++;}
                        else a++;
                    }
                    if(b==v[i][k].size()){
                        dp[i][k]=1+dp[i+1][j];
                        cnt=max(cnt,dp[i][k]);
                    }
                }
            }
        } return cnt+1;
    }
};