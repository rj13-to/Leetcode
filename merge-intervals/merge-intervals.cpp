class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& v) {
        int a[10001]={0};
        int b[10001]={0};
        vector<vector<int>>f;
        for(int i=0;i<v.size();i++){
            a[v[i][0]]++;
            b[v[i][1]]--;
        }
        int k=0;bool ok=1;
        for(int i=0;i<10001;i++){
            k+=a[i];
            if(ok && k>0){
                f.push_back({i,i});ok=0;
            }
            k+=b[i];
            if(k==0 && !ok){
                f.back()[1]=i;ok=1;
            }
        }return f;
    }
};