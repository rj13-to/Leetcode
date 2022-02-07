class Solution {
public:
    char findTheDifference(string s, string t) {
        int arr[26]={0},brr[26]={0};
        for(int i=0;i<s.size();i++)
        {
            arr[s[i]-'a']++;
            brr[t[i]-'a']++;
        }
        brr[t.back()-'a']++;
        for(int i=0;i<26;i++) if(arr[i] != brr[i]) return i+'a';
        return 'a';
    }
};