class Solution {
public:
    string add(string one,string second)
    {
        int cnt =0,k;
        if(one.size()>second.size()) swap(one,second);
        int i=0;
        while(i<one.size())
        {
            k = (one[i]+second[i]-2*('0')+cnt)/10;
            second[i] = (one[i]+second[i]-2*('0')+cnt)%10 +'0';
            cnt = k;
            i++;
        }
        while(i<second.size())
        {
            k = (second[i]-'0'+cnt)/10;
            second[i] = (second[i]-'0'+cnt)%10+'0';
            cnt = k;
            i++;
        }
        if(cnt) second += "1";
        return second;
    }
    string multiply(string num1, string num2) 
    {
        string ans="";
        string str="";
        int cnt=0,k;
        reverse(num1.begin(),num1.end());
        reverse(num2.begin(),num2.end());
        
        for(int i=0;i<num1.size();i++)
        {
            str="";
            for(int j=0;j<i;j++) str += "0";
            cnt = 0;
            k=0;
            int n = num1[i]-'0';
            for(int j=0;j<num2.size();j++)
            {
                k   =  ((num2[j]-'0')*n+cnt)/10;
                str += ((num2[j]-'0')*n+cnt)%10 +'0';
                cnt = k;
            }
            if(cnt) str+='0'+cnt;
          
            ans = add(ans,str);
            
        }
        int i =ans.size()-1;
        while(i>0 && ans[i] == '0') i--;
        ans = ans.substr(0,i+1);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};