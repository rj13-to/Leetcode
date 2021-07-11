class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int tot=0;
        for(int i=0;i<26;i++)
        {
            char f='a'+i;
            int ft=-1,lt=-1;
            int arr[26]={0};
            for(int i=0;i<s.size();i++)
            {
                if(s[i]==f){
                    ft=i;
                    break;
                }
            }
            if(ft==-1) continue;
            for(int i=s.size()-1;i>=0;i--)
            {
                if(s[i]==f){
                    lt=i;
                    break;
                }
            }
            for(int i=ft+1;i<lt;i++){
                arr[s[i]-'a']++;
                if(arr[s[i]-'a']==1) tot++;
            }
        }
        return tot;
    }
};