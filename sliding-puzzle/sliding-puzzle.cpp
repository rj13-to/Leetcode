class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) 
    {
        string s = "";
        for(int i = 0;i<2;i++)
        {
            for(int j = 0;j<3;j++)
            {
                s+= board[i][j]+'0';
            }
        }
        unordered_set<string> st;
        st.insert(s);
        string target = "123450";
        int ans = 0;
        queue<string>q;
        q.push(s);
        while(q.size())
        {
            int k = q.size();
            while(k--)
            {
                string temp = q.front();
                q.pop();
                if(temp == target) return ans;
                
                for(int i = 0;i<2;i++)
                {
                    for(int j=0 ;j<3;j++)
                    {
                        if(temp[i*3+j] != '0')
                        {
                            continue;
                        }
                        if(j-1 >= 0)
                        {

                            swap(temp[i*3+j],temp[i*3+j-1]);
                            //cout<<temp<<endl;
                            if(st.count(temp) == 0)
                            {
                                st.insert(temp);
                                q.push(temp);
                            }
                            swap(temp[i*3+j],temp[i*3+j-1]);
                        }
                        if(j+1 < 3)
                        {
                            swap(temp[i*3+j],temp[i*3+j+1]);
                            //cout<<temp<<endl;
                            if(st.count(temp) == 0)
                            {
                                st.insert(temp);
                                q.push(temp);
                            }
                            swap(temp[i*3+j],temp[i*3+j+1]);
                        }
                        if(i == 1)
                        {
                            swap(temp[i*3+j],temp[j]);
                            //cout<<temp<<endl;
                            if(st.count(temp) == 0)
                            {
                                st.insert(temp);
                                q.push(temp);
                            }
                            swap(temp[i*3+j],temp[j]);
                        }
                        else
                        {
                            swap(temp[i*3+j],temp[3+j]);
                            //cout<<temp<<endl;
                            if(st.count(temp) == 0)
                            {
                                st.insert(temp);
                                q.push(temp);
                            }
                            swap(temp[i*3+j],temp[3+j]);
                        }
                            
                    }
                }
            }
            ans ++;
        }
        return -1;
    }
};