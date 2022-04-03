class Solution {
public:
    void nextPermutation(vector<int>& arr) {
        int i=arr.size()-2;
        while(i>=0){
            if(arr[i]<arr[i+1]){
                break;
            }i--;
        }
        if(i==-1){
            reverse(arr.begin(),arr.end());
        }else{
            int k=arr[i+1],in=i+1;
            for(int j=i+1;j<arr.size();j++){
                if(arr[j]>arr[i]){
                    k=min(arr[j],k);
                    in=j;
                }
            }
            swap(arr[i],arr[in]);
            reverse(arr.begin()+i+1,arr.end());
        }
    }
};