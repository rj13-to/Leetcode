class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int k=s1.size(),n=s2.size();;
        int arr[26]={0};
        int brr[26]={0};
        if(k>n) return 0;
        for(int i=0;i<k;i++){
            arr[s1[i]-'a']++;
            brr[s2[i]-'a']++;
        }
        
        bool ok;
        for(int i=0;i<n-k;i++){
            ok=0;
            for(int j=0;j<26;j++){
                if(arr[j]!=brr[j]){
                    ok=1;
                    break;
                }
            }
            if(ok){
                brr[s2[i]-'a']--;
                brr[s2[i+k]-'a']++;
            }
            else return 1;
        }
        for(int i=0;i<26;i++) if(arr[i]!=brr[i]){return 0;}return 1;
    }
};