class Solution {
public:
    int maxDistToClosest(vector<int>& seats) 
    {
        if(seats[0]==0) seats[0]=-seats.size();
        for(int i=1;i<seats.size();i++)
        {
            if(seats[i]==0)
            {
                seats[i]=seats[i-1]-1;
            }
        }
        int ans=-seats.back()+1,k;
        if(seats.back()!=1) seats.back()=-seats.size();
        for(int i=seats.size()-2;i>=0;i--)
        {
            if(seats[i]!=1)
            {
                k=seats[i+1]-1;
                seats[i]=max(seats[i],k);
                ans=max(ans,-seats[i]+1);
                seats[i]=k;
            }
        }
        return ans;
    }
};