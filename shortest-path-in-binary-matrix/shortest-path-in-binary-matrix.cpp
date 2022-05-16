class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        
        queue<int>queue;
        
        if(grid[0][0] == 0) queue.push(0);
        else return -1;
        grid[0][0] = 1;

        int i,j;
        int k, steps = 1;
        k = queue.size();
        while(queue.size())
        {
            while(k--)
            {
                i = queue.front();
                queue.pop();
                j = i%n;
                i /= n;
                if(i == n-1 && j == n-1) return steps;
                for(int x = -1;x < 2; x++)
                {
                    for(int y= -1; y<2; y++)
                    {
                        if(i+x < 0 || i+x == n || j+y < 0 || j+y == n || grid[i+x][j+y]) continue;
                        //cout<<i+x<<" "<<j+y<<endl;
                        queue.push((i+x)*n + j+y);
                        grid[i+x][j+y] = 1;
                    }
                }
                
            }
            k = queue.size();
            steps++;
        }
        return -1;
    }
};