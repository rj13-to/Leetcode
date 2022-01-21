class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) 
    {
        int st = 0;
        int cur = 0, req = 0;
        int i = 0;
        int tot = 0, tot_req=0;
        while(st < gas.size())
        {
            tot += gas[st];
            tot_req += cost[st];
            
            cur += gas[st];
            req += cost[st];
            if(cur < req)
            {
                cur = req = 0;
                i = st+1;
            }
            st++;
        }
        if(i == st || tot < tot_req) return -1;
        return i;
    }
};