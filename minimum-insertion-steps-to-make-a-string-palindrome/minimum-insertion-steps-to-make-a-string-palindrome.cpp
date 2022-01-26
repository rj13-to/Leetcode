class Solution {
public:
    int arr[501][501];
    int fun(int i,int j,string& s)
    {
        //cout<<i<<" "<<j<<endl;
        if(i >= j) return 0;
        if(arr[i][j] != -1) return arr[i][j];
        if(s[i] == s[j]) return arr[i][j] = fun(i+1,j-1,s);
        else return arr[i][j] =  min({1+fun(i+1,j,s), 1 + fun(i,j-1,s), 2+fun(i+1,j-1,s)});
    }
    int minInsertions(string s) 
    {
        memset(arr,-1,sizeof(arr));
        return fun(0,s.size()-1,s);
    }
};