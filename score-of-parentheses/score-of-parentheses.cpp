class Solution {
public:
    int scoreOfParentheses(string s) {
        vector<int>v(s.size()/2+1);
        int k=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                k++;
            }else{
                if(v[k]==0){
                    k--;v[k]+=1;
                }else{
                    k--;
                    v[k]+=2*v[k+1];
                    v[k+1]=0;
                }
    
            }
        }
        return v[0];
    }
};