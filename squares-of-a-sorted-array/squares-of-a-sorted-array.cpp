class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        int st=0,ed=A.size()-1,mid;
        while(st<ed){
            mid=(st+ed)/2;
            if(A[mid]>0) ed=mid-1;
            else if(A[mid]<0) st=mid+1;
            else{ st=mid+1;break;}
        }
        if(A[st]>0)st--;
        ed=st+1;
        vector<int>v;
        while(st!=-1 && ed!=A.size()){
            if(A[st]*A[st]>A[ed]*A[ed]){
                v.push_back(A[ed]*A[ed]);
                ed++;
            }
            else{
                v.push_back(A[st]*A[st]);
                st--;
            }
        }
        while(st!=-1)
        {
            v.push_back(A[st]*A[st]);
            st--;
        }
        while(ed!=A.size())
        {
            v.push_back(A[ed]*A[ed]);
            ed++;
        }
        return v;
    }
};