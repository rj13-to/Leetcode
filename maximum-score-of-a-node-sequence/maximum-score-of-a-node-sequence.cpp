class Solution {
public:
    int maximumScore(vector<int>& score, vector<vector<int>>& edges) 
    {
       
        int n = score.size();
        vector<vector<int>>graph(n);

        for(int i = 0;i<edges.size();i++)
        {
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }
        auto compare = [&](int m,int n)-> bool 
        {
            return score[m] > score[n]; 
        };
        for(int i=0;i<n;i++)
        {
            sort(graph[i].begin(),graph[i].end(),compare);
        }
        int ans=-1;
        for(int i=0;i<edges.size();i++)
        {
            int a = edges[i][0];
            int b = edges[i][1];
            
            vector<int>a_side;
            vector<int>b_side;
            for(int j=0;j<graph[a].size()  && a_side.size() < 2;j++)
            {   
                if(graph[a][j] != b ) a_side.push_back(graph[a][j]);
            }
            for(int j=0; j<graph[b].size() && b_side.size() < 2;j++)
            {
                if(graph[b][j] != a ) b_side.push_back(graph[b][j]);
            }
            
            if(a_side.size() == 0 || b_side.size() == 0) continue;
            
            if(a_side[0] == b_side[0]) 
            {
                if(a_side.size() == 1)
                {
                    if(b_side.size() == 1)
                    {
                        continue;
                    }
                    else
                    {
                        ans = max(ans,score[a]+score[b]+score[a_side[0]]+score[b_side[1]]);
                    }
                }
                else if(b_side.size() == 1)
                {
                    if(a_side.size() == 1)
                    {
                        continue;
                    }
                    else
                    {
                        ans = max(ans,score[a]+score[b]+score[a_side[1]]+score[b_side[0]]);
                    }
                }
                else
                {
                    int cur = max(score[a_side[0]]+score[b_side[1]], score[a_side[1]]+score[b_side[0]]);
                    
                    ans = max(ans,score[a]+score[b]+cur);
                }
            }
            else
            {
                ans = max(ans,score[a]+score[b]+score[a_side[0]]+score[b_side[0]]);
            }
        }
        return ans;
    }
};