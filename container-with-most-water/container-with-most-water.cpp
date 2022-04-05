class Solution {
public:
    int maxArea(vector<int>& arr) {
        int ans=0,st=0,ed=arr.size()-1;
        while(st!=ed){
            ans=max(ans,(ed-st)*min(arr[st],arr[ed]));
            if(arr[st]<arr[ed])st++;
            else ed--;
        }
        return ans;
    }
};