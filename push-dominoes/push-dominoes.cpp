class Solution {
public:
    string pushDominoes(string arr) {
        int l=0,r=arr.size();
        for(int i=0;i<arr.size();i++){
            if(arr[i]=='L'){
                l=i;
                while(r<l){
                    arr[l]='L';
                    arr[r]='R';
                    l--;
                    r++;
                }l=i-1;
                while(r==arr.size() && l>=0 && arr[l]=='.') {
                    arr[l]='L';
                    l--;
                }
                r=arr.size();
            }
            else if(arr[i]=='R'){
                while(r<i ){
                    arr[r]='R';
                    r++;
                }
                r=i;
            }
        }
        while(r<arr.size()){
            arr[r]='R';r++;
        }
        return arr;
    }
};