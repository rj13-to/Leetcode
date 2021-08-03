class Solution {
public:
    bool sumGame(string s) 
    {
        int n=s.size();
        int a=0,b=0,cnt=0;
        for(int i=0;i<n/2;i++) if(s[i]=='?') cnt++; else a+=s[i]-'0';
        for(int i=n/2;i<n;i++) if(s[i]=='?') cnt--; else b+=s[i]-'0';
        //cout<<a<<" "<<b<<" "<<cnt<<endl;
        if(a>=b)
        {
            if(cnt>0) return true;
            else if(cnt==0) return !(a==b);
            else if(cnt & 1) return true;
            cnt/=2;
            return !((a-b)%cnt==0 && abs((a-b)/cnt)==9);
            
        }
        else
        {
            if(cnt<=0 || (cnt & 1)) return true;
            cnt/=2;
            return !((a-b)%cnt==0 && abs((a-b)/cnt)==9);
        }
    }
};