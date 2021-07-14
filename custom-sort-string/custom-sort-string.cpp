class Solution {
public:
    string customSortString(string order, string str) {
        int arr[26]={0};
        for(int i=0;i<str.size();i++)
        {
            arr[str[i]-'a']++;
        }
        string ans="";
        for(int i=0;i<order.size();i++)
        {
            while(arr[order[i]-'a'])
            {
                arr[order[i]-'a']--;
                ans+=order[i];
            }
        }
        for(int i=0;i<26;i++)
        {
            while(arr[i])
            {
                arr[i]--;
                ans+='a'+i;
            }
        }
        return ans;
    }
};