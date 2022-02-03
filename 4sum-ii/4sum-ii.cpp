class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        vector<long long>s1;
        map<int,int>mp;
        for(int i=0;i<D.size();i++){
            for(int j=0;j<D.size();j++)
                mp[D[i]+C[j]]++;
        }
        int tot=0;
        for(int i=0;i<A.size();i++){
            for(int j=0;j<B.size();j++){
                    if(mp.find(-(A[i]+B[j]))!=mp.end()) tot+=mp[-(A[i]+B[j])];
            }
        }
        return tot;
    }
};