class Solution {
public:
    int maxEqualFreq(vector<int>& nums) 
    {
        map<int,int>elements,frequency;
        
        int ans = 2;
        elements[1] = 1;
        frequency[nums[0]] = 1;
        
        for(int i=1;i<nums.size();i++)
        {
            int cur = ++frequency[nums[i]];
            elements[cur-1]--;
            elements[cur]++;
            
            if(cur -1 == 0 || elements[cur-1] == 0)
            {
                elements.erase(cur-1);
            }
            
            if(elements.size() > 2) continue;
            else if(elements.size() == 1 && (elements.begin()->first == 1 || elements.begin()->second == 1) ) ans = i+1;
            else if(elements.size() == 2)
            {
                if(elements.begin()->first == 1 && elements.begin()->second == 1)
                {
                    ans = i+1;
                }
                else if(elements.rbegin()->first == elements.begin()->first + 1)
                {
                    if(elements.rbegin()->second == 1)
                    {
                        ans = i+1;
                    }
                    
                }
                
            }
        }
        
        return ans;
    }
};

