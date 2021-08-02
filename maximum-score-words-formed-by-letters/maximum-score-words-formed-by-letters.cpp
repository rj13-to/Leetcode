class Solution {
public:
    int dfs(vector<string>&words,vector<int>& arr,vector<int>& score,int i)
    {
        if(i == 0) return 0;
        int k=dfs(words,arr,score,i-1);
        vector<int>v(26);
        for(int j=0;j<words[i-1].size();j++)
        {
            v[words[i-1][j]-'a']++;
        }
        for(int j=0;j<26;j++)
        {
              if(v[j]>arr[j]) return k;  
        }
        int tot=0;
        for(int j=0;j<26;j++) 
        {
            arr[j]-=v[j];
            tot+=v[j]*score[j];
        }
        k=max(k,tot+dfs(words,arr,score,i-1));
        for(int j=0;j<26;j++) arr[j]+=v[j];
        return k;
    }
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score)
    {
        vector<int>charac(26);
        for(int i=0;i<letters.size();i++)
        {
            charac[letters[i]-'a']++;
        }
        return dfs(words,charac,score,words.size());
    }
};