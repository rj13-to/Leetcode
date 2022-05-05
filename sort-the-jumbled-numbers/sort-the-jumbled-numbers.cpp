class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) 
    {   
        vector<pair<int,int>>v;
        for(int i=0;i<nums.size();i++)
        {
            string a = to_string(nums[i]);
            
            for(int i=0;i<a.size();i++)
            {
                a[i] += '0' + mapping[a[i]-'0']-a[i];
            }
            
            v.push_back({stoi(a),i});
        }
        sort(v.begin(),v.end());
        vector<int>ans;
        for(int i=0; i< v.size();i++)
        {
            ans.push_back(nums[v[i].second]);
        }
        return ans;
    }
};