class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) 
    {
        int low = 1, high = 1e9;
        int mid;
        while(low < high)
        {
            mid = (low + high) / 2;
            int tot = 0;
            for(int i=0;i<piles.size();i++)
            {
                tot += (piles[i]+mid-1)/mid;
            }
            if(tot > h)
            {
                low = mid+1;
            }
            else
            {
                high = mid;
            }
        }
        return high;
    }
};