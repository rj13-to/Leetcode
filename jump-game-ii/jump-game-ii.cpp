class Solution {
public:
    int jump(vector<int>& nums) {
        int arr[10005]={0};
        int st=1;
        for(int i=0;i<nums.size();i++){
            while(st<nums.size() && st<=nums[i]+i ){
                arr[st]=1+arr[i];
                st++;
            }
        }
        return arr[nums.size()-1];
    }
};