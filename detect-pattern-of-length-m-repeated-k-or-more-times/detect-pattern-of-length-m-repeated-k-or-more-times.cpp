class Solution {
public:
    bool containsPattern(vector<int>& arr, int m, int k) 
    {
        int count = 0;
        for(int i=0, j = i+m;j<arr.size();i++,j++)
        {
            if(arr[i] != arr[j])
            {
                count = 0;
            }
            else
            {
                count++;
                if(count == (k-1)*m) return true;
            }
        }
        return false;
    }
};