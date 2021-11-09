class Solution {
public:
    vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzels) {
        unordered_map<char,vector<int>> map;
        for(int i=0;i<words.size();i++)
        {
            int mask=0;
            for(auto word: words[i])
                mask=(mask|(1<<(word-'a')));
            unordered_set<char> set;
            for(auto word:words[i])
            {
                if(set.find(word)!=set.end())
                    continue;
                set.insert(word);
                map[word].push_back(mask);
            }
        }
        vector<int> res;
        for(int i=0;i<puzzels.size();i++)
        {
            string puzzel=puzzels[i];
            int pmask=0;
            for(auto ch:puzzel)
                pmask=pmask|(1<<(ch-'a'));
            if(map.find(puzzel[0])==map.end())
                res.push_back(0);
            else{
                vector<int> tres=map[puzzel[0]];
                int count=0;
                for(auto it: tres)
                {
                    if((it&pmask)==it)
                        count++;
                   
                }
                 res.push_back(count);
            }
        }
        return res;
        
    }
};