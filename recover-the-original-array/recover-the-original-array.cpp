class Solution {
public:
    vector<int> recoverArray(vector<int>& nums) 
    {
        sort(nums.begin(),nums.end());
        vector<int>ans;
        for(int i=1;i<nums.size();i++)
        {
            int k = (nums[i]-nums[0]);
            if((k & 1) || k < 1) continue;
            k = k/2;
            
            vector<int> arr(nums.begin(),nums.end());
            
            int slow = 0,fast = 1;
            
            while(slow < nums.size())
            {
                fast = max(fast,slow+1);
                if(arr[slow] < 0)
                {
                    slow++;
                    continue;
                }
                while(fast < nums.size() && arr[slow] +2*k > arr[fast])
                {
                    fast++;
                }
                if(fast == nums.size() || arr[fast] != arr[slow] + 2*k) 
                {
                    break;
                }
                else
                {
                    arr[fast] = -1;
                    fast++;
                    slow++;
                }
            }
 
            if(slow == nums.size())
            {
                arr = nums;
                int slow_i = 0,fast_i = 1;
                while(slow_i < nums.size())
                {
                    fast_i = max(fast_i,slow_i+1);
                    if(arr[slow_i] < 0)
                    {
                        slow_i++;
                        continue;
                    }
                    while(fast_i < nums.size() && arr[slow_i] +2*k > arr[fast_i])
                    {
                        fast_i++;
                    }
                    ans.push_back(arr[slow_i]+k);
                    arr[fast_i] = -1;
                    fast_i++;
                    slow_i++;
                }
                return ans;
            }
        }
        return {};
    }
};