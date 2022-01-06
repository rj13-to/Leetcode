class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        unordered_map<int,int>mp;
        int n = arr.size();
        for(int i=0; i<n; i++)
        {
            int nums = ((arr[i]%k)+k)%k;
            mp[nums]++;
        }
        
        for(auto i:mp)
        {
            cout<<i.first<<"->"<<i.second<<endl;
            if( i.first == 0 )
            {
                if(i.second%2==1)
                return false;
            } 
            else if(mp.find(k-i.first)==mp.end())
            {
                return false;
            }
            else
            {
                auto el = k-i.first;
                if(i.second!=mp[el]) return false;
            }
        }
        return true;
    }
};