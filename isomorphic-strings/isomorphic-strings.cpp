class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int arr[128]={0};
        int brr[128]={0};
        int k=1;
        for(int i=0;i<s.size();i++)
        {
              if(arr[s[i]]) s[i]=arr[s[i]];
              else
              {
                  arr[s[i]]=k;
                  s[i]=k;
                  k++;
              }
        }
        k=1;
        for(int i=0;i<t.size();i++)
        {
              if(brr[t[i]]) t[i]=brr[t[i]];
              else
              {
                  brr[t[i]]=k;
                  t[i]=k;
                  k++;
              }
        }
        return s==t;
    }
};