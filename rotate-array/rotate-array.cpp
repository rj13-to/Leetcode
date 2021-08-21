class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if(nums.empty() or k%nums.size()==0) return;
        k%=nums.size();
        int f,s(__gcd(k,(int)nums.size())),m;
        for(int i=0;i<s;i++){
            f=nums[i];
            m=i+k;
            for(int j=0;j<(nums.size())/s;j++){
                nums[m%(nums.size())]+=f;
                f=nums[m%(nums.size())]-f;
                nums[m%(nums.size())]-=f;
                m+=k;
            }
        }
    }
};