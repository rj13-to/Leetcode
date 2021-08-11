class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        map<int,int>mp;
        for(int i=0;i<arr.size();i++)
        {
            mp[arr[i]]++;
        }
        sort(arr.begin(),arr.end());
        for(int i=0;i<arr.size();i++)
        {
            if(mp[arr[i]]==0) continue;
            mp[arr[i]]--;
            if(arr[i]>=0)
            {
                if(mp[arr[i]*2]==0) return 0;
                else mp[arr[i]*2]--;
            }
            else {
                if((arr[i] & 1) || mp[arr[i]/2]==0) return 0; 
                else  mp[arr[i]/2]--;
            }
        }
        return 1;
    }
};