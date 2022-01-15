class Solution {
public:
    map<int,vector<int>>mp;
    int minJumps(vector<int>& arr) {
        for(int i = 0;i<arr.size();i++)
        {
            mp[arr[i]].push_back(i);
        }
        vector<int>vis(arr.size(),0);
        queue<int>q;
        int moves = 0;
        q.push(0);
        vis[0] = 1;
        while(true)
        {
            int k =q.size();
            while(k--)
            {
                if(q.front() == arr.size()-1) return moves;
                if(q.front()-1 > 0 && vis[q.front()-1] == 0)
                {
                    vis[q.front()-1] = 1;
                    q.push(q.front()-1);
                }
                if(q.front() + 1 < arr.size() && vis[q.front() + 1] == 0)
                {
                    vis[q.front() + 1] = 1;
                    q.push(q.front()+1);
                }
                for(int i=0;i<mp[arr[q.front()]].size();i++)
                {
                    if(vis[mp[arr[q.front()]][i]] == 0)
                    {
                        vis[mp[arr[q.front()]][i]] = 1;
                        q.push(mp[arr[q.front()]][i]);
                    }
                }
                mp.erase(arr[q.front()]);
                q.pop();
            }
            moves++;
        }
        return moves;
    }
};