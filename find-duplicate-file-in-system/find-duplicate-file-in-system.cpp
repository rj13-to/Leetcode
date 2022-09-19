class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        unordered_map<string,vector<string>>mp;
        string path,file;
        int j,k;
        for(int i=0;i<paths.size();i++)
        {
            j=0;
            while(paths[i][j]!=' ') j++;
            path=paths[i].substr(0,j);
            path+='/';
            while(j<paths[i].size()){
                j++;
                k=j;
                while(paths[i][k]!='('){
                    k++;
                }
                file=paths[i].substr(j,k-j);
                j=k+1;
                while(paths[i][j]!=')') j++;
                mp[paths[i].substr(k+1,j-k-1)].push_back(path+file);
                j++;
            }
        }
        vector<vector<string>>v;
        for(auto it=mp.begin();it!=mp.end();it++)
        {
            if(it->second.size()>1) v.push_back(it->second);
        }return v;
    }
};