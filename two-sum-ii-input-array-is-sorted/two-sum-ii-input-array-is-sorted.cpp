class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int st=0,ed=numbers.size()-1,mid;
        while(st<ed){
            if(numbers[st]+numbers[ed] == target){
                return {st+1,ed+1};
            }
            else if(numbers[st]+numbers[ed] > target){
                ed--;
            }
            else st++;
        }
        return {};
    }
};