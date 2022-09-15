class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        vector<int>ans;
        int slow = changed.size()-1;
        int fast = changed.size()-1;
        
        sort(changed.begin(),changed.end());
        while(slow >= 0)
        {
            fast = min(fast,slow-1);
            if(changed[slow] < 0)
            {
                slow--;
                continue;
            }
            while(fast >= 0 && changed[slow] < 2*changed[fast]) fast--;
            
            if(fast < 0 || changed[slow] != 2* changed[fast]) return {};
            else
            {
                ans.push_back(changed[fast]);
                changed[fast] = -1;
                fast--;
                slow--;
            }
        }
        return ans;
    }
};