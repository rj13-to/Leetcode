class Solution {
public:
    int minDominoRotations(vector<int>& A, vector<int>& B) {
        int a[7]={0},b[7]={0},c[7]={0},d[7]={0};
        for(int i=0;i<A.size();i++){
            if(A[i]!=B[i]){
                d[A[i]]++;
                c[B[i]]++;
            }
            a[A[i]]++;b[B[i]]++;
        }
        int k=A.size();
        for(int i=1;i<7;i++){
            if(a[i]+c[i]==A.size()){
                k=min(k,c[i]);
            }
            if(b[i]+d[i]==A.size()){
                k=min(k,d[i]);
            }
        }
        if(k==A.size()) k=-1;
        return k;
    }
};