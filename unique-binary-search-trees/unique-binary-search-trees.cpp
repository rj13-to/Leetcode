class Solution {
public:
    int arr[20]={0};
    int ways(int n){
        if(arr[n]!=-1) return arr[n];
        int k=0;
        for(int i=0;i<n;i++){
            k+=ways(n-i-1)*ways(i);
        }
        arr[n]=k;
        return k;
    }
    int numTrees(int n) {
        memset(arr,-1,sizeof(arr));
        arr[0]=1;
        arr[1]=1;
        arr[2]=2;
        return ways(n);
    }
};