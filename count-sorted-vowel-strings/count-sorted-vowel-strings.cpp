class Solution {
public:
    int countVowelStrings(int n) {
        int arr[51][5], tot[51]={0};
        for(int i=0;i<5;i++){arr[1][i]=1;}
        tot[1]=5;
        for(int i=2;i<=n;i++){
            arr[i][0]=tot[i-1];
            tot[i]+=arr[i][0];
            for(int j=1;j<5;j++){
                arr[i][j]=arr[i][j-1]-arr[i-1][j-1];
                tot[i]+=arr[i][j];
            }
        }
        return tot[n];
    }
};