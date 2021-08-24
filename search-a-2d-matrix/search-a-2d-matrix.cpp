class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(target<matrix[0][0]) return false;
        int l=0,r=matrix.size(),mid;
        while(l<r)
        {
            mid=(l+r)/2;
            if(matrix[mid][0]>target) r=mid;
            else l=mid+1;
        }
        int i=l-1;
        return binary_search(matrix[i].begin(),matrix[i].end(),target);
    }
};