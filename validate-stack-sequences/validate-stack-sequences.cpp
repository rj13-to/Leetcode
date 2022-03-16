class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        if(pushed.size()==0) return true;
        stack<int>st;
        int i=0;int j=0;int n=pushed.size();
        while(i<n || j<n){
            if(st.empty()) {
                st.push(pushed[i]);
                i++;
            }
            else if(popped[j]==st.top()){
                j++;
                st.pop();
            }
            else if(i!=n){
                st.push(pushed[i]);i++;
            }else return 0;
        }return true;
    }
};