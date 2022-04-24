class Solution {
public:
    string maximumNumber(string num, vector<int>& change) {
        for(int i =0;i<num.size();i++)
        {
            if(change[num[i]-'0'] > num[i]-'0')
            {
                int j = i;
                while(j<num.size() && change[num[j]-'0'] >= num[j]-'0')
                {
                    num[j] = change[num[j]-'0'] +'0';
                    j++;
                }
                return num;
            }
        }
        return num;
    }
};