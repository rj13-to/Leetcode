class Solution {
public:
    vector<int> partitionLabels(string s) {
        pair<int,int>arr[26];
        memset(arr,-1,sizeof(arr));
        int n=s.size();
        for(int i=0;i<n;i++){
            if(arr[s[i]-97].first==-1){
                arr[s[i]-97].second= arr[s[i]-97].first=i;
            }
            else{
                arr[s[i]-97].second=i;
            }
        }
        vector<int>v;
        sort(arr,arr+26);
        for(int i=0;i<26;i++){
            if(arr[i].first==-1)continue;
            int end=arr[i].second;
            for(int j=i;j<26;j++){
                 if(arr[j].first<=end){
                     end=max(end,arr[j].second);
                 }
                 else{
                     v.push_back(end-arr[i].first+1);
                     i=j-1;break;
                     
                 }
                if(j==25){
                    v.push_back(end-arr[i].first+1);
                     i=j;break;
                }
            }
        }
        return v;
    }
};