class Solution {
public:
    set<string>st;
    int minFlips(vector<vector<int>>& mat) 
    {
        int n = mat.size();
        int m = mat[0].size();
        
        string target(mat.size()*mat[0].size(),'0');
       
        queue<string>q;
        string cur = "";
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cur += mat[i][j]+'0';
            }
        }
        q.push(cur);
        int steps = 0;
        string temp;
        while(q.size())
        {
            int k = q.size();
            while(k--)
            {
                cur = q.front();
                
                q.pop();
                if(cur == target) return steps;
                for(int i=0;i<n;i++)
                {
                    for(int j=0;j<m;j++)
                    {
                        temp = cur;
                    
                        temp[i*m+j] = '0'+'1' - temp[i*m+j];
                        
                        if(i!=0) temp[(i-1)*m+j] = '0'+'1' - temp[(i-1)*m+j];
                        
                        if(i!=n-1) temp[(i+1)*m+j] = '0' +'1' - temp[(i+1)*m+j];
                        
                        if(j!=0) temp[i*m+j-1] = '0'+'1' - temp[i*m+j-1];
                        
                        if(j!=m-1) temp[i*m+j+1] = '0' + '1' - temp[i*m+j+1];
                        
                        if(st.count(temp) == 0) 
                        {
                            st.insert(temp);
                            q.push(temp);
                        }
                    }
                }
            }
            steps++;
        }
        return -1;
    }
};