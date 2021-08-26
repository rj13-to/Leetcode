class Solution {
public:
    int i=-1;
    bool fun(string& s)
    {
        i++;
        //cout<<i<<" ";
        if(i>=s.size()) return false;
        string k="";
        while(i<s.size() && s[i]!=',' )
        {
            k+=s[i];
            i++;
        }
        //cout<<k<<endl;
        if(k == "#") return true;
        return fun(s) && fun(s);
    }
    bool isValidSerialization(string preorder) {
        return fun(preorder) && (i == preorder.size());
    }
};