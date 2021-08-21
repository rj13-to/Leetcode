class Solution {
public:
    void merge(vector<int>& nums1, int n, vector<int>& nums2, int m) {
        queue<int>q;int st=0,b=0;
        while(st<n+m){
            if(st<n){
                q.push(nums1[st]);
                if(b<m){
                    if(nums2[b]<q.front()){
                        nums1[st]=nums2[b];st++;b++;
                    }
                    else{
                        nums1[st]=q.front();st++;q.pop();
                    }
                }
                else{
                    nums1[st]=q.front();st++;q.pop();
                }
            }
            else {
                if(b<m){
                    if(!q.empty()){
                        if(nums2[b]<q.front()){
                            nums1[st]=nums2[b];st++;b++;
                        }
                        else{
                            nums1[st]=q.front();st++;q.pop();
                        }
                    }
                    else{
                       nums1[st]=nums2[b];st++;b++;
                    }
                }
                else{
                    nums1[st]=q.front();st++;q.pop();
                }
            }
        }
    }
};