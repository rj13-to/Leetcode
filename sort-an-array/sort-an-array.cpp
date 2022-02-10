class Solution {
public:
    void merge(vector<int>&nums,int st,int ed)
    {
        if(st >= ed) return;
        
        merge(nums,st,(st+ed)/2);
        merge(nums,(st+ed)/2+1,ed);
        
        vector<int> v= {};
        int i=st, j= (st+ed)/2 + 1;
        while(v.size() < ed-st+1)
        {
            if(i == (st+ed)/2 +1)
            {
                v.push_back(nums[j]);
                j++;
            }
            else if(j == ed+1)
            {
                v.push_back(nums[i]);
                i++;
            }
            else if(nums[i] <= nums[j])
            {
                v.push_back(nums[i]);
                i++;
            }
            else
            {
                v.push_back(nums[j]);
                j++;
            }
        }
        for(int i= st; i<= ed;i++)
        {
            nums[i] = v[i-st];
        }
    }
    vector<int> sortArray(vector<int>& nums) 
    {
        merge(nums,0,nums.size()-1);
        return nums;
    }
};