class Solution {
public:
    bool winnerSquareGame(int n) 
    {
        vector<int>v;
        bool arr[(int)(1e5+5)];
        memset(arr,0,sizeof(arr));
        for(int i = 1; i*i<=n;i++)
        {
            v.push_back(i*i);
            arr[i*i] = 1;
        }
        
        
        for(int i=2 ;i<= n;i ++)
        {
            if(arr[i] == 1 ) continue;
            for(int j = 0;j<v.size() && v[j] + i <= n;j++)
            {
                arr[i+v[j]] = 1;
            }
        }
        
        return arr[n];
    }
}; 